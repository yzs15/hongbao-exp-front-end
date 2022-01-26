#include "msgfield.h"
#include <QDebug>

MsgField::MsgField():
    QWidget()
{   
    this->msgFieldLayout = new QVBoxLayout();
    this->setLayout(msgFieldLayout);
}


void MsgField::addMsg(MsgObj* obj) {
    MsgBox *msgBox = new MsgBox(this, obj);
    connect(msgBox, &MsgBox::clicked, this, &MsgField::onMsgBoxClicked);

    this->msgBoxs.append(msgBox);
    this->msgFieldLayout->addWidget(msgBox);
}

void MsgField::setThingHidden(bool hidden) {
    for (QList<MsgBox*>::iterator it = this->msgBoxs.begin(); it != this->msgBoxs.end(); it ++) {
        MsgBox* msgBox = *it;
        if (msgBox->getAuthor().contains(QRegExp("^Thing"))) {
            msgBox->setHidden(hidden);
        }
    }
    this->update();
}

void MsgField::clear() {
    for (int i = 0; i < this->msgBoxs.size(); i++) {
        this->msgFieldLayout->removeWidget(this->msgBoxs.at(i));
        delete this->msgBoxs.at(i);
    }

    this->msgBoxs.clear();
}

void MsgField::onMsgBoxClicked(MsgBox* obj) {
    emit msgSelected(obj);
}
