#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>

//static const char *encodings[] = {"EUC-JP", "ISO 2022-JP", "Shift-JIS", "UTF-16BE", "UTF-16LE"};
static const char *encodings[] = {"UTF-8", "Shift-JIS", "UTF-16", "UTF-16BE", "UTF-16LE"};
static constexpr unsigned char encoding_nums = sizeof(encodings) / sizeof(encodings[0]);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void encode();
    void decode();

private:
    Ui::MainWindow *ui;
    QTextEdit textEdit_[encoding_nums];
    QLabel label_[encoding_nums];
};

#endif // MAINWINDOW_H
