#include "my_rect.h"
#include "QKeyEvent"
#include "QDebug"
#include "bullet.h"
#include "QGraphicsScene"
#include "enemy.h"
#include "QTimer"
#include "QList"
#include "typeinfo"
#include "health.h"
#include "game.h"

extern Game *game;
void My_Rect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x()>0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        BULLET *bullet = new BULLET();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            game->health->decrease();


            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}

void My_Rect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);

}
