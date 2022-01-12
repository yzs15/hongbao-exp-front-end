#include "proofform.h"
#include "ui_proofform.h"

ProofForm::ProofForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProofForm)
{
    ui->setupUi(this);
}

ProofForm::~ProofForm()
{
    delete ui;
}
