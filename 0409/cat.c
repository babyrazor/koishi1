#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 명령어 인자로 파일 경로가 주어지지 않은 경우
    if (argc < 2) {
        printf("Usage: %s <file1> [<file2> ...]\n", argv[0]);
        return 1;
    }

    // 각 파일의 내용을 화면에 출력
    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r"); // 파일을 읽기 모드로 열기
        if (file == NULL) {
            perror("fopen() error");
            return 1;
        }

        // 파일의 내용을 한 줄씩 읽어 화면에 출력
        int c;
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }

        fclose(file); // 파일 닫기
    }

    return 0;
}

