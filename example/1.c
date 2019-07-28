#include "common.h"

int main(void){
	int fd=open("exist",O_RDONLY,0);
	printf("1.c start\n\n");
	if(fd==-1){
		perror("open");
		return 1;
	}
	close(fd);
	printf("1.c end\n\n");
	return 0;
}
