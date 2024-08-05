#pragma once
#include <qwidget.h>
#include <QQueue>
#include <QPixmap>
#include <QTimer>
#include <qmovie.h>

class GifPlayer : public QWidget
{
	Q_OBJECT
public:
    explicit GifPlayer(QString& gifPath,QWidget* parent = nullptr);
    ~GifPlayer();
    void setScale(bool isBigger);
private:
    void setFrame();

    QImage img;
    QMovie movie;
    QTimer* timer;
    double ratio{ 1.f };
    unsigned int curFrameIndex{ 0 };
    double scaleFactor{ 0.f };

protected:
    void paintEvent(QPaintEvent* event) override;
};

