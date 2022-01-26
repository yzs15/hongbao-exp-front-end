#ifndef HBBOX_H
#define HBBOX_H

#include <QWidget>

namespace Ui {
class HBBox;
}

class HBBox : public QWidget
{
    Q_OBJECT

public:
    explicit HBBox(QWidget *parent = 0);
    ~HBBox();

private:
    Ui::HBBox *ui;
};

#endif // HBBOX_H
