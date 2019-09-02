#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    char filename[50], file[500];
    scanf ("%s", &filename);
    int fd = open(filename, O_RDONLY, 0);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    int len = lseek(fd, 0, SEEK_END);
    int i = lseek(fd, 0, SEEK_SET);
    read(fd, file, len);
    printf("%s\n", file);
    close(fd);
    return 0;
}
