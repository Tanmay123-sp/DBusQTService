#ifndef DBUSSERVICE_H
#define DBUSSERVICE_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDBusConnection>

class dbusService : public QWidget { // Changed to QWidget
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.example.InputService")

public:
    explicit dbusService(QWidget *parent = nullptr);

public slots:
    void setData();

signals:
    void dataReceived(const QString &input, const QString &amount);

private:
    QVBoxLayout *layout;
    QLineEdit *inputBox;
    QLineEdit *inputBox2;
    QPushButton *sendButton;
    QString m_input;
    QString m_amount;
};

#endif // DBUSSERVICE_H
