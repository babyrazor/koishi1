#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file1, *file2;
    char line1[1024], line2[1024];

    // 명령줄 인수로 두 파일이 제공되지 않은 경우
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 첫 번째 파일 열기
    file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        perror("fopen() error");
        exit(EXIT_FAILURE);
    }

    // 두 번째 파일 열기
    file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        perror("fopen() error");
        exit(EXIT_FAILURE);
    }

    // 파일 내용 읽어오기 및 병합하여 출력
    while (fgets(line1, sizeof(line1), file1) && fgets(line2, sizeof(line2), file2)) {
        // 각 파일에서 읽은 줄 출력
        printf("%s\t%s", line1, line2); // 탭으로 분리하여 출력
    }

    // 파일 닫기
    fclose(file1);
    fclose(file2);

    return 0;
}

