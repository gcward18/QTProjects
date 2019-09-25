#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_searchButton_clicked();

private:
    Ui::Widget *ui;
    QString url;
};
#endif // WIDGET_H
