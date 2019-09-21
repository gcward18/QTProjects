#include "widget.h"
#include "ui_widget.h"
#include <cstdlib>
#include <ctime>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initialize
    std::srand(std::time(NULL));

    //Generate Random number;
    this->secretNumber = std::rand() % 10 + 1;

    //Output Secret Number to the Terminal
    qDebug() << "Secret Number generated: " << QString::number(secretNumber);

    //Align QLabels Text
    ui->messageLabel->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);

    //Disable start over Button
    ui->guessButton->setDisabled(false);
    ui->startOverButton->setDisabled(true);

    //Set default message text
    ui->messageLabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    //Get value from drop down
    guessNumber = ui->spinBox->value();

    //Output Secret Number to the Terminal
    qDebug() << "The guess number is: " << QString::number(guessNumber);

    if( guessNumber == secretNumber )
    {
        //Congratulations
        ui->messageLabel->setText("Congratulations!!! The number is: " + QString::number(secretNumber));

        //Disable the guess Button
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }else
    {
        if( secretNumber < guessNumber )
        {
            ui->messageLabel->setText("The number is lower");
        }else
        {
            ui->messageLabel->setText("The number is higher");
        }
    }
    ui->messageLabel->setAlignment(Qt::AlignCenter);
}

void Widget::on_startOverButton_clicked()
{
    //Enable guess button
    ui->guessButton->setDisabled(false);

    //Disable start over button
    ui->startOverButton->setDisabled(true);

    //Put spin box back to 1
    ui->spinBox->setValue(1);

    //Regenerate random number
    secretNumber = rand()%10 +1;

    //Clear message label
    ui->messageLabel->setText("");

}
