// #ifndef DBUSSERVICE_H
// #define DBUSSERVICE_H

// #include <QObject>
// #include <QString>
// #include <QDBusConnection>
// #include <QLineEdit>
// #include <QVBoxLayout>
// #include <QLabel>
// #include <QPushButton>


// class dbusService : public QObject {
//     Q_OBJECT
//     Q_CLASSINFO("D-Bus Interface", "com.example.InputService")

// public:
//     explicit dbusService(QObject *parent = nullptr);
//     QVBoxLayout *layout =nullptr;
//     QLineEdit *inputBox =nullptr;
//     QLineEdit *inputBox2 =nullptr;
//     QPushButton *sendButton =nullptr;

// public slots:
//     // void setInput(const QString &input);
//     // void setAmount(const QString &amount);
//     void setData(/*const QString &input,const QString &amount*/);

// signals:
//     // void inputReceived(const QString &input);
//     // void amountReceived(const QString &amount);
//     void dataReceived(const QString &input,const QString &amount);

// private:
//     QString m_input;
//     QString m_amount;

// };

// #endif // DBUSSERVICE_H
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
