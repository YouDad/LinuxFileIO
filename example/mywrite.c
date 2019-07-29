#include "common.h"
#include <time.h>

struct mymsg{
	time_t time;
	char msg[32];
};

int main(void){
	int pd[2];
	int pid;
	pipe(pd);
	pid=fork();
	if(pid<0){
		perror("fork");
		return 1;
	}
	if(pid!=0){
		char str[32];
		scanf("%s",str);
		write(pd[1],str,sizeof str);
		sleep(0);
	}else{
		struct mymsg msg;
		struct tm *local;
		int fd;
		read(pd[0],msg.msg,sizeof msg.msg);
		time(&msg.time);
		fd=open("my",O_WRONLY|O_TRUNC|O_CREAT,0644);
		if(fd<0){
			perror("open");
			return 1;
		}
		write(fd,&msg,sizeof msg);
		close(fd);
		close(pd[0]);
		close(pd[1]);
	}
	return 0;
}
