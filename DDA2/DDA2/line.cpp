#include "line.h"
#include "ui_line.h"
#include <QPainter>

Line::Line(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Line)
{
    ui->setupUi(this);

    /*设置窗口*/
    setWindowTitle("Draw Line");
    setAutoFillBackground(true);
    //setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFixedSize(560, 560);
    setFocusPolicy(Qt::StrongFocus);

    Pix = QPixmap(560, 560);
    Pix.fill(Qt::transparent);

    ddaColor = qRgb(225,0,0);
    breColor = qRgb(0,0,255);

    /*设置DDA button*/
    DDA = new QToolButton(this);
    DDA->setText("DDA");
    DDA->setCheckable(true);
    DDA->adjustSize();
    DDA->move(10, 0);

    /*设置Bresenham button*/
    BRE = new QToolButton(this);
    BRE->setText("BRE");
    BRE->setCheckable(true);
    BRE->adjustSize();
    BRE->move(20 + DDA->width(), 0);


}

void Line::paintEvent(QPaintEvent *event) { //重写paintEvent
    QPainter painter(this);
    int i;
    //绘制网格，网格长度为5
    for(i = 0; i<=100; i++)
        painter.drawLine(0+30, i*5+30, 500+30, i*5+30);
    for(i = 0; i<=100; i++)
        painter.drawLine(i*5+30, 0+30, i*5+30, 500+30);

    painter.drawPixmap(30, 30, Pix);
}

void Line::dda(QMouseEvent *event) {//dda算法
    //设置画笔
    QPainter myPainter(&Pix);
    myPainter.setPen(ddaColor);

    //DDA算法核心代码
    if(flipflop){
        startPoint=event->pos(); //起始点
    }
    else{
        endPoint=event->pos(); //终点

        //x1-x0和y1-y0
        int dx = endPoint.x() - startPoint.x();
        int dy = endPoint.y() - startPoint.y();

        int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

        /*增量*/
        float Xinc = dx / (float) steps;
        float Yinc = dy / (float) steps;

        QPointF tempPoint = startPoint;

        /*从起点到终点，依次以每个点为顶点绘制正方形（像素格）*/
        for(int i = 0; i <= steps; i++) {
            myPainter.drawRect((int)tempPoint.x(), (int)tempPoint.y(), 5, 5);
            tempPoint.setX(tempPoint.x() + Xinc);
            tempPoint.setY(tempPoint.y() + Yinc);
        }
    }
    update();
    flipflop=!flipflop;
}


void Line::bre(QMouseEvent *event) { //Bresenham算法
    //设置画笔
    QPainter myPainter(&Pix);
    myPainter.setPen(breColor);

    //核心代码
    if(flipflop) {
        startPoint = event->pos();  //起点
    } else {
        endPoint = event->pos();  //终点

        //x1-x0和y1-y0
        int dx = abs(endPoint.x() - startPoint.x());
        int dy = abs(endPoint.y() - startPoint.y());
        //增量
        int xInc = startPoint.x() < endPoint.x()? 1 : -1;
        int yInc = startPoint.y() < endPoint.y()? 1 : -1;
        int k1 = (dx > dy ? dx : -dy) / 2;
        int k2;
        QPoint tempPoint = startPoint;
        //从起始点开始到终点，绘制像素格
        while(1) {
            myPainter.drawRect(tempPoint.x(), tempPoint.y(), 5, 5);
            if(tempPoint == endPoint)
                break;
            k2 = k1;
            if(k2 > -dx) {
                k1 -= dy;
                tempPoint.setX(tempPoint.x() + xInc);
                //tempPoint.setY(tempPoint.y() + yInc);
            }
            if(k2 < dy) {
                k1 += dx;
                //tempPoint.setX(tempPoint.x() + xInc);
                tempPoint.setY(tempPoint.y() + yInc);
            }
        }
    }
    update();
    flipflop = !flipflop;

}

void Line::mousePressEvent(QMouseEvent *event) {
    if(DDA->isChecked()) {
        dda(event);
    } else if(BRE->isChecked()) {
        bre(event);
    }
}

Line::~Line()
{
    delete ui;
}
