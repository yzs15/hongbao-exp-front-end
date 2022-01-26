/********************************************************************************
** Form generated from reading UI file 'hbbox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HBBOX_H
#define UI_HBBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HBBox
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *HBBox)
    {
        if (HBBox->objectName().isEmpty())
            HBBox->setObjectName(QStringLiteral("HBBox"));
        HBBox->resize(300, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HBBox->sizePolicy().hasHeightForWidth());
        HBBox->setSizePolicy(sizePolicy);
        HBBox->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(HBBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(HBBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(HBBox);

        QMetaObject::connectSlotsByName(HBBox);
    } // setupUi

    void retranslateUi(QWidget *HBBox)
    {
        HBBox->setWindowTitle(QApplication::translate("HBBox", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("HBBox", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HBBox: public Ui_HBBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HBBOX_H
