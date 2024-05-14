#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

long calculate_directory_size(const char *path) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir;
    long total_size = 0;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir() error");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        sprintf(full_path, "%s/%s", path, entry->d_name);

        if (stat(full_path, &statbuf) == -1) {
            perror("stat() error");
            exit(EXIT_FAILURE);
        }

        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                total_size += calculate_directory_size(full_path);
            }
        } else {
            total_size += statbuf.st_size;
        }
    }

    closedir(dir);

    return total_size;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    long total_size = calculate_directory_size(argv[1]);
    printf("Total disk usage of %s: %ld bytes\n", argv[1], total_size);

    return 0;
}

