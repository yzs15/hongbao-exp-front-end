/********************************************************************************
** Form generated from reading UI file 'msgbox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGBOX_H
#define UI_MSGBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgBox
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *authorLabel;
    QLabel *msgLabel;

    void setupUi(QWidget *MsgBox)
    {
        if (MsgBox->objectName().isEmpty())
            MsgBox->setObjectName(QStringLiteral("MsgBox"));
        MsgBox->resize(466, 32);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MsgBox->sizePolicy().hasHeightForWidth());
        MsgBox->setSizePolicy(sizePolicy);
        MsgBox->setMinimumSize(QSize(100, 32));
        horizontalLayout_2 = new QHBoxLayout(MsgBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        authorLabel = new QLabel(MsgBox);
        authorLabel->setObjectName(QStringLiteral("authorLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(authorLabel->sizePolicy().hasHeightForWidth());
        authorLabel->setSizePolicy(sizePolicy1);
        authorLabel->setMinimumSize(QSize(60, 32));
        authorLabel->setWordWrap(true);
        authorLabel->setIndent(0);

        horizontalLayout_2->addWidget(authorLabel);

        msgLabel = new QLabel(MsgBox);
        msgLabel->setObjectName(QStringLiteral("msgLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(msgLabel->sizePolicy().hasHeightForWidth());
        msgLabel->setSizePolicy(sizePolicy2);
        msgLabel->setMinimumSize(QSize(0, 32));
        msgLabel->setWordWrap(true);
        msgLabel->setIndent(0);

        horizontalLayout_2->addWidget(msgLabel);


        retranslateUi(MsgBox);

        QMetaObject::connectSlotsByName(MsgBox);
    } // setupUi

    void retranslateUi(QWidget *MsgBox)
    {
        MsgBox->setWindowTitle(QApplication::translate("MsgBox", "Form", Q_NULLPTR));
        authorLabel->setText(QApplication::translate("MsgBox", "TextLabel", Q_NULLPTR));
        msgLabel->setText(QApplication::translate("MsgBox", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MsgBox: public Ui_MsgBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGBOX_H
