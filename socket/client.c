#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

void *sendProc(void *arg)
{
	int dataSocket = *(int *)arg;
	for(;;) {
		char buf[1024];
		fgets(buf, 1024, stdin);
		if (strcmp(buf, "q\n") == 0 || strcmp(buf, "Q\n") == 0) {
			break;
			}
			write(dataSocket, buf, strlen(buf));
		}
	close(dataSocket);
	
	return NULL;
}



void *recvProc(void *arg)
{
	int dataSocket = *(int *)arg;
	
	char buf[1024];
	int n;
	while (n = read(dataSocket, buf, 1024)) {
		buf[n] = '\0';
		printf("%s", buf);
	}
	return NULL;
}

int main(void)
{
	int dataSocket = socket(AF_INET, SOCK_STREAM, 0);
	assert(dataSocket != -1);
	
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(7000);
	
	assert(connect(dataSocket, (struct sockaddr *)&servAddr, sizeof (struct sockaddr_in)) != -1);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, sendProc, &dataSocket); 
	pthread_create(&thread2, NULL, recvProc, &dataSocket);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	
	
	return 0;
}
