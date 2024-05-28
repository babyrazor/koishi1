#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> // mkdir 함수를 사용하기 위한 헤더 파일

int main(int argc, char *argv[]) {
    if (argc != 2) {  // 명령어 인자로 디렉토리 이름이 주어지지 않은 경우
        printf("Usage: %s <directory_name>\n", argv[0]);
        return 1;
    }

    // mkdir 함수를 사용하여 새로운 디렉토리 생성
    if (mkdir(argv[1], 0777) == -1) {
        perror("mkdir() error");
        return 1;
    }

    printf("Directory '%s' created successfully.\n", argv[1]);
    return 0;
}
