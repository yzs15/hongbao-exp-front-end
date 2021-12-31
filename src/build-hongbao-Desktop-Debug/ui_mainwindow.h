/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QScrollArea *msgFieldArea;
    QWidget *msgFieldWidget;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *msgDetailArea;
    QWidget *scrollAreaWidgetContents;
    QCheckBox *thingHidden;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *msgIn;
    QHBoxLayout *horizontalLayout_3;
    QDateEdit *dateIn;
    QTimeEdit *timeIn;
    QSpinBox *msIn;
    QSpinBox *usIn;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *reqContentIn;
    QLineEdit *reqSenderIn;
    QPushButton *msgSubmitBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        msgFieldArea = new QScrollArea(centralWidget);
        msgFieldArea->setObjectName(QStringLiteral("msgFieldArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(msgFieldArea->sizePolicy().hasHeightForWidth());
        msgFieldArea->setSizePolicy(sizePolicy1);
        msgFieldArea->setWidgetResizable(true);
        msgFieldWidget = new QWidget();
        msgFieldWidget->setObjectName(QStringLiteral("msgFieldWidget"));
        msgFieldWidget->setGeometry(QRect(0, 0, 597, 517));
        msgFieldArea->setWidget(msgFieldWidget);

        horizontalLayout->addWidget(msgFieldArea);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, 0, 0);
        msgDetailArea = new QScrollArea(centralWidget);
        msgDetailArea->setObjectName(QStringLiteral("msgDetailArea"));
        msgDetailArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 395, 487));
        msgDetailArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(msgDetailArea);

        thingHidden = new QCheckBox(centralWidget);
        thingHidden->setObjectName(QStringLiteral("thingHidden"));

        verticalLayout_5->addWidget(thingHidden);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalLayout->setStretch(0, 60);
        horizontalLayout->setStretch(1, 40);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        msgIn = new QTextEdit(centralWidget);
        msgIn->setObjectName(QStringLiteral("msgIn"));

        verticalLayout_3->addWidget(msgIn);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        dateIn = new QDateEdit(centralWidget);
        dateIn->setObjectName(QStringLiteral("dateIn"));
        dateIn->setDateTime(QDateTime(QDate(2021, 12, 13), QTime(0, 0, 0)));
        dateIn->setCurrentSection(QDateTimeEdit::YearSection);
        dateIn->setTimeSpec(Qt::UTC);

        horizontalLayout_3->addWidget(dateIn);

        timeIn = new QTimeEdit(centralWidget);
        timeIn->setObjectName(QStringLiteral("timeIn"));
        timeIn->setDisplayFormat(QStringLiteral("HH:mm:ss"));
        timeIn->setTimeSpec(Qt::UTC);

        horizontalLayout_3->addWidget(timeIn);

        msIn = new QSpinBox(centralWidget);
        msIn->setObjectName(QStringLiteral("msIn"));
        msIn->setMaximum(999);
        msIn->setSingleStep(1);

        horizontalLayout_3->addWidget(msIn);

        usIn = new QSpinBox(centralWidget);
        usIn->setObjectName(QStringLiteral("usIn"));
        usIn->setMaximum(999);
        usIn->setSingleStep(100);

        horizontalLayout_3->addWidget(usIn);

        horizontalLayout_3->setStretch(0, 30);
        horizontalLayout_3->setStretch(1, 30);
        horizontalLayout_3->setStretch(2, 20);
        horizontalLayout_3->setStretch(3, 20);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 10);

        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        reqContentIn = new QTextEdit(centralWidget);
        reqContentIn->setObjectName(QStringLiteral("reqContentIn"));

        verticalLayout_4->addWidget(reqContentIn);

        reqSenderIn = new QLineEdit(centralWidget);
        reqSenderIn->setObjectName(QStringLiteral("reqSenderIn"));

        verticalLayout_4->addWidget(reqSenderIn);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalLayout_2->setStretch(0, 60);
        horizontalLayout_2->setStretch(1, 40);

        verticalLayout_2->addLayout(horizontalLayout_2);

        msgSubmitBtn = new QPushButton(centralWidget);
        msgSubmitBtn->setObjectName(QStringLiteral("msgSubmitBtn"));

        verticalLayout_2->addWidget(msgSubmitBtn);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout->setStretch(0, 70);
        verticalLayout->setStretch(1, 30);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\272\242\345\214\205\345\272\224\347\224\250", Q_NULLPTR));
        thingHidden->setText(QApplication::translate("MainWindow", "\344\270\215\347\234\213\347\211\251\347\253\257\346\266\210\346\201\257", Q_NULLPTR));
        msgIn->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\246\201\345\217\221\351\200\201\347\232\204\346\266\210\346\201\257", Q_NULLPTR));
        dateIn->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd", Q_NULLPTR));
        reqContentIn->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\345\256\232\347\232\204\346\266\210\346\201\257", Q_NULLPTR));
        reqSenderIn->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\345\256\232\347\232\204\345\217\221\351\200\201\350\200\205", Q_NULLPTR));
        msgSubmitBtn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
