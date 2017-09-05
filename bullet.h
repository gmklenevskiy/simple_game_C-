#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>

class BULLET: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    BULLET();
public slots:
    void move();

};

#endif // BULLET_H
