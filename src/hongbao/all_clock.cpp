#include "all_clock.h"

time_ns utils_get_current_sys_ns_timestamp()
{
    struct timespec current_time;
    clock_gettime(CLOCK_REALTIME, &current_time);
    time_ns timestamp = current_time.tv_sec*1000000000+current_time.tv_nsec;
    return timestamp;
}

clockid_t utils_get_clockid(const char *dev_ptp)
{
    int fd;
    clockid_t clkid;
    fd = open(dev_ptp, O_RDWR);
    if (fd < 0)
    {
        printf("ptp open error.\n");
        return CLOCK_INVALID;
    }
    clkid = FD_TO_CLOCKID(fd);
    if ((clkid & CLOCKFD) != 3)
    {
        printf("ptp clock id error.\n");
        return CLOCK_INVALID;
    }
    return clkid;
}

time_ns utils_get_current_ptp_ns_timestamp(clockid_t clkid)
{
    struct timespec current_time;
    clock_gettime(clkid, &current_time);
    time_ns timestamp = current_time.tv_sec*1000000000+current_time.tv_nsec;
    return timestamp;
}
