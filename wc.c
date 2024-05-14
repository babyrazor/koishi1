#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(FILE *file, int *lines, int *words, int *chars) {
    char c;
    int in_word = 0;

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') {
            (*lines)++;
        }
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            (*words)++;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    int lines = 0, words = 0, chars = 0;

    // 명령행 인수로 파일명을 전달하지 않은 경우
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 파일 열기
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen() error");
        exit(EXIT_FAILURE);
    }

    // 파일 내용 카운트
    count(file, &lines, &words, &chars);

    // 결과 출력
    printf("%d %d %d %s\n", lines, words, chars, argv[1]);

    // 파일 닫기
    fclose(file);

    return 0;
}

