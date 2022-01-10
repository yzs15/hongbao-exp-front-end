#ifndef MESSAGE_H
#define MESSAGE_H

#define REGISTER_MSG 0
#define NAME_MSG     1
#define QUERY_MSG    2
#define RESULT_MSG   3
#define TEXT_MSG     4
#define TASK_MSG     5
#define LOG_MSG      6

#include <QString>
#include "public.h"
#include "commutils.h"

class MsgObj
{
public:
    MsgObj();

    uint64_t id = 0;
    uint64_t sender = SENDER;
    uint64_t receiver = 0;
    uint8_t type = TEXT_MSG;
    QString content = "";
    uint64_t sendTime = 0;

    int toBytes(char **raw);
    QString toString();
};

MsgObj* char2msg(const char *raw, int len);
void updateSendTime(char *raw, int len);

#endif // MESSAGE_H
