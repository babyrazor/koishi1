#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[]) {
    struct statvfs buf;

    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if (statvfs(argv[1], &buf) == -1) {
        perror("statvfs() error");
        return 1;
    }

    printf("Filesystem size: %lu bytes\n", buf.f_frsize * buf.f_blocks);
    printf("Available space: %lu bytes\n", buf.f_frsize * buf.f_bavail);
    printf("Used space: %lu bytes\n", buf.f_frsize * (buf.f_blocks - buf.f_bfree));

    return 0;
}

