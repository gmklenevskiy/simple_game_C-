#include <QtGui/QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include "my_rect.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <game.h>

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    return a.exec();
}
