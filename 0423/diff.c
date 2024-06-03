#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void diff(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line1, sizeof(line1), file1) != NULL && fgets(line2, sizeof(line2), file2) != NULL) {
        line_number++;

        if (strcmp(line1, line2) != 0) {
            printf("Difference at line %d:\n", line_number);
            printf("File 1: %s", line1);
            printf("File 2: %s", line2);
        }
    }

    // 파일의 끝까지 도달한 경우
    if (feof(file1) && feof(file2)) {
        printf("No differences found.\n");
    } else {
        printf("Files have different lengths.\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *file1, *file2;

    // 명령행 인수로 비교할 두 파일의 경로를 받지 않은 경우
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

    // 파일 비교
    diff(file1, file2);

    // 파일 닫기
    fclose(file1);
    fclose(file2);

    return 0;
}

