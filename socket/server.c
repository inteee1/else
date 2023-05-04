#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <pthread.h>
#include <arpa/inet.h>

int dataSockets[100];
int count;
pthread_mutex_t mutex;
void *clientProc(void *arg);

int main(void)
{
	pthread_mutex_init(&mutex, NULL);
	int servSocket = socket/*3*/(AF_INET, SOCK_STREAM, 0); //open(), int fd=open(....) // file descriptor // close(fd)
	assert(servSocket != -1);
	
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(7000); //host to network short
	
	assert(bind(servSocket, (struct sockaddr *)&servAddr, sizeof(servAddr)) != -1);
	//bind(servSocket, AF_INET, &servAddr, sizeof(servAddr));
	
	assert(listen(servSocket, 5) != -1);
	
	for(;;) {
		struct sockaddr_in clientAddr;
		int len;
		int dataSocket = accept(servSocket, (struct sockaddr *)&clientAddr, &len);
		assert(dataSocket != -1);
		
		printf("client ip : %s\n", inet_ntoa(clientAddr.sin_addr));
		pthread_mutex_lock(&mutex);
		dataSockets[count] = dataSocket;
		++count;
		pthread_mutex_unlock(&mutex);
		//create Thread! call clone!
		pthread_t thread;
		pthread_create(&thread, NULL, &clientProc, &dataSocket);
		pthread_detach(thread);
	}
	
	close(servSocket);
	pthread_mutex_destroy(&mutex);
	return 0;
}

//multi-process vs. multi-thread(0s)







//system call
// open(), close(), read(), write(), ioctl()
/*
int bind(int fd, const struct sockaddr *addr, int size)
{
	int family = *(int*)addr;
	if(family == AF_INET){
		//addr = *((int *)addr + 1);
		//port = *(short*)((int *)addr + 2);	
		struct sockaddr_in sddr_in = (struct sockaddr_in)(*addr);
		= addr_in.sin_addr;
		= addr_in.sin_port;
	}	else if (family == ???) {
	
	}
}
*/
void *clientProc(void *arg)
{
	int dataSocket = *(int *)arg;
	
	char buf[1024];
	int n;
	while ((n = read(dataSocket, buf, 1024)) != 0)
	{
		assert(n != -1);
		pthread_mutex_lock(&mutex);
		for(int i = 0; i < count; ++i) {
		write(dataSockets[i], buf, n);
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_lock(&mutex);
	for (int i = 0; i <count; ++i) {
		if(dataSockets[i] == dataSocket) {
			for(int j = i; j <count-1; ++j) {
				dataSockets[j] = dataSockets[j+1];
			}
			--count;
			break;
		}
	}
	pthread_mutex_unlock(&mutex);
	close(dataSocket);
	return NULL;
}
