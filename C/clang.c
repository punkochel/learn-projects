#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char cut_name[64];
    int i;
    if(argc != 2) {
        fprintf(stderr, "Error: wrong input");
        return 1;
    }
    for(i = 0; argv[1][i] != '.'; i++) {
        cut_name[i] = argv[1][i];
    }
    cut_name[i] = '\0';
    execlp("clang", "clang", "-Wall", "-g", argv[1], "-o", cut_name, NULL);
    perror("clang");
    fflush(stderr);
    _exit(1);
}
