#ifndef MYLISTWIDGETITEM_H
#define MYLISTWIDGETITEM_H

#include <QWidget>

namespace Ui {
class MyListWidgetItem;
}

class MyListWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit MyListWidgetItem(QWidget *parent = 0);
    ~MyListWidgetItem();

    void setImage(const char *image_path);
    void setText(const char *str);

private:
    Ui::MyListWidgetItem *ui;
};

#endif // MYLISTWIDGETITEM_H