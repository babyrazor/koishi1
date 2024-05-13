#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // 명령어 인자로 삭제할 디렉토리 경로가 주어지지 않은 경우
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // 디렉토리 삭제 시도
    if (rmdir(argv[1]) == -1) {
        perror("rmdir() error");
        return 1;
    }

    printf("Directory %s deleted successfully.\n", argv[1]);
    return 0;
}
