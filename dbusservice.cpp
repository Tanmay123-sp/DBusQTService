#include "dbusservice.h"
#include <QDebug>
#include <QDBusError>

dbusService::dbusService(QWidget *parent)
    : QWidget(parent), layout(new QVBoxLayout(this)), inputBox(new QLineEdit(this)), inputBox2(new QLineEdit(this)), sendButton(new QPushButton("Send Money", this)) {
    QLabel *label1 = new QLabel("Send Money", this);
    label1->setStyleSheet("font-size: 24px; font-weight: bold; color: blue;");
    label1->setAlignment(Qt::AlignCenter);

    // Input Boxes
    inputBox->setPlaceholderText("Enter recipient's name...");
    inputBox->setStyleSheet("font-size: 16px; padding: 8px; border: 1px solid #ccc; border-radius: 5px;");

    inputBox2->setPlaceholderText("Enter amount...");
    inputBox2->setStyleSheet("font-size: 16px; padding: 8px; border: 1px solid #ccc; border-radius: 5px;");

    // Send Button
    sendButton->setStyleSheet(
        "background-color: #4CAF50; color: white; font-size: 16px; padding: 10px;"
        "border: none; border-radius: 5px;"
        "hover: { background-color: #45a049; }"
        );

    // Add Widgets to Layout
    layout->addWidget(label1);
    layout->addSpacing(20);
    layout->addWidget(inputBox);
    layout->addWidget(inputBox2);
    layout->addSpacing(10);
    layout->addWidget(sendButton);

    // Connect button to setData slot
    connect(sendButton, &QPushButton::clicked, this, &dbusService::setData);

    // Register D-Bus Service
    if (!QDBusConnection::sessionBus().registerService("com.example.InputService")) {
        qDebug() << "Failed to register service:" << QDBusConnection::sessionBus().lastError().message();
    }
    if (!QDBusConnection::sessionBus().registerObject("/InputObject", this, QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals)) {
        qDebug() << "Failed to register object:" << QDBusConnection::sessionBus().lastError().message();
    }

    setWindowTitle("Service");
    resize(600, 300);
    show(); // Show the GUI window
}

void dbusService::setData() {
    m_input = inputBox->text();
    m_amount = inputBox2->text();
    emit dataReceived(m_input, m_amount);
    qDebug() << "Data Sent:" << m_input << ", " << m_amount;
}

