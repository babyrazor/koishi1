#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <signal>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    int sig = atoi(argv[2]);

    // 프로세스에 시그널 보내기
    if (kill(pid, sig) == -1) {
        perror("kill");
        return 1;
    }

    printf("Sent signal %d to process %d\n", sig, pid);
    return 0;
}
