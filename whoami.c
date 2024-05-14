#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main() {
    uid_t uid;
    struct passwd *pw;

    // 현재 사용자 ID 가져오기
    uid = getuid();

    // 사용자 ID로 사용자 정보 가져오기
    pw = getpwuid(uid);
    if (pw == NULL) {
        perror("getpwuid() error");
        return 1;
    }

    // 사용자 이름 출력
    printf("%s\n", pw->pw_name);

    return 0;
}
