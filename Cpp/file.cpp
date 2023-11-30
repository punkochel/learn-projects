#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

class File {
    int fd;
public:
    File() {
        fd = -1;
    }
    bool OpenWO(const char *name) {
        fd = open(name, O_WRONLY | O_CREAT);
        return (fd != -1);
    }
    ssize_t Write(const char *str) {
        return write(fd, str, strlen(str));
    }
    ~File() {
        if(fd != -1)
            close(fd);
    }
};

int main()
{
    File f;
    bool res;
    res = f.OpenWO("file.txt");
    if(!res) {
        printf("Error: the file wasn't open");
        return 1;
    }
    for(int i = 0; i < 10; i++) {
        f.Write("Hello, world!\n");
    }
    return 0;
}
