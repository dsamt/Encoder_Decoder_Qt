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

    vec.push_back(new CaesarCoder(5));
    vec.push_back(OneTimePad::getInstance());
    vec.push_back(new PalindromeCoder());
    vec.push_back(new LegacyCoder());


    std::wstring text = ui->textEdit->toPlainText().toStdWString().c_str();

    for (size_t i = 0; i < vec.size(); i++){
        if (i == 0){
         ui->textEdit_2->setText(QString::fromStdWString(vec.at(i)->encode(text)));
        }
        else if (i == 1){
            ui->textEdit_3->setText(QString::fromStdWString(vec.at(i)->encode(text)));
        }
        else if (i == 2){
            ui->textEdit_4->setText(QString::fromStdWString(vec.at(i)->encode(text)));
        }
        else if (i == 3){
            ui->textEdit_5->setText(QString::fromStdWString(vec.at(i)->encode(text)));
        }

    }
}

void MainWindow::on_decodeButton_clicked()
{
    std::vector<CoderStrategy*> vec;

    vec.push_back(new CaesarCoder(5));
    vec.push_back(OneTimePad::getInstance());
    vec.push_back(new PalindromeCoder());
    vec.push_back(new LegacyCoder());

    std::wstring text = ui->textEdit_2->toPlainText().toStdWString().c_str();
    std::wstring text1 = ui->textEdit_3->toPlainText().toStdWString().c_str();
    std::wstring text2 = ui->textEdit_4->toPlainText().toStdWString().c_str();
    std::wstring text3 = ui->textEdit_5->toPlainText().toStdWString().c_str();

    for (size_t i = 0; i < vec.size(); i++){
        if (i == 0){
         ui->textEdit_6->setText(QString::fromStdWString(vec.at(i)->decode(text)));
        }
        else if (i == 1){
            ui->textEdit_7->setText(QString::fromStdWString(vec.at(i)->decode(text1)));
        }
        else if (i == 2){
            ui->textEdit_8->setText(QString::fromStdWString(vec.at(i)->decode(text2)));
        }
        else if (i == 3){
            ui->textEdit_9->setText(QString::fromStdWString(vec.at(i)->decode(text3)));
        }
    }
}




