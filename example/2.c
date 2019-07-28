#include "common.h"

int main(void){
	int fd=0;
	printf("Open _ReadPermissionDeny With Read!\n");
	fd=open("_ReadPermissionDeny",O_RDONLY);
	if(fd==-1){
		perror("_ReadPermissionDeny");
		goto Next;
	}
	close(fd);
	printf("Open Success!\n");
Next:
	printf("Open _WritePermissionDeny With Write!\n");
	fd=open("_WritePermissionDeny",O_WRONLY);
	if(fd==-1){
		perror("_WritePermissionDeny");
		return 1;
	}
	close(fd);
	printf("Open Success!\n");
	return 0;
}
