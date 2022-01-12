#ifndef PROOFFORM_H
#define PROOFFORM_H

#include <QWidget>

namespace Ui {
class ProofForm;
}

class ProofForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProofForm(QWidget *parent = 0);
    ~ProofForm();

private:
    Ui::ProofForm *ui;
};

#endif // PROOFFORM_H
