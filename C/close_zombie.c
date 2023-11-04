#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    __pid_t p;
    p = fork();
    if(p == -1)
        return 1;
    if(p == 0) {
        printf("[Child] Hello, world!\n");
        exit(55);
    } else {
        __pid_t wr;
        int status;
        wr = wait(&status);
        if(wr != -1) {
            printf("[Parent] Process with pid=%d finished\n", wr);
            if(WIFEXITED(status)) {
                printf("[Parent] It has exited with code=%d\n",
                    WEXITSTATUS(status));
            } else {
                printf("[Parent] It was killed by signal %d\n",
                    WTERMSIG(status));
            }
        }
    }
    return 0;
}
