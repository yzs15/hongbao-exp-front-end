/********************************************************************************
** Form generated from reading UI file 'proofform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROOFFORM_H
#define UI_PROOFFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProofForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;

    void setupUi(QWidget *ProofForm)
    {
        if (ProofForm->objectName().isEmpty())
            ProofForm->setObjectName(QStringLiteral("ProofForm"));
        ProofForm->resize(640, 480);
        verticalLayout = new QVBoxLayout(ProofForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ProofForm);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(ProofForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        checkBox = new QCheckBox(ProofForm);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        horizontalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(ProofForm);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        horizontalLayout->addWidget(checkBox_2);

        pushButton = new QPushButton(ProofForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ProofForm);

        QMetaObject::connectSlotsByName(ProofForm);
    } // setupUi

    void retranslateUi(QWidget *ProofForm)
    {
        ProofForm->setWindowTitle(QApplication::translate("ProofForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ProofForm", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("ProofForm", "\350\275\254\345\217\221\347\273\231", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ProofForm", "\346\235\216\350\200\201\345\270\210", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("ProofForm", "\345\255\231\350\200\201\345\270\210", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ProofForm", "\347\241\256\350\256\244\350\275\254\345\217\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProofForm: public Ui_ProofForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROOFFORM_H
