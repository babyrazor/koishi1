#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void print_tree(const char *base_path, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    char path[1024];

    // 디렉토리 열기
    if ((dir = opendir(base_path)) == NULL) {
        perror("opendir() error");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", base_path, entry->d_name);

        // 파일 정보 가져오기
        if (stat(path, &info) == -1) {
            perror("stat() error");
            continue;
        }

        for (int i = 0; i < depth; i++) {
            printf("    ");
        }

        printf("|-- %s\n", entry->d_name);

        // 디렉토리인 경우 재귀적으로 호출
        if (S_ISDIR(info.st_mode)) {
            print_tree(path, depth + 1);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    char *start_path;

    // 시작 경로 설정
    if (argc < 2) {
        start_path = ".";
    } else {
        start_path = argv[1];
    }

    printf("%s\n", start_path);
    print_tree(start_path, 0);

    return 0;
}

