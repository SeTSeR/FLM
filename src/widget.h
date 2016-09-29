#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "complexplane.h"
#include "complex.h"
#include <QCloseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    ComplexPlane *Z,*W;
    Complex a = Complex(1,0),b = Complex(0,1),c = Complex(1,0),d = Complex(0,-1);
    
private:
    Ui::Widget *ui;
private slots:
    void closeEvent(QCloseEvent *event);
    void draw();
};

#endif // WIDGET_H
