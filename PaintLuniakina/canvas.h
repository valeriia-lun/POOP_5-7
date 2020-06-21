#ifndef CANVAS_H
#define CANVAS_H
#include "mainwindow.h"
#include <QLabel>
#include <QGraphicsScene>



class Point{
private:
            int x;
            int y;

public:
    Point(int a,int b) : x(a),y(b) {}

    ~Point();

    int getX(){
       return x;
    }

    int getY(){
       return y;
    }


};

class Canvas : public QWidget{
 Q_OBJECT

public :

    Canvas(MainWindow *p);

    void draw();
    void drawRectangle();
    void drawCircle();
    void drawLine();
    void filling();

    void drawLineTemporary();
    void drawCircleTemporary();
    void drawRectangleTemporary();

    int fillageFour(int x,int y,QRgb colcible, QRgb colrep);

    void paintEvent(QPaintEvent* event);

     void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);


public slots:
    void openCanvas();
    void undoCanvas();
    void newCanvas();
    void saveCanvas();


private :

    int _xMove;
    int _yMove;
    int _xPress;
    int _yPress;
    int _xRelease;
    int _yRelease;

    int _actualPixel;
    int _maximalX;
    int _maximalY;

    QPainter *_painter;
    QLabel *_label;
    MainWindow *_window;
    QGraphicsScene *_scene;
    QGraphicsView *_view;
    QImage *_image;
    QVector<QPixmap*> _pixmapList;
    QPainterPath *_path;
};

#endif //LUNIAKINA_CANVAS_H
