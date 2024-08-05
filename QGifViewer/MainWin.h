#pragma once

#include <QMainWindow>
#include "ui_MainWin.h"
#include <QWheelEvent>
#include "GifPlayer.h"

class MainWin : public QMainWindow
{
	Q_OBJECT
public:
	MainWin(QWidget *parent = nullptr);
	~MainWin();
	void wheelEvent(QWheelEvent* event) override;
private:
	Ui::MainWinClass ui;
	GifPlayer* player;
};
