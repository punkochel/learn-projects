#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int fd, pid, status;
    if(argc < 2) {
        fprintf(stderr, "Error: You must specify a file name\n");
        return 1;
    }
    fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if(fd == -1) {
        perror(argv[1]);
        return 2;
    }
    pid = fork();
    if(pid == -1) {
        close(fd);
        return 3;
    }
    if(pid == 0) { /* child process */
        dup2(fd, 1);
        close(fd);
        execlp("ls", "ls", "-a", "-l", "-R", "/home/", NULL);
        perror("ls");
        exit(1);
    }
    close(fd);
    wait(&status);
    if(!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
        fprintf(stderr, "Error: Child process did not exit normally\n");
        return 4;
    }
    return 0;
}