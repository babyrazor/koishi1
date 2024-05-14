#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 인자가 3개가 아닌 경우 사용법을 출력
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // 파일 이동 또는 이름 변경 시도
    if (rename(argv[1], argv[2]) == -1) {
        perror("rename() error");
        return 1;
    }

    printf("File or directory moved successfully.\n");
    return 0;
}
