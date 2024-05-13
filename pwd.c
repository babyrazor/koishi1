#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[1024];  // 현재 작업 디렉토리를 저장할 배열
    if (getcwd(cwd, sizeof(cwd)) != NULL) {  // 현재 작업 디렉토리를 가져오고 성공한 경우
        printf("Current working directory: %s\n", cwd);  // 현재 작업 디렉토리 출력
    } else {  // 실패한 경우
        perror("getcwd() error");
        return 1;
    }
    return 0;
}

