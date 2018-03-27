#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(size());
    this->setWindowTitle("Qtulator");

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_znak,SIGNAL(released()),this,SLOT(zmiana_znaku()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(dzialania()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(dzialania()));
    connect(ui->pushButton_razy,SIGNAL(released()),this,SLOT(dzialania()));
    connect(ui->pushButton_dziel,SIGNAL(released()),this,SLOT(dzialania()));


    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_razy->setCheckable(true);
    ui->pushButton_dziel->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() ||ui->pushButton_razy->isChecked() ||
        ui->pushButton_dziel->isChecked())&&(!userIsTypingSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber=true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {
        if(ui->label->text().contains('.')&& button->text()=="0")
        {
            newLabel=ui->label->text()+button->text();
        }
        else
        {
            labelNumber = (ui->label->text()+button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }

    }



    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_przecinek_released()
{
    ui->label->setText(ui->label->text() + "." );
}

void MainWindow::zmiana_znaku()
{
    QPushButton * button=(QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if(button->text()=="+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber=labelNumber * -1;
        newLabel=QString::number(labelNumber, 'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_czysc_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_razy->setChecked(false);
    ui->pushButton_dziel->setChecked(false);

    userIsTypingSecondNumber=false;
    ui->label->setText("0");

}

void MainWindow::on_pushButton_rownosc_released()
{
    double labelNumber, secondNum;
    secondNum=ui->label->text().toDouble();
    QString newLabel;

    if(ui->pushButton_plus->isChecked())
    {
        labelNumber=firstNum+secondNum;
        newLabel = QString::number(labelNumber, 'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber=firstNum-secondNum;
        newLabel = QString::number(labelNumber, 'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_razy->isChecked())
    {
        labelNumber=firstNum*secondNum;
        newLabel = QString::number(labelNumber, 'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_razy->setChecked(false);
    }
    else if(ui->pushButton_dziel->isChecked())
    {
        labelNumber=firstNum/secondNum;
        newLabel = QString::number(labelNumber, 'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_dziel->setChecked(false);
    }
    userIsTypingSecondNumber=false;

}

void MainWindow::dzialania()
{
    QPushButton * button = (QPushButton*)sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);


}
