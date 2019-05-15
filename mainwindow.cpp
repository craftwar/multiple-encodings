#include <QTextCodec>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    bool test = textEdit_[0].testAttribute(Qt::WA_InputMethodEnabled);
//    for (const auto &i: encodings) {
    for (unsigned char i=0; i < encoding_nums; ++i) {
        unsigned char row = (i+1)/2;
        unsigned char col = (i+1)%2;
        textEdit_[i].setParent(ui->centralWidget);
        label_[i].setParent(ui->centralWidget);
        textEdit_[i].setGeometry(QRect(col? 500: 20, 40 + 170*row, 361, 111));
        label_[i].setText(encodings[i]);
        label_[i].setGeometry(QRect(col? 630: 170, 20 + 170*row , 47, 12));

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::encode()
{
    const QString &text = ui->inputText->toPlainText();
//    textEdit_[1].setPlainText(text.toUtf8().toHex().toUpper());
    for (int i=0; i<encoding_nums; ++i) {
        QTextCodec *codec = QTextCodec::codecForName(encodings[i]);
        QByteArray encodedString = codec->fromUnicode(text);
        textEdit_[i].setPlainText(encodedString.toHex().toUpper());
    }
}


void MainWindow::decode()
{
//    const QString &text = ui->inputText->toPlainText();
////    const QByteArray &text = ui->inputText->toPlainText().toUtf8();
//    QByteArray byteArray;
//    const int len = text.length();
//    for (int i=0; i<len; i+=2)
//        byteArray.append(static_cast<char>(text.midRef(i, 2).toUInt(nullptr, 16)));
    QByteArray byteArray = QByteArray::fromHex(ui->inputText->toPlainText().toUtf8());

    for (int i=0; i<encoding_nums; ++i) {
        QTextCodec *codec = QTextCodec::codecForName(encodings[i]);
        QString decodedString = codec->toUnicode(byteArray);
        textEdit_[i].setPlainText(decodedString);
    }
}
