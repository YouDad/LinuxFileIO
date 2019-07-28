#include "common.h"
#include <memory.h>

int main(void){
	int fd,ret;
	char str[16];

	fd=open("_TenChar",O_RDONLY);
	if(fd==-1){
		perror("open");
		return 1;
	}

	memset(str,0,sizeof str);
	ret=read(fd,str,16);
	if(ret==-1){
		perror("read1");
		return 1;
	}

	printf("read %d char\nContent is %s\n",ret,str);

	memset(str,0,sizeof str);
	ret=read(fd,str,16);
	if(ret==-1){
		perror("read2");
		return 1;
	}

	printf("read %d char\nContent is %s\n",ret,str);

	close(fd);
	return 0;
}
