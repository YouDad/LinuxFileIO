#include "common.h"
#include <string.h>

int main(void){
	int fd,ret,pid,pd[2];
	int *ReadPipe =&pd[0];
	int *WritePipe=&pd[1];
	char msg[32];
	struct flock locker={
		.l_type=F_WRLCK,
		.l_whence=SEEK_SET,
		.l_start=0,
		.l_len=0
	};
	pipe(pd);
	pid=fork();
	if(pid<0){
		perror("fork");
		return 1;
	}
	if(pid==0){

		read(*ReadPipe,msg,sizeof msg);
		printf("3=children:%s\n",msg);

		fd=open("_Fcntl",O_WRONLY);
		perror("4 children open");

		fcntl(fd,F_SETLK,&locker);
		perror("5 children fcntl");

		ret=write(fd,msg,strlen(msg));
		printf("6=children write %d byte(s)\n",ret);

		write(*WritePipe,"children over",sizeof msg);
	}else{

		fd=open("_Fcntl",O_WRONLY);
		perror("1 parent open");

		fcntl(fd,F_SETLK,&locker);
		perror("2 parent fcntl");

		write(*WritePipe,"parent mover",sizeof msg);

		sleep(0);

		read(*ReadPipe,msg,sizeof msg);
		printf("7=parent:%s\n",msg);
	}
	close(fd);
	close(*ReadPipe);
	close(*WritePipe);
	return 0;
}
