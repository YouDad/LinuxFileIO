#include "common.h"

int main(void){
	char ch;
	while(EOF!=(ch=getchar()))
		putchar(ch);
	return 0;
}
