#include <stdio.h>
#include <pthread.h>
#include "redis_publisher.h"

int main(int argc, char** argv)
{
	if(argc != 3){
		printf("<prog> <channel> <str>\n");
		return -1;
	}

	int ret = 0;
	printf("channel[%s]: string:%s\n", argv[1], argv[2]);
	ret = publish(argv[1], argv[2]);
	if(ret != 0){
		printf("Failed to publish.\n");
	}

	return 0;
}
