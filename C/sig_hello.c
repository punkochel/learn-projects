#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t child_ready;

void handle_signal_usr1(int n)
{
    child_ready = 1;
}

int main()
{
    int pid;
    sigset_t mask_usr1, mask_empty;
    sigemptyset(&mask_usr1);
    sigaddset(&mask_usr1, SIGUSR1);
    sigemptyset(&mask_empty);
    child_ready = 0;
    sigprocmask(SIG_SETMASK, &mask_usr1, NULL);
    signal(SIGUSR1, &handle_signal_usr1);
    pid = fork();
    if(pid == 0) {
        kill(getppid(), SIGUSR1);
        exit(0);
    }
    while(!child_ready)
        sigsuspend(&mask_empty);
    printf("Hello world!\n");
    return 0;
}