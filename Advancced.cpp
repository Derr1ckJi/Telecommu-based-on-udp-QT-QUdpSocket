#include "Advancced.h"
#include "ui_Advancced.h"

Advancced::Advancced(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Advancced)
{
    ui->setupUi(this);
}

Advancced::~Advancced()
{
    delete ui;
}
