#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
#include<QMouseEvent>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    isGrasp=false;
    preStatus=true;
    cur=true;
    widget_x=-5;
    widget_y=950;
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    ui->setupUi(this);
    run1.load("F:\\QT_Code\\run1.png");
    run2.load("F:\\QT_Code\\run2.png");
    QTimer *timer=new QTimer(this);
    timer->start(50);
    connect(timer,QTimer::timeout,this,[=]()
    {
        widget_x=this->frameGeometry().topLeft().x()+5;
        if(widget_x>1980)   widget_x=-30;
        widget_y=this->frameGeometry().topLeft().y();
        if(!isGrasp&&cur)
        this->update();
    });
    dinoX=0,dinoY=0;
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    static int cnt=0;
    if(cnt%2)    paint.drawPixmap(dinoX,dinoY,run1);
    else           paint.drawPixmap(dinoX,dinoY,run2);
    cnt=(cnt+1)%2;
    this->move(widget_x,widget_y);

}
void Widget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::RightButton)  this->close();
    else if(ev->button()==Qt::LeftButton)
    {
        preStatus=cur;
        point=ev->globalPos()-this->frameGeometry().topLeft();
        isGrasp=true;
    }
}
void Widget::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton)
    {
        isGrasp=false;
        if(cur) cur=false;
        else cur=true;
    }
}

void Widget::mouseMoveEvent(QMouseEvent *ev)
{
    if(preStatus) cur=false;
    else cur=true;
    this->move(ev->globalPos()-point);
}
