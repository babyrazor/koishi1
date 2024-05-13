#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // 명령어 인자로 파일 이름이 주어지지 않은 경우
    if (argc < 2) {
        printf("Usage: %s <file1> [<file2> ...]\n", argv[0]);
        return 1;
    }

    // 각 파일을 생성하고 최근 수정 시간을 현재 시간으로 설정
    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_CREAT | O_WRONLY, 0644); // 파일 생성
        if (fd == -1) {
            perror("open() error");
            return 1;
        }

        // 파일의 최근 수정 시간을 현재 시간으로 설정
        struct utimbuf utime_buf;
        utime_buf.actime = utime_buf.modtime = time(NULL);
        if (utime(argv[i], &utime_buf) == -1) {
            perror("utime() error");
            return 1;
        }

        close(fd); // 파일 닫기
    }

    return 0;
}
