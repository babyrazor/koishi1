#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {  // 명령어 인자로 복사할 파일과 대상 파일이 주어지지 않은 경우
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // 소스 파일 열기
    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("open() source file error");
        return 1;
    }

    // 대상 파일 생성 또는 열기
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("open() destination file error");
        close(source_fd);
        return 1;
    }

    // 소스 파일에서 읽어 대상 파일로 쓰기
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write() error");
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }

    // 파일 닫기
    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
    return 0;
}
