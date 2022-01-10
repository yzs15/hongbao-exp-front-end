#ifndef MSGBOX_H
#define MSGBOX_H

#include <QObject>
#include <QWidget>
#include "public.h"
#include "message.h"

namespace Ui {
class MsgBox;
}

class MsgBox : public QWidget
{
    Q_OBJECT

public:
    explicit MsgBox(QWidget *parent = 0, MsgObj* obj = 0);
    ~MsgBox();

    QString getAuthor() const;

signals:
    void clicked(MsgDetailObj* obj);

private:
    Ui::MsgBox *ui;

    MsgObj *obj;

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // MSGBOX_H
