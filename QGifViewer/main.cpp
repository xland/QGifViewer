#include <QApplication>
#include <QWidget>
#include "MainWin.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv); 
    MainWin window;
    window.show();
    auto result = app.exec(); 
    return result;
}