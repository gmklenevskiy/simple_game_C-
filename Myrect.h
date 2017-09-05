#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>

class rect: public QGraphicsRectItem{
public:
    void key_press_event (QKeyEvent *event);
};

#endif // RECT_H
