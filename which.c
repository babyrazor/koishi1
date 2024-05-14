#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // access 함수와 X_OK 상수를 사용하기 위해 포함합니다.

#define PATH_MAX_LEN 1024

void find_executable(const char *cmd) {
    char *path = getenv("PATH");
    char *dir, *p, buffer[PATH_MAX_LEN];

    if (path == NULL) {
        fprintf(stderr, "PATH environment variable not set\n");
        exit(EXIT_FAILURE);
    }

    p = strdup(path);
    dir = strtok(p, ":");

    while (dir != NULL) {
        snprintf(buffer, sizeof(buffer), "%s/%s", dir, cmd);
        if (access(buffer, X_OK) == 0) {
            printf("%s\n", buffer);
            free(p);
            return;
        }
        dir = strtok(NULL, ":");
    }

    printf("%s: command not found\n", cmd);
    free(p);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    find_executable(argv[1]);

    return 0;
}

