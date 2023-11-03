#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    __pid_t p, pid;
    p = fork();
    pid = getpid();
    if(p == -1)
        return 1;
    if(p == 0) {
        printf("[%d] I'm the children\n", pid);
        exit(0);
    } else {
        printf("[%d] I'm the parent\n", pid);
    }
    return 0;
}