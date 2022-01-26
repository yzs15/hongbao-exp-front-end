#ifndef HBOPENED_H
#define HBOPENED_H

#include <QWidget>
#include "public.h"

namespace Ui {
class HBOpened;
}

class HBOpened : public QWidget
{
    Q_OBJECT

public:
    explicit HBOpened(QWidget *parent = 0, QString name = "", QString money = "", QString content = "");
    ~HBOpened();

private:
    Ui::HBOpened *ui;

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // HBOPENED_H
