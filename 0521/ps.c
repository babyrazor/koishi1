#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[256];
    FILE *fp;
    char line[256];

    // /proc 디렉터리 열기
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir() error");
        exit(EXIT_FAILURE);
    }

    // /proc 디렉터리 내의 각 엔트리에 대해 프로세스 정보 출력
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && atoi(entry->d_name) != 0) {
            sprintf(path, "/proc/%s/cmdline", entry->d_name);

            fp = fopen(path, "r");
            if (fp != NULL) {
                fgets(line, sizeof(line), fp);
                fclose(fp);
                printf("PID: %s, Command: %s\n", entry->d_name, line);
            }
        }
    }

    closedir(dir);

    return 0;
}
