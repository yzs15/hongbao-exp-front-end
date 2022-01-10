/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QScrollArea *msgFieldArea;
    QWidget *msgFieldWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QScrollArea *summaryArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QDateEdit *dateIn;
    QTimeEdit *timeIn;
    QSpinBox *msIn;
    QSpinBox *usIn;
    QVBoxLayout *verticalLayout_4;
    QLabel *countDownLabel;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *receiverSlc;
    QPlainTextEdit *msgIn;
    QPushButton *subBtn;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *netStartBtn;
    QPushButton *spbStartBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1440, 900);
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
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 0);
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        horizontalLayout_6->addWidget(nameLabel);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, -1, 0, 0);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_2);

        msgFieldArea = new QScrollArea(centralWidget);
        msgFieldArea->setObjectName(QStringLiteral("msgFieldArea"));
        sizePolicy.setHeightForWidth(msgFieldArea->sizePolicy().hasHeightForWidth());
        msgFieldArea->setSizePolicy(sizePolicy);
        msgFieldArea->setWidgetResizable(true);
        msgFieldWidget = new QWidget();
        msgFieldWidget->setObjectName(QStringLiteral("msgFieldWidget"));
        msgFieldWidget->setEnabled(true);
        msgFieldWidget->setGeometry(QRect(0, 0, 562, 687));
        msgFieldArea->setWidget(msgFieldWidget);

        verticalLayout_7->addWidget(msgFieldArea);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, 0, 0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);

        summaryArea = new QScrollArea(centralWidget);
        summaryArea->setObjectName(QStringLiteral("summaryArea"));
        summaryArea->setFrameShape(QFrame::NoFrame);
        summaryArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 846, 689));
        summaryArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(summaryArea);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalLayout->setStretch(0, 40);
        horizontalLayout->setStretch(1, 60);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        dateIn = new QDateEdit(centralWidget);
        dateIn->setObjectName(QStringLiteral("dateIn"));
        dateIn->setDateTime(QDateTime(QDate(2022, 1, 5), QTime(0, 0, 0)));
        dateIn->setCurrentSection(QDateTimeEdit::YearSection);
        dateIn->setTimeSpec(Qt::UTC);
        dateIn->setDate(QDate(2022, 1, 5));

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
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(usIn->sizePolicy().hasHeightForWidth());
        usIn->setSizePolicy(sizePolicy1);
        usIn->setMaximum(999);
        usIn->setSingleStep(100);

        horizontalLayout_3->addWidget(usIn);

        horizontalLayout_3->setStretch(0, 30);
        horizontalLayout_3->setStretch(1, 30);
        horizontalLayout_3->setStretch(2, 20);
        horizontalLayout_3->setStretch(3, 20);

        horizontalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        countDownLabel = new QLabel(centralWidget);
        countDownLabel->setObjectName(QStringLiteral("countDownLabel"));
        countDownLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(countDownLabel);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalLayout_2->setStretch(0, 60);
        horizontalLayout_2->setStretch(1, 40);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        receiverSlc = new QComboBox(centralWidget);
        receiverSlc->setObjectName(QStringLiteral("receiverSlc"));

        horizontalLayout_5->addWidget(receiverSlc);

        msgIn = new QPlainTextEdit(centralWidget);
        msgIn->setObjectName(QStringLiteral("msgIn"));

        horizontalLayout_5->addWidget(msgIn);

        subBtn = new QPushButton(centralWidget);
        subBtn->setObjectName(QStringLiteral("subBtn"));

        horizontalLayout_5->addWidget(subBtn);

        horizontalLayout_5->setStretch(1, 90);

        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        netStartBtn = new QPushButton(centralWidget);
        netStartBtn->setObjectName(QStringLiteral("netStartBtn"));

        horizontalLayout_4->addWidget(netStartBtn);

        spbStartBtn = new QPushButton(centralWidget);
        spbStartBtn->setObjectName(QStringLiteral("spbStartBtn"));

        horizontalLayout_4->addWidget(spbStartBtn);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout->setStretch(1, 90);
        verticalLayout->setStretch(2, 10);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\272\242\345\214\205\345\272\224\347\224\250", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\266\210\346\201\257\346\241\206", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\347\273\237\350\256\241\344\277\241\346\201\257", Q_NULLPTR));
        dateIn->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd", Q_NULLPTR));
        countDownLabel->setText(QApplication::translate("MainWindow", "\350\257\267\347\202\271\345\207\273\345\274\200\345\247\213", Q_NULLPTR));
        receiverSlc->clear();
        receiverSlc->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\216\213\350\200\201\345\270\210", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\235\216\350\200\201\345\270\210", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\255\231\350\200\201\345\270\210", Q_NULLPTR)
        );
        subBtn->setText(QApplication::translate("MainWindow", "Submit", Q_NULLPTR));
        netStartBtn->setText(QApplication::translate("MainWindow", "\344\272\222\350\201\224\347\275\221\347\211\210 \345\274\200\345\247\213", Q_NULLPTR));
        spbStartBtn->setText(QApplication::translate("MainWindow", "\344\277\241\346\201\257\351\253\230\351\223\201\347\211\210 \345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
