#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

class File {
    int fd;
public:
    File() { fd = -1; }
    bool OpenRO(const char *name) {
        fd = open(name, O_RDONLY);
        if(fd == -1) {
            throw "The file wasn't open";
        }
        return (fd != -1);
    }
    ~File() {
        if(fd != -1)
            close(fd);
    }
};

int main()
{
    File f;
    try {
        f.OpenRO("my_file.txt");
    }
    catch(const char *str) {
        fprintf(stderr, "[catch] %s\n", str);
    }
    return 0;
}
