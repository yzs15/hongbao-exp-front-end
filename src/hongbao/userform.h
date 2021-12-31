#ifndef USERFORM_H
#define USERFORM_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>

class UserForm : public QWidget
{
    Q_OBJECT

signals:
    void userConfirmed(const QString& author);

public:
    UserForm(QWidget *parent = 0);
    ~UserForm();

private:
    QLineEdit *input;

private slots:
    void onBtnClicked();
};

#endif // USERFORM_H
