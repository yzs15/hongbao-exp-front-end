#include "hbopened.h"
#include "ui_hbopened.h"
#include <QGraphicsDropShadowEffect>

HBOpened::HBOpened(QWidget *parent, QString name, QString money, QString content) :
    QWidget(parent),
    ui(new Ui::HBOpened)
{
    ui->setupUi(this);


    QPixmap bgImage;
    if (curEnv == INTERNET) {
        bgImage = QPixmap("../pic/opened-net.png").scaled(this->size());
    } else {
        bgImage = QPixmap("../pic/opened-spb.png").scaled(this->size());
    }

    this->setAutoFillBackground(true);
    QPalette palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(bgImage));
    this->setPalette(palette);

    ui->nameLab->setText(name);
    ui->nameLab->setStyleSheet("color:#F1E352;");
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
    effect->setColor(QColor(100,100,100,100));
    effect->setBlurRadius(2);   //模糊半径
    effect->setOffset(3);      //偏移量
    ui->nameLab->setGraphicsEffect(effect);


    ui->moneyLab->setText(QString("￥ %1").arg(money));
    ui->moneyLab->setStyleSheet("color:#CF4F3C;");
    effect = new QGraphicsDropShadowEffect;
    effect->setColor(QColor(100,100,100,100));
    effect->setBlurRadius(2);   //模糊半径
    effect->setOffset(2);      //偏移量
    ui->moneyLab->setGraphicsEffect(effect);

    ui->conLab->setText(content);
    ui->conLab->setStyleSheet("color:#F1E352;");
    effect = new QGraphicsDropShadowEffect;
    effect->setColor(QColor(100,100,100,100));
    effect->setBlurRadius(2);   //模糊半径
    effect->setOffset(3);      //偏移量
    ui->conLab->setGraphicsEffect(effect);

    ui->closeLab->setStyleSheet("color:#F39A00;");
    effect = new QGraphicsDropShadowEffect;
    effect->setColor(QColor(100,100,100,100));
    effect->setBlurRadius(2);   //模糊半径
    effect->setOffset(1);      //偏移量
    ui->closeLab->setGraphicsEffect(effect);
}

HBOpened::~HBOpened()
{
    delete ui;
}

void HBOpened::mousePressEvent(QMouseEvent* event) {
    this->close();
}
