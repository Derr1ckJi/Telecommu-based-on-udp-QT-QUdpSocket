#ifndef ADVANCCED_H
#define ADVANCCED_H

#include <QWidget>

namespace Ui {
class Advancced;
}

class Advancced : public QWidget
{
    Q_OBJECT

public:
    explicit Advancced(QWidget *parent = nullptr);
    ~Advancced();

private:
    Ui::Advancced *ui;
};

#endif // ADVANCCED_H
