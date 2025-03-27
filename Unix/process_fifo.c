//
// Created by olu on 10/25/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (mkfifo("./fifo1", 0666) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            return 1;
        }
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        int fd = open("./fifo1", O_RDONLY);
        if (fd == -1) {
            perror("open");
            return 1;
        }
        int buf;
        if (read(fd, &buf, sizeof(buf)) == -1) {
            perror("read");
            return 1;
        }

        printf("Read data from fifo in child: %d\n", buf);
        close(fd);
        return 0;
    }

    int fd = open("./fifo1", O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int xx = 100;
    if (write(fd, &xx, sizeof(xx)) == -1) {
        perror("write");
        return 1;
    }
    close(fd);
    wait(NULL);


    return 0;
}
