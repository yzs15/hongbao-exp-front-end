#ifndef MSGBOX_H
#define MSGBOX_H

#include <QObject>
#include <QWidget>
#include "public.h"
#include "message.h"
#include "hbbox.h"
#include "commutils.h"
#include <map>

namespace Ui {
class MsgBox;
}

class MsgBox : public QWidget
{
    Q_OBJECT

public:
    explicit MsgBox(QWidget *parent = 0, MsgObj* obj = 0);
    ~MsgBox();

    MsgObj *obj;

    QString getAuthor() const;
    QString getContent() const;

    bool isHongbao = false;

signals:
    void clicked(MsgBox* box);

private:
    Ui::MsgBox *ui;

    void handleHB();

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // MSGBOX_H
