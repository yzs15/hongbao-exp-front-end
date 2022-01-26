/*

Copyright (c) 2022 Yifan Wang <me@wangyifan.tech>

*/

#ifndef _ALL_CLOCK_H
#define _ALL_CLOCK_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/ptp_clock.h>

#ifndef CLOCK_INVALID
#define CLOCK_INVALID -1
#endif

#define CLOCKFD 3
#define FD_TO_CLOCKID(fd)   ((clockid_t) ((((unsigned int) ~fd) << 3) | CLOCKFD))
#define CLOCKID_TO_FD(clk)  ((unsigned int) ~((clk) >> 3))

typedef uint64_t time_ns;

time_ns utils_get_current_sys_ns_timestamp();

clockid_t utils_get_clockid(const char *dev_ptp);

time_ns utils_get_current_ptp_ns_timestamp(clockid_t clkid);

#endif
