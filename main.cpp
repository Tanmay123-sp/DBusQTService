// #include <QApplication>
// #include <QLineEdit>
// #include <QVBoxLayout>
// #include <QLabel>
// #include <QPushButton>
// #include "dbusservice.h"

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);
//     // QWidget window;
//     // QVBoxLayout *layout = new QVBoxLayout(&window);

//     // QLabel *label1 = new QLabel("Send Money");
//     // label1->setStyleSheet("font-size: 24px; font-weight: bold; color: blue;");
//     // label1->setAlignment(Qt::AlignCenter);

//     // // Input Boxes
//     // QLineEdit *inputBox = new QLineEdit(&window);
//     // inputBox->setPlaceholderText("Enter recipient's name...");
//     // inputBox->setStyleSheet("font-size: 16px; padding: 8px; border: 1px solid #ccc; border-radius: 5px;");

//     // QLineEdit *inputBox2 = new QLineEdit(&window);
//     // inputBox2->setPlaceholderText("Enter amount...");
//     // inputBox2->setStyleSheet("font-size: 16px; padding: 8px; border: 1px solid #ccc; border-radius: 5px;");

//     // // Send Button
//     // QPushButton *sendButton = new QPushButton("Send Money", &window);
//     // sendButton->setStyleSheet(
//     //     "background-color: #4CAF50; color: white; font-size: 16px; padding: 10px;"
//     //     "border: none; border-radius: 5px;"
//     //     "hover: { background-color: #45a049; }"
//     //     );

//     // // Add Widgets to Layout
//     // layout->addWidget(label1);
//     // layout->addSpacing(20);
//     // layout->addWidget(inputBox);
//     // layout->addWidget(inputBox2);
//     // layout->addSpacing(10);
//     // layout->addWidget(sendButton);

//     // // Set Layout Spacing and Margins
//     // layout->setSpacing(15);
//     // layout->setContentsMargins(20, 20, 20, 20);;

//     dbusService service;
//     // QObject::connect(inputBox, &QLineEdit::textChanged, &service, &dbusService::setInput);
//     // QObject::connect(inputBox2, &QLineEdit::textChanged, &service, &dbusService::setAmount);
//     // QObject::connect(sendButton, &QPushButton::clicked, &service, &dbusService::setData);

//     // window.setWindowTitle("Service");
//     // window.resize(600, 300);
//     // window.show();
//     // service.show();

//     return app.exec();
// }

#include <QApplication>
#include "dbusservice.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    dbusService service;
    return app.exec();
}
