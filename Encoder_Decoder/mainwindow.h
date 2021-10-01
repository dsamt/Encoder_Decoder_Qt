#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CoderStrategy.h"
#include "PalindromeCoder.h"
#include "LegacyCoder.h"
#include "Caesarcoder.h"
#include "OneTimePadCoder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_encodeButton_clicked();

    void on_decodeButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
