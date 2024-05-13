#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *de;  // 포인터 구조체 선언
    DIR *dr = opendir(".");  // 현재 디렉토리 열기

    if (dr == NULL) {  // 디렉토리 열기 실패 시 오류 메시지 출력
        printf("Could not open current directory\n");
        return 1;
    }

    while ((de = readdir(dr)) != NULL) {  // 디렉토리 내용을 읽으면서 출력
        printf("%s\n", de->d_name);
    }

    closedir(dr);  // 디렉토리 닫기
    return 0;
}
