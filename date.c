#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *local;
    char buffer[80];

    // 현재 시간 가져오기
    time(&now);

    // 현재 시간 구조체로 변환
    local = localtime(&now);

    // 날짜와 시간을 포맷팅하여 문자열로 변환
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local);

    // 결과 출력
    printf("Current date and time: %s\n", buffer);

    return 0;
}
