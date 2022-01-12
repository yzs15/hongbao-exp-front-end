#ifndef COMMUTILS_H
#define COMMUTILS_H

#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <QDebug>
#include "public.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>

time_t get_current_ns_timestamp();

int ns_sleep_until(long end_time, long sleep_threshold_ns);

time_t str2time_t(QString str);

QString time_t2str(time_t t);

uint64_t str2uint64_t(QString s);

char* get_mac();

QString id2string(uint64_t id);

#endif // COMMUTILS_H
