#ifndef MY_RECT_H
#define MY_RECT_H
#include <QObject>
#include <QGraphicsRectItem>

class My_Rect:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
};

#endif // MY_RECT_H
