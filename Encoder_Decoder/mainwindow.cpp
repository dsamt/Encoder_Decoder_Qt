#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

int OneTimePad::offset;
OneTimePad* OneTimePad::otpInstance;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_encodeButton_clicked()
{
    std::vector<CoderStrategy*> vec;

    //vec.push_back(new PalindromeCoder());
    //vec.push_back(new LegacyCoder());
    //vec.push_back(new CaesarCoder(5));
    vec.push_back(OneTimePad::getInstance());

    std::wstring text = ui->textEdit->toPlainText().toStdWString().c_str();

    for (size_t i = 0; i < vec.size(); i++){
         ui->textEdit_2->setText(QString::fromStdWString(vec.at(i)->encode(text)));
         //ui->textEdit_2->setText(QString::fromStdWString(text));
    }

}


void MainWindow::on_decodeButton_clicked()
{
    std::vector<CoderStrategy*> vec;

   // vec.push_back(new PalindromeCoder());
    //vec.push_back(new CaesarCoder(5));
    vec.push_back(OneTimePad::getInstance());

    std::wstring text = ui->textEdit_2->toPlainText().toStdWString().c_str();

    for (size_t i = 0; i < vec.size(); i++){
        ui->textEdit_3->setText(QString::fromStdWString(vec.at(i)->decode(text)));
    }
}

