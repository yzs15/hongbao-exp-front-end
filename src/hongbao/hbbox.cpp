#include "hbbox.h"
#include "ui_hbbox.h"

HBBox::HBBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HBBox)
{
    ui->setupUi(this);

}

HBBox::~HBBox()
{
    delete ui;
}
