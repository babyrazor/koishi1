#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

void cut_fields(FILE *input, int field_num) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), input)) {
        char *token;
        int field_count = 0;

        // 문자열을 구분자로 분리하고 필요한 필드를 출력합니다.
        token = strtok(line, " \t\n");
        while (token != NULL) {
            field_count++;
            if (field_count == field_num) {
                printf("%s ", token);
                break;
            }
            token = strtok(NULL, " \t\n");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <field_number> <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int field_num = atoi(argv[1]); // 필드 번호를 정수로 변환합니다.
    if (field_num <= 0) {
        fprintf(stderr, "Invalid field number\n");
        exit(EXIT_FAILURE);
    }

    FILE *input = fopen(argv[2], "r"); // 입력 파일을 엽니다.
    if (input == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    cut_fields(input, field_num); // 지정된 필드를 추출하여 출력합니다.

    fclose(input); // 파일을 닫습니다.
    return 0;
}

