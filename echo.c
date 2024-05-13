#include <stdio.h>

int main(int argc, char *argv[]) {
    // 명령어 인자로 출력할 문자열이 주어지지 않은 경우
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // 명령어 인자로 받은 문자열을 화면에 출력
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}
