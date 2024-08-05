#include "MainWin.h"
#include <qlabel.h>
#include <qmovie.h>
#include <qlayout.h>



MainWin::MainWin(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
    QString gifPath{ "D:\\project\\QGifViewer\\x64\\Debug\\test.gif" };
    QVBoxLayout* vbox = new QVBoxLayout(this);
    this->setMouseTracking(true);


    //QLabel* label = new QLabel(this);
    //QMovie* movie = new QMovie(gifPath,QByteArray(),this);
    //label->setMovie(movie);
    //vbox->addWidget(label);
    //movie->start();
    //this->centralWidget()->setLayout(vbox);

    player = new GifPlayer(gifPath, this);
    vbox->addWidget(player);
    this->centralWidget()->setLayout(vbox);    
}

MainWin::~MainWin()
{}

void MainWin::wheelEvent(QWheelEvent * event)
{
    auto delta = event->angleDelta().y();
    player->setScale(delta > 0);
    event->accept();
}

