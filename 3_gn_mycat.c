#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



void display(int i, char *p);

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("no file to cat!\n");
	}
	else{
		int count = 1;
		while(count < (argc)){
			display(count, argv[count]);
			count++;
		}
	}

	return 0;
}

void display(int i, char *p){
	int fd = open(p, O_RDWR);
	if(fd == -1){
		perror("open file!");
		exit(1);
	}

	int c;
	char buffer[128] = {0};
	read(fd, buffer, sizeof(buffer));
	printf("read: \n%s", buffer);
}




