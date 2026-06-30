#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];
    char msg[] = "Hello, I am Pruthviraj M. Nice to Meet You!\n";
    fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    write(fd, msg, strlen(msg));
    lseek(fd, 0, SEEK_SET);

    int n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';

    printf("%s", buffer);

    close(fd);

    return 0;
}
