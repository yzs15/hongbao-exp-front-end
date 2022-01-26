#include "msghandler.h"

MsgHandler::MsgHandler(MsgObj* msg, time_t received_time)
{
    this->msg = msg;
    this->received_time = received_time;
}

void MsgHandler::run() {
    MsgObj callback;
    callback.id = this->msg->id;
    callback.sender = SENDER;
    callback.receiver = SID(SENDER);
    callback.type = LOG_MSG;
    callback.content = "";
    callback.sendTime = this->received_time;
    zmqSend(ZMQ_SERVER[curEnv], &callback);

    emit this->processed(this->msg);
}
