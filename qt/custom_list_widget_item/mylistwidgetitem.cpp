#include "mylistwidgetitem.h"
#include "ui_mylistwidgetitem.h"
#include <QPixmap>

MyListWidgetItem::MyListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyListWidgetItem)
{
    ui->setupUi(this);
}

MyListWidgetItem::~MyListWidgetItem()
{
    delete ui;
}

void MyListWidgetItem::setImage(const char *image_path)
{
    QPixmap img(image_path);
    ui->label_image->setScaledContents(true);
    ui->label_image->setPixmap(img);
}

void MyListWidgetItem::setText(const char *str)
{
    ui->label_path->setText(str);
}

