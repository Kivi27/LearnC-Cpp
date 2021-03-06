#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

int main(void) {
    time_t since_epoch;
    struct tm* loc_time;
    since_epoch = time(NULL);
    loc_time = localtime(&since_epoch);
    printf("Curent year = %d\n",loc_time->tm_year + 1900);
    printf("Current month = %d\n",loc_time->tm_mon + 1);
    printf("Current day = %d\n",loc_time->tm_mday);
    printf("Current hour = %d\n",loc_time->tm_hour);
    printf("Current minunte = %d\n",loc_time->tm_min);
    printf("Current sec = %d\n",loc_time->tm_sec);
    printf("Since Epoch = %ld\n",since_epoch);
    char *data;
    data = ctime(&since_epoch);
    fputs(data,stdout);
    struct timeval tv;
    gettimeofday(&tv,NULL);
    printf("microsec = %ld\n",tv.tv_usec);
    sleep(1); /* sleep second. Function, not system call */
    usleep(100000); /* sleep microsecond. Function, not system call */
    struct timespec req;
    req.tv_sec = 10;
    nanosleep(&req,NULL); /* system call */
    return 0;
}
