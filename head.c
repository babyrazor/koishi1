#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINES 10  // 디폴트로 출력할 줄 수

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[1024];
    int lines_to_print = DEFAULT_LINES;
    int lines_printed = 0;

    // 명령어 인자로 파일 이름이 주어지지 않은 경우
    if (argc < 2) {
        printf("Usage: %s <file> [number_of_lines]\n", argv[0]);
        return 1;
    }

    // 파일을 열기
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen() error");
        return 1;
    }

    // 출력할 줄 수 설정
    if (argc >= 3) {
        lines_to_print = atoi(argv[2]);
    }

    // 파일 내용 출력
    while (fgets(buffer, sizeof(buffer), file) != NULL && lines_printed < lines_to_print) {
        printf("%s", buffer);
        lines_printed++;
    }

    fclose(file);
    return 0;
}
