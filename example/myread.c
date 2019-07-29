#include "common.h"
#include <time.h>

struct mymsg{
	time_t time;
	char msg[32];
};

int main(void){
	int fd=open("my",O_RDONLY);
	struct mymsg msg;
	struct tm *local;
	read(fd,&msg,sizeof msg);
	local=localtime(&msg.time);
	printf("TIME:%sMESG:%s\n",asctime(local),msg.msg);
	return 0;
}
