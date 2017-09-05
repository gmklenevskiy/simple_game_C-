#include "game.h"
#include "QTimer"
#include "QGraphicsTextItem"
#include <QFont>
#include "enemy.h"

Game::Game(QWidget *parent)
{
    QGraphicsScene *scene = new QGraphicsScene();

    My_Rect *player = new My_Rect();
    player->setRect(0,0,100,100);

    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);


    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();




    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    player->setPos(view->width()/2,view->height() - player->rect().height());

    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);


}
