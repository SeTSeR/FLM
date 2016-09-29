#ifndef COMPLEXPLANE_H
#define COMPLEXPLANE_H

#include <QLabel>
#include <QMouseEvent>
#include "complex.h"

#define MAXW 400
#define MAXH 400

class ComplexPlane : public QLabel
{
Q_OBJECT
public:
    int map[MAXW][MAXH] {{0}};
    int prevmap[MAXW][MAXH] {{0}};
    Complex lBot = Complex(-2,-2),rTop = Complex(2,2);
    
    bool writingTrack = 0;
    ComplexPlane() : QLabel() {this->setMouseTracking(true);}
    long double lastx = -1, lasty = -1;
private:
    int linex,liney;
signals:
    void redraw();
private slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // COMPLEXPLANE_H
