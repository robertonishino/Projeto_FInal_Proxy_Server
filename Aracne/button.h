#ifndef BUTTON_H
#define BUTTON_H

#include "ui_aracne.h"
#include <QApplication>

class Button
{
public:
    Button();
    void handleClick();
protected:
    Ui::Aracne *_ui;
    QPushButton *_button;
};


#endif // BUTTON_H
