#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>

int main(int argc, char *argv[]) {
    char name[50], text[1000];
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("open faild");
        return 1;
    }

    memset(text, 0, sizeof text);
    read(fd, &text, sizeof text);
    printf("%s", text);
    close(fd);
    return 0;
}

//gcc mycat.c -o mycat
//./mycat mycat.c