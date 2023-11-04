#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

enum {
    max_buffer_size = 32
};

int main()
{
    int fd[2];
    pipe(fd);
    if(fork() == 0) {
        close(fd[0]);
        dup2(fd[1], 1); /* stdout */
        close(fd[1]);
        printf("Hello world!\n");
        exit(0);
    }
    if(fork() == 0) {
        char s[max_buffer_size];
        int rc;
        close(fd[1]);
        rc = read(fd[0], s, max_buffer_size);
        if(rc != -1)
            printf("[Result] %s", s);
        close(fd[0]);
        exit(0);
    }
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
