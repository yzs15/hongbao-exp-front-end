#include "message.h"

MsgObj::MsgObj()
{

}

int MsgObj::toBytes(char **rawP) {
    int contentLen = this->content.toStdString().size();
    int len = 25 + contentLen + 8;

    char* raw = new char[len];

    int offset = 0;
    memcpy(raw+offset, &this->id, 8);
    offset += 8;

    memcpy(raw+offset, &this->sender, 8);
    offset += 8;

    memcpy(raw+offset, &this->receiver, 8);
    offset += 8;

    memcpy(raw+offset, &this->type, 1);
    offset += 1;

    memcpy(raw+offset, this->content.toStdString().c_str(), contentLen);
    offset += contentLen;

    memcpy(raw+offset, &this->sendTime, 8);

    *rawP = raw;
    return len;
}

QString MsgObj::toString() {
    return QString("MsgObj{%1, %2, %3, %4, %5}").arg(id2string(this->id))
            .arg(id2string(this->sender)).arg(id2string(this->receiver))
            .arg(this->type).arg(time_t2str(this->sendTime));
}

void updateSendTime(char *raw, int len) {
    time_t now = get_current_ns_timestamp();
    memcpy(raw+len-8, &now, 8);
}

MsgObj* char2msg(const char *raw, int len) {
    MsgObj *obj = new MsgObj();

    int contentLen = len - 25 - 8;

    int offset = 0;
    memcpy(&obj->id, raw+offset, 8);
    offset += 8;

    memcpy(&obj->sender, raw+offset, 8);
    offset += 8;

    memcpy(&obj->receiver, raw+offset, 8);
    offset += 8;

    memcpy(&obj->type, raw+offset, 1);
    offset += 1;

    obj->content = QByteArray::fromRawData(raw+offset, contentLen);
    offset += contentLen;

    memcpy(&obj->sendTime, raw+offset, 8);

    return obj;
}
