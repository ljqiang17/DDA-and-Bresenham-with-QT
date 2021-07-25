#ifndef LINE_H
#define LINE_H

#include <QWidget>
#include <QMouseEvent>
#include <QToolButton>

namespace Ui {
class Line;
}

class Line : public QWidget
{
    Q_OBJECT

public:
    explicit Line(QWidget *parent = nullptr);
    ~Line();

private:
    QRgb ddaColor;
    QRgb breColor;
    QToolButton *DDA;
    QToolButton *BRE;
    QPoint startPoint;
    QPoint endPoint;
    QPixmap Pix;
    bool flipflop=true;
    void dda(QMouseEvent *event);
    void bre(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event) override;

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Line *ui;
};

#endif // LINE_H
