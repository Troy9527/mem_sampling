#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE	1024*1024

char	*buffer;
int	seg_len;

void* access_buffer(void* segment){
	int	i;
	char	*seg = (char*)segment;

	srand(time(NULL));
	for(i = 0; i < seg_len; i++)
		*(seg + i) = rand() % 255;

	pthread_exit(NULL);
}

int main(int argc, char** argv){
	int		num_thread, i;
	pthread_t	*id_thread;
	num_thread = atoi(argv[1]);
	seg_len = SIZE / num_thread;
	buffer = (char*)malloc(sizeof(char)*SIZE);
	id_thread = (pthread_t*)malloc(sizeof(pthread_t)*num_thread);

	sleep(2);
	printf("Create %d threads\n", num_thread);

	for(i = 0; i < num_thread; i++)
		pthread_create((id_thread + i), NULL, access_buffer, (buffer + (i * seg_len)));
	
	for(i = 0; i < num_thread; i++)
		pthread_join(id_thread[i], NULL);

	free(buffer);
	free(id_thread);
}
