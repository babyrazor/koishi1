#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

// 비교 함수
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *lines[MAX_LINES];
    char buffer[MAX_LENGTH];
    int num_lines = 0;

    // 명령어 인자로 파일 이름이 주어지지 않은 경우
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // 파일을 열기
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen() error");
        return 1;
    }

    // 파일 내용 읽기
    while (fgets(buffer, sizeof(buffer), file) != NULL && num_lines < MAX_LINES) {
        // 개행 문자 제거 후 동적 할당하여 배열에 저장
        buffer[strcspn(buffer, "\n")] = '\0';
        lines[num_lines] = strdup(buffer);
        num_lines++;
    }

    fclose(file);

    // 정렬
    qsort(lines, num_lines, sizeof(char *), compare);

    // 정렬된 결과 출력
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);  // 동적 할당 해제
    }

    return 0;
}

