#include "Terminus.h"
#include "ui_Terminus.h"

#include <QMessageBox>

Terminus::Terminus(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Terminus)
{
    ui->setupUi(this);
    this->setWindowTitle("Terminus");

    this->port = 1111;

    socket = new QUdpSocket(this);

    socket->bind(this->port);

    connect(ui->sendBtn,&QPushButton::clicked,[=](){
        if(ui->Input->toPlainText()==""){
            QMessageBox::warning(this,"warning","发送内容不能为空");
            return ;
        }
        QString str = ui->Input->toPlainText();
        sendEdict(str);
    });

    connect(socket,&QUdpSocket::readyRead,this,&Terminus::receiveEdict);

}

int Terminus::getType()
{
    if(ui->modeCh1->isChecked()){
        return 1;
    }else if(ui->modeCh2->isChecked()){
        return 2;
    }else if(ui->modeCh3->isChecked()){
        return 3;
    }else{
        QMessageBox::warning(this,"Warning","Please choose the mode firstly!");
        return 0;
    }
}

void Terminus::sendEdict(QString msg)
{
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream<<getType()<<msg;

    socket->writeDatagram(array,QHostAddress::LocalHost,port);

    ui->Input->clear();
}

void Terminus::receiveEdict()
{
    int size = socket->pendingDatagramSize();
    QByteArray array = QByteArray(size,0);
    socket->readDatagram(array.data(),size);

    QDataStream stream(&array, QIODevice::ReadOnly);
    int type;
    QString text;
    stream>>type;
    stream>>text;
    switch (type) {
    case 1:
        ui->Browser1->append(text);
        break;
    case 2:
        ui->Browser2->append(text);
        break;
    case 3:
        ui->Browser3->append(text);
        break;
    }
}

Terminus::~Terminus()
{
    delete ui;
}

