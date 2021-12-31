#include "userform.h"

UserForm::UserForm(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label = new QLabel("姓名");
    this->input = new QLineEdit();
    this->input->setText("Wang");

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(label);
    inputLayout->addWidget(input);


    QPushButton *confirmBtn = new QPushButton("确认");
    connect(confirmBtn, &QPushButton::released, this, &UserForm::onBtnClicked);

    QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addSpacerItem(spacer);
    btnLayout->addWidget(confirmBtn);
    btnLayout->addSpacerItem(spacer);


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(btnLayout);

    this->setLayout(mainLayout);
}

UserForm::~UserForm() {

}

void UserForm::onBtnClicked() {
    QString author = this->input->text();
    emit userConfirmed(author);
    this->close();
}
