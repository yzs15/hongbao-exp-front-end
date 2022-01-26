/********************************************************************************
** Form generated from reading UI file 'hbopened.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HBOPENED_H
#define UI_HBOPENED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HBOpened
{
public:
    QLabel *nameLab;
    QLabel *conLab;
    QLabel *moneyLab;
    QLabel *closeLab;

    void setupUi(QWidget *HBOpened)
    {
        if (HBOpened->objectName().isEmpty())
            HBOpened->setObjectName(QStringLiteral("HBOpened"));
        HBOpened->resize(300, 400);
        nameLab = new QLabel(HBOpened);
        nameLab->setObjectName(QStringLiteral("nameLab"));
        nameLab->setGeometry(QRect(20, 90, 241, 61));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameLab->sizePolicy().hasHeightForWidth());
        nameLab->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        nameLab->setFont(font);
        nameLab->setAlignment(Qt::AlignCenter);
        conLab = new QLabel(HBOpened);
        conLab->setObjectName(QStringLiteral("conLab"));
        conLab->setGeometry(QRect(30, 310, 231, 81));
        conLab->setFont(font);
        conLab->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        conLab->setWordWrap(true);
        moneyLab = new QLabel(HBOpened);
        moneyLab->setObjectName(QStringLiteral("moneyLab"));
        moneyLab->setGeometry(QRect(10, 210, 281, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        moneyLab->setFont(font1);
        moneyLab->setTextFormat(Qt::AutoText);
        moneyLab->setScaledContents(false);
        moneyLab->setAlignment(Qt::AlignCenter);
        closeLab = new QLabel(HBOpened);
        closeLab->setObjectName(QStringLiteral("closeLab"));
        closeLab->setGeometry(QRect(260, 0, 41, 41));
        QFont font2;
        font2.setPointSize(36);
        font2.setBold(true);
        font2.setWeight(75);
        closeLab->setFont(font2);

        retranslateUi(HBOpened);

        QMetaObject::connectSlotsByName(HBOpened);
    } // setupUi

    void retranslateUi(QWidget *HBOpened)
    {
        HBOpened->setWindowTitle(QApplication::translate("HBOpened", "Form", Q_NULLPTR));
        nameLab->setText(QApplication::translate("HBOpened", "TextLabel", Q_NULLPTR));
        conLab->setText(QApplication::translate("HBOpened", "TextLabel", Q_NULLPTR));
        moneyLab->setText(QApplication::translate("HBOpened", "TextLabel", Q_NULLPTR));
        closeLab->setText(QApplication::translate("HBOpened", "X", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HBOpened: public Ui_HBOpened {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HBOPENED_H
