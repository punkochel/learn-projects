#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void print_time(struct tm *st, const char *t_name)
{
    printf("%s: %02d:%02d:%02d %02d.%02d.%d\n",
        t_name,
        st->tm_hour, st->tm_min, st->tm_sec,
        st->tm_mday, st->tm_mon, st->tm_year+1900);
}

int main()
{
    time_t t;
    struct tm *stime;
    struct timeval stval_1, stval_2;
    gettimeofday(&stval_1, NULL);
    t = time(NULL);
    stime = gmtime(&t);
    print_time(stime, "GMT");
    stime = localtime(&t);
    print_time(stime, "L_TIME");
    /* usleep(500000); */
    gettimeofday(&stval_2, NULL);
    printf("Execution time was: %ld sec %ld usec\n",
        stval_2.tv_sec - stval_1.tv_sec,
        stval_2.tv_usec - stval_1.tv_usec);
    return 0;
}
