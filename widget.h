#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include<QPoint>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QPixmap run1;
    QPixmap run2;
    int dinoX,dinoY;

protected :
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    QPoint point;
    int widget_x,widget_y;
    bool preStatus;
    bool cur;
    bool isGrasp;
};

#endif // WIDGET_H
