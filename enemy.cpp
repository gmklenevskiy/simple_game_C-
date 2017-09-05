 #include "enemy.h"
#include "QTimer"
#include "QGraphicsScene"
#include "stdlib.h"
#include "QList"
#include "game.h"

extern Game *game;

Enemy::Enemy()
{
    int random_number = rand() % 700;
    setPos(random_number, 0);
    setRect(0,0,50,50);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(35);
}

void Enemy::move()
{
    setPos(x(),y()+10);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;

    }
}
