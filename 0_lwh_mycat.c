#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
//用宏来清楚的表明缓冲区的大小是1MB
#define FILEMAXCHAR 1<<20
char buffer[FILEMAXCHAR];

//接受命令行参数
int main(int argc,char** argv){
	//ret为程序返回值
	int i,fd,ret=0;

	//0是自己，从1开始遍历所有参数
	for(i=1;i<argc;i++){
		//cnt is count，计数值，代表读了多少个字节到缓冲区
		int cnt;

		//试图以读方式打开文件
		fd=open(argv[i],O_RDONLY);

		//处理错误
		if(fd<0){
			perror(argv[i]);

			//有错即返回1
			ret=1;

			//继续处理下一个参数
			continue;
		}

		//读取文件
		cnt=read(fd,buffer,sizeof buffer);

		//超过1MB的文本文件将不予输出
		if(cnt==sizeof buffer){
			//输出提示信息
			printf("File size is too big, cannot output.");

			//设置返回值，关闭文件
			ret=1;
			close(fd);
			continue;
		}

		//输出内容
		buffer[cnt]='\0';
		printf("%s",buffer);
		close(fd);
	}
	return ret;
}
