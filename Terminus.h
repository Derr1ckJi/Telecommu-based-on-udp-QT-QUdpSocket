#ifndef TERMINUS_H
#define TERMINUS_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Terminus; }
QT_END_NAMESPACE

class Terminus : public QMainWindow
{
    Q_OBJECT


public:
    Terminus(QWidget *parent = nullptr);
    ~Terminus();
        int getType();
    void sendEdict(QString msg);
    void receiveEdict();


private:
    Ui::Terminus *ui;
    QUdpSocket *socket;
    quint16 port;

};
#endif // TERMINUS_H
