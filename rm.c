#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // 명령어 인자로 파일 또는 디렉토리 경로가 주어지지 않은 경우
    if (argc < 2) {
        printf("Usage: %s <file_or_directory>\n", argv[0]);
        return 1;
    }

    // 명령어 인자로 받은 파일 또는 디렉토리를 삭제
    for (int i = 1; i < argc; i++) {
        if (unlink(argv[i]) == -1) { // 파일 삭제 시도
            perror("unlink() error");
            return 1;
        }
    }

    printf("File(s) or directory(ies) removed successfully.\n");
    return 0;
}
