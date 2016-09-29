#include "complexplane.h"
#include <QDebug>
#include <cstring>

void ComplexPlane::mouseMoveEvent(QMouseEvent *event)
{
    if (!event->buttons())
        return;
    else if (event->buttons() & Qt::LeftButton)
        map[event->x()][event->y()] = 1 - map[event->x()][event->y()];
    else if (event->buttons() & Qt::RightButton)
    {
        int xs = linex - lastx;
        int ys = liney - lasty;
        
        long double dy = (double)ys/(double)xs;
        
        //qDebug() << (double)dy;
        int dx = (lastx > linex ? 1 : -1);
        
        if (lastx >= 0 && lasty >= 0)
            for (int i = linex; i != lastx; i += dx)
                map[i][(int)(liney + (i-linex) * dy)] = prevmap[i][(int)(liney + (i-linex) * dy)];
        
        lastx = event->x(),lasty = event->y();
        memcpy(prevmap,map,MAXH * MAXW * sizeof(int));
        
        xs = linex - lastx;
        ys = liney - lasty;
        
        dy = (double)ys/(double)xs;
        
        //qDebug() << (double)dy;
        dx = (lastx > linex ? 1 : -1);
        
        if (lastx >= 0 && lasty >= 0)
            for (int i = linex; i != lastx; i += dx)
                map[i][(int)(liney + (i-linex) * dy)] = 1;
        
    }
    emit redraw();
}

void ComplexPlane::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::RightButton)
        linex = event->x(),liney = event->y();
}

void ComplexPlane::mouseReleaseEvent(QMouseEvent *event)
{
    lastx = lasty = -1;
}
