#include "bullet.h"
#include "QTimer"
#include "QGraphicsScene"
#include "QList"
#include "enemy.h"
#include "typeinfo"
#include "game.h"

extern Game *game;

BULLET::BULLET()
{
    setRect(0,0,10,10);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);
}

void BULLET::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            game->score->increase();


            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;

    }
}
