#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>


class Network: public QTcpSocket
{
    Q_OBJECT
private:

public:
    Network();
    ~Network();
    void handleMessage(QString message);
    QStringList splitMessage(QString message);
    void sendMessage(QString message);

private slots:
    void login(QString username, QString password);

    void readMessage();

public slots:
    void sendUserMessage(QString user, QString message);

signals:
    void recvUserMessage(QString user, QString message);

    void updateFriends(QStringList friends);
};