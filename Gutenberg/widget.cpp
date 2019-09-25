#include "widget.h"
#include "ui_widget.h"
#include "HTTPRequest.hpp"
#include "QGraphicsPixmapItem"
#include "QPixmap"
#include "QGraphicsScene"
#include "QImage"
#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include "QDebug"
#include <string>
#include <vector>
#include <boost/metaparse/string.hpp>
#include <regex>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap image("/home/george/Pictures/gutenberg.jpg");
    image = image.scaled(300, 200, Qt::KeepAspectRatioByExpanding);
    ui->label->setMaximumHeight(500);
    ui->label->setPixmap(image);
    ui->label->setAlignment(Qt::AlignCenter);
}

Widget::~Widget()
{
    delete ui;
}

std::vector<std::string> getTopHundredURLS()
{
    std::vector<std::string> top_urls;

    return top_urls;
}

void Widget::on_searchButton_clicked()
{
    this->url = ui->plainTextEdit->toPlainText();
    std::string base_url = "http://www.gutenberg.org/files/$book_id/$book_id.txt";

    qDebug() << this->url;
    try {
        http::Request request(this->url.toStdString());

        http::Response response = request.send("GET");
        std::string res = std::string( response.body.begin(), response.body.end());

        qDebug() << QString::fromStdString(res);

        ui->plainTextEdit_2->setPlainText(QString::fromStdString(res));
    } catch (const std::exception& e) {
        qDebug() << QString::fromStdString("Request failed, error: ") << QString::fromStdString(e.what()) << endl;
    }
}
