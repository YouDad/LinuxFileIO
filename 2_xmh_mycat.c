#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <memory.h>

int main(int argc,char *argv[]){
	int ret,fd;
	char str[500];
	fd=open(argv[1],O_RDONLY);
	
	if(fd==-1){
		perror("I2C");
		return 1;
	}

	memset(str,0,sizeof str);
	ret=read(fd,str,500);

	if(ret==-1){
		perror("I2C1");
		return 1;
	}

	printf("%s",str);
	close(fd);
	return 0;
}
