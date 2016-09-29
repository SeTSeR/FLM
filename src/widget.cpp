#include "widget.h"
#include "ui_widget.h"
#include <QImage>
#include <QPixmap>
#include <QColor>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Z = new ComplexPlane();
    W = new ComplexPlane();
    Z->setGeometry(100,100,MAXW,MAXH);
    W->setGeometry(600,100,MAXW,MAXH);
    Z->show();
    W->show();
    connect(Z,SIGNAL(redraw()),this,SLOT(draw()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event)
{
    Z->close();
    W->close();
}

void Widget::draw()
{
    long double dx = (Z->rTop - Z->lBot).Re / (long double)MAXW;
    long double dy = (Z->rTop - Z->lBot).Im / (long double)MAXH;
    
    QImage *Zi = new QImage(MAXW,MAXH,QImage::Format_ARGB32);
    QImage *Wi = new QImage(MAXW,MAXH,QImage::Format_ARGB32);
    
    for (int i = 0; i<MAXW; ++i)
        for (int j = 0; j<MAXH; ++j)
        {
            if (!Z->map[i][j])
            {    
                Zi->setPixel(i,j,QColor(255,255,255).rgba());
                continue;
            }
            Complex z = Z->lBot + Complex(i * dx, j * dy);
            Complex w = (a * z + b) / (c * z + d);
            if (!w.isInf && (w.Re - W->lBot.Re) / dx < MAXW && (w.Im - W->lBot.Im) / dy < MAXH)
                Wi->setPixel((w.Re - W->lBot.Re) / dx,(w.Im - W->lBot.Im) / dy,QColor(0,0,0).rgba());
            Zi->setPixel(i,j,QColor(0,0,0).rgba());
            
        }
    Z->setPixmap(QPixmap::fromImage(*Zi));
    W->setPixmap(QPixmap::fromImage(*Wi));
    delete Zi;
    delete Wi;
}
