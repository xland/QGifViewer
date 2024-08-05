#include "GifPlayer.h"
#include "qpainter.h"

GifPlayer::GifPlayer(QString& gifPath, QWidget* parent) : 
    QWidget(parent), 
    timer(new QTimer(this)),
    movie(gifPath,QByteArray(),this)
{
    scaleFactor = metric(PdmDevicePixelRatioScaled) / devicePixelRatioFScale();
    movie.jumpToFrame(curFrameIndex);
    setFrame();
    update();
    QObject::connect(timer, &QTimer::timeout, [this]() {
        this->update();
        });
    timer->setSingleShot(true);
}

GifPlayer::~GifPlayer() {

}

void GifPlayer::setScale(bool isBigger)
{
    if (isBigger) {
        this->ratio += 0.1;
    }
    else {
        this->ratio -= 0.1;
    }
    if (this->ratio <= 0) {
        this->ratio = 0.1;
    }
}

void GifPlayer::setFrame()
{
    img = movie.currentImage();
    auto tempSize = img.size() * ratio;
    this->setMaximumSize(tempSize / scaleFactor);
    this->setMinimumSize(tempSize / scaleFactor);
    img = img.scaled(tempSize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    img.setDevicePixelRatio(scaleFactor);
}

void GifPlayer::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    //painter.fillRect(this->rect(), Qt::red);
    painter.drawImage(0, 0, img);

    curFrameIndex += 1;
    if (curFrameIndex >= movie.frameCount()) {
        curFrameIndex = 0;
    }
    movie.jumpToFrame(curFrameIndex);
    setFrame();
    timer->start(movie.nextFrameDelay());
}