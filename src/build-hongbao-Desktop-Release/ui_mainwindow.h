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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
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
    QLabel *proofLabel;
    QHBoxLayout *redirectLayout;
    QLabel *redLabel;
    QCheckBox *redLi;
    QCheckBox *redSun;
    QPushButton *redBtn;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *hbWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *countDownLabel;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *teachWang;
    QCheckBox *teachLi;
    QCheckBox *teachSun;
    QPlainTextEdit *msgIn;
    QPushButton *subBtn;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *netStartBtn;
    QPushButton *spbStartBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 758);
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
        msgFieldWidget->setGeometry(QRect(0, 0, 395, 526));
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

        proofLabel = new QLabel(centralWidget);
        proofLabel->setObjectName(QStringLiteral("proofLabel"));
        sizePolicy.setHeightForWidth(proofLabel->sizePolicy().hasHeightForWidth());
        proofLabel->setSizePolicy(sizePolicy);
        proofLabel->setMinimumSize(QSize(500, 500));
        proofLabel->setScaledContents(false);
        proofLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(proofLabel);

        redirectLayout = new QHBoxLayout();
        redirectLayout->setSpacing(6);
        redirectLayout->setObjectName(QStringLiteral("redirectLayout"));
        redLabel = new QLabel(centralWidget);
        redLabel->setObjectName(QStringLiteral("redLabel"));

        redirectLayout->addWidget(redLabel);

        redLi = new QCheckBox(centralWidget);
        redLi->setObjectName(QStringLiteral("redLi"));
        redLi->setChecked(true);

        redirectLayout->addWidget(redLi);

        redSun = new QCheckBox(centralWidget);
        redSun->setObjectName(QStringLiteral("redSun"));
        redSun->setChecked(true);

        redirectLayout->addWidget(redSun);

        redBtn = new QPushButton(centralWidget);
        redBtn->setObjectName(QStringLiteral("redBtn"));

        redirectLayout->addWidget(redBtn);


        verticalLayout_5->addLayout(redirectLayout);


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
        hbWidget = new QWidget(centralWidget);
        hbWidget->setObjectName(QStringLiteral("hbWidget"));
        hbWidget->setMinimumSize(QSize(50, 0));
        horizontalLayout_3 = new QHBoxLayout(hbWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(hbWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);


        horizontalLayout_2->addWidget(hbWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        countDownLabel = new QLabel(centralWidget);
        countDownLabel->setObjectName(QStringLiteral("countDownLabel"));
        countDownLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(countDownLabel);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalLayout_2->setStretch(1, 40);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        teachWang = new QCheckBox(centralWidget);
        teachWang->setObjectName(QStringLiteral("teachWang"));

        verticalLayout_3->addWidget(teachWang);

        teachLi = new QCheckBox(centralWidget);
        teachLi->setObjectName(QStringLiteral("teachLi"));

        verticalLayout_3->addWidget(teachLi);

        teachSun = new QCheckBox(centralWidget);
        teachSun->setObjectName(QStringLiteral("teachSun"));

        verticalLayout_3->addWidget(teachSun);


        horizontalLayout_5->addLayout(verticalLayout_3);

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
        label->setText(QApplication::translate("MainWindow", "\345\207\255\350\257\201\345\261\225\347\244\272\346\241\206", Q_NULLPTR));
        proofLabel->setText(QApplication::translate("MainWindow", "\346\232\202\346\227\240\345\207\255\350\257\201", Q_NULLPTR));
        redLabel->setText(QApplication::translate("MainWindow", "\350\275\254\345\217\221\347\273\231", Q_NULLPTR));
        redLi->setText(QApplication::translate("MainWindow", "\346\235\216\350\200\201\345\270\210", Q_NULLPTR));
        redSun->setText(QApplication::translate("MainWindow", "\345\255\231\350\200\201\345\270\210", Q_NULLPTR));
        redBtn->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244\350\275\254\345\217\221", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\351\200\211\344\270\255\350\246\201\345\217\221\351\200\201\347\232\204\347\272\242\345\214\205", Q_NULLPTR));
        countDownLabel->setText(QApplication::translate("MainWindow", "\350\257\267\347\202\271\345\207\273\345\274\200\345\247\213", Q_NULLPTR));
        teachWang->setText(QApplication::translate("MainWindow", "\347\216\213\350\200\201\345\270\210", Q_NULLPTR));
        teachLi->setText(QApplication::translate("MainWindow", "\346\235\216\350\200\201\345\270\210", Q_NULLPTR));
        teachSun->setText(QApplication::translate("MainWindow", "\345\255\231\350\200\201\345\270\210", Q_NULLPTR));
        subBtn->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
        netStartBtn->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\345\271\266\347\224\237\346\210\220\345\207\255\350\257\201 (\344\272\222\350\201\224\347\275\221\347\211\210)", Q_NULLPTR));
        spbStartBtn->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\345\271\266\347\224\237\346\210\220\345\207\255\350\257\201 (\344\277\241\346\201\257\351\253\230\351\223\201\347\211\210)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
