#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char filename[] = "test.txt";
    int fd;
    char buffer[1024];
    ssize_t bytesRead;

    // 打开文件
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 读取文件内容
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }

    // 关闭文件
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}