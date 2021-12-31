#include "commutils.h"

time_t get_current_ns_timestamp(){
    struct timespec current_time;
    clock_gettime(CLOCK_REALTIME, &current_time);
    time_t timestamp = current_time.tv_sec * 1000000000 + current_time.tv_nsec;
    return timestamp;
}

int ns_sleep_until(long end_time, long sleep_threshold_ns) {
    time_t cur_time = get_current_ns_timestamp();

    if (end_time - cur_time > sleep_threshold_ns) {
        long ns_gap = end_time - cur_time - sleep_threshold_ns;
        struct timespec req;
        req.tv_sec = ns_gap / 1000000000;
        req.tv_nsec = ns_gap % 1000000000;

        int res;
        do {
            res = nanosleep(&req, &req);
        } while (res && errno == EINTR);
    }

    do {
        cur_time = get_current_ns_timestamp();
    } while (cur_time < end_time);

    return 0;
}

time_t str2time_t(QString str) {
    time_t res = 0;
    for (int i = 0; i < str.size(); i++) {
        res = res * 10 + str[i].toLatin1() - '0';
    }
    return res;
}

QString time_t2str(time_t t) {
    if (t <= 0) return "-1";

    time_t ymdhms = t / 1000000000;

    int ns = t % 1000;
    int us = (t / 1000) % 1000;
    int ms = (t / 1000000) % 1000;

    struct tm *stm = localtime(&ymdhms);

    char tmp[35];
    sprintf(tmp, "%04d-%02d-%02d %02d:%02d:%02d .%03d .%03d .%03d",
            1900 + stm->tm_year, 1 + stm->tm_mon, stm->tm_mday,
            stm->tm_hour, stm->tm_min, stm->tm_sec,
            ms, us, ns);

    return QString(tmp);
}


uint64_t str2uint64_t(QString s) {
    uint64_t res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = res * 10 + s[i].toLatin1() - '0';
    }
    return res;
}
