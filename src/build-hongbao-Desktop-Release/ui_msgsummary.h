/********************************************************************************
** Form generated from reading UI file 'msgsummary.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGSUMMARY_H
#define UI_MSGSUMMARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgSummary
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *MsgSummary)
    {
        if (MsgSummary->objectName().isEmpty())
            MsgSummary->setObjectName(QStringLiteral("MsgSummary"));
        MsgSummary->resize(760, 652);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MsgSummary->sizePolicy().hasHeightForWidth());
        MsgSummary->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(MsgSummary);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(MsgSummary);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 13)
            tableWidget->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem14);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(MsgSummary);

        QMetaObject::connectSlotsByName(MsgSummary);
    } // setupUi

    void retranslateUi(QWidget *MsgSummary)
    {
        MsgSummary->setWindowTitle(QApplication::translate("MsgSummary", "Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MsgSummary", "Internet", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MsgSummary", "Info Superbahn", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MsgSummary", "\346\227\266\346\256\265 T(\347\247\222)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MsgSummary", "\344\273\273\345\212\241\346\225\260 N(\344\270\252)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MsgSummary", "\345\220\236\345\220\220\347\216\207 \316\273(\345\271\263\345\235\207\346\257\217\347\247\222\345\256\214\346\210\220\344\273\273\345\212\241\346\225\260\357\274\214\344\273\273\345\212\241/\347\247\222)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MsgSummary", "\345\271\266\345\217\221\345\272\246 L(\345\271\263\345\235\207\346\257\217\344\270\252\346\227\266\345\210\273\346\264\273\350\267\203\344\273\273\345\212\241\346\225\260\357\274\214\344\270\252)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MsgSummary", "\345\273\266\350\277\237 W(\345\271\263\345\235\207\346\257\217\344\270\252\344\273\273\345\212\241\345\273\266\350\277\237\357\274\214\347\247\222)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MsgSummary", "\344\277\235\350\264\250\344\273\273\345\212\241\346\225\260NG(\344\270\252)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MsgSummary", "\344\273\273\345\212\241\347\272\247\350\211\257\347\216\207 Y(NG /N)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("MsgSummary", "\351\200\232\351\207\217 G(\346\257\217\347\247\222\345\256\214\346\210\220\347\232\204\344\277\235\350\264\250\344\273\273\345\212\241\346\225\260\357\274\214\344\273\273\345\212\241/\347\247\222)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("MsgSummary", "\346\200\273\350\277\220\347\256\227\346\225\260 O(N \344\270\252\344\273\273\345\212\241\347\232\204\346\200\273\350\256\241\350\277\220\347\256\227\346\225\260\357\274\214Gop, giga operations)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("MsgSummary", "\344\277\235\350\264\250\350\277\220\347\256\227\346\225\260 OG(NG\344\270\252\344\273\273\345\212\241\347\232\204\350\277\220\347\256\227\346\225\260\357\274\214Gop, giga operations)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem12->setText(QApplication::translate("MsgSummary", "\350\277\220\347\256\227\347\272\247\350\211\257\347\216\207 YG(OG /O)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem13->setText(QApplication::translate("MsgSummary", "\350\243\270\351\200\237\345\272\246 S(\346\257\217\347\247\222\345\256\214\346\210\220\347\232\204\350\277\220\347\256\227\346\225\260\357\274\214Gops, giga operations per sec)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem14->setText(QApplication::translate("MsgSummary", "\351\200\237\345\272\246 SG(\346\257\217\347\247\222\345\256\214\346\210\220\347\232\204\344\277\235\350\264\250\350\277\220\347\256\227\346\225\260\357\274\214Gops, giga operations per sec)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MsgSummary: public Ui_MsgSummary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGSUMMARY_H
