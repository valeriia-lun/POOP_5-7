#include "canvas.h"
#include "newimage.h"



Canvas::Canvas(MainWindow *p) : QWidget()
{
    _window = p;

    _maximalX = 680;
   _maximalY = 620;
    _label = new QLabel(this);
    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
   _actualPixel = _pixmapList.size()-1;
    _pixmapList[_actualPixel]->fill();
    _painter = new QPainter(_pixmapList[_actualPixel]);


//kkk
    _label->setPixmap(*_pixmapList[_actualPixel]);
}

void Canvas::paintEvent(QPaintEvent *event)
{


}

//Event souris
void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(_window->getDrawEnable())
    {
        _xMove = event->pos().x();
        _yMove = event->pos().y();
        draw();


    }
    if(_window->getRectangleEnable())
    {
        _xMove = event->pos().x();
        _yMove = event->pos().y();
        drawRectangleTemporary();
    }
    if(_window->getCircleEnable())
    {
        _xMove = event->pos().x();
        _yMove = event->pos().y();
        drawCircleTemporary();
    }
    if(_window->getLineEnable())
    {
        _xMove = event->pos().x();
        _yMove = event->pos().y();
        drawLineTemporary();
    }


}
void Canvas::mousePressEvent(QMouseEvent* event)
{
    if(_window->getRectangleEnable()||_window->getCircleEnable()
            ||_window->getFillingEnable()||_window->getLineEnable())
    {
        _xPress = event->pos().x();
        _yPress = event->pos().y();

    }
    if(_window->getDrawEnable())
    {
        _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
        _actualPixel = _actualPixel+1;
        _pixmapList[_actualPixel]->operator =(*_pixmapList[_actualPixel-1]);
        _painter->end();
        delete _painter;
        _painter = new QPainter(_pixmapList[_actualPixel]);
    }
    if(_window->getDrawEnable())
    {
        _xPress = event->pos().x();
        _yPress = event->pos().y();
        _path = new QPainterPath(QPointF(_xPress,_yPress));
        _path->moveTo(_xPress,_yPress);
    }

}
void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if(_window->getRectangleEnable())
    {
        _xRelease = event->pos().x();
        _yRelease = event->pos().y();
        drawRectangle();

    }
    if(_window->getCircleEnable())
    {
        _xRelease = event->pos().x();
        _yRelease = event->pos().y();
        drawCircle();

    }
    if(_window->getLineEnable())
    {
        _xRelease = event->pos().x();
        _yRelease = event->pos().y();
        drawLine();

    }
    if(_window->getPolygonEnable())
    {
        _xRelease = event->pos().x();
        _yRelease = event->pos().y();
        drawLine();

    }
    if(_window->getFillingEnable())
    {
        _xRelease = event->pos().x();
        _yRelease = event->pos().y();
        filling();

    }
    if(_window->getDrawEnable())
    {
        delete _path;
    }

}
//Fonctions
void Canvas::draw()
{
    QPen pen;

    _path->lineTo(_xMove,_yMove);
    pen.setColor(_window->getColor());
    pen.setWidth(_window->getSliderValue());
    _painter->setPen(pen);
    _painter->setRenderHint(QPainter::Antialiasing);
    _painter->drawPath(*_path);

    _label->setPixmap(*_pixmapList[_actualPixel]);
}
void Canvas::drawRectangle()
{
    QPen pen;
    pen.setColor(_window->getColor());
    pen.setWidth(_window->getSliderValue());

    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
    _actualPixel = _actualPixel+1;
    _pixmapList[_actualPixel]->operator =(*_pixmapList[_actualPixel-1]);
    _painter->end();
    delete _painter;
    _painter = new QPainter(_pixmapList[_actualPixel]);

    _painter->setPen(pen);
    _painter->drawRect(_xPress,_yPress,_xRelease-_xPress,_yRelease-_yPress);

    _label->setPixmap(*_pixmapList[_actualPixel]);
}
void Canvas::drawRectangleTemporary()
{
    QPen pen;
    pen.setColor(_window->getColor());
    pen.setWidth(_window->getSliderValue());

    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
    _actualPixel = _actualPixel+1;
    _pixmapList[_actualPixel]->operator =(*_pixmapList[_actualPixel-1]);
    _painter->end();
    delete _painter;
    _painter = new QPainter(_pixmapList[_actualPixel]);

    _painter->setPen(pen);
    _painter->drawRect(_xPress,_yPress,_xMove-_xPress,_yMove-_yPress);
    _label->setPixmap(*_pixmapList[_actualPixel]);
    _pixmapList.remove(_actualPixel);
    _actualPixel = _pixmapList.size()-1;
}

void Canvas::drawCircle()
{
    QPen pen;
    pen.setColor(_window->getColor());
    pen.setWidth(_window->getSliderValue());

    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
    _actualPixel = _actualPixel+1;
    _pixmapList[_actualPixel]->operator =(*_pixmapList[_actualPixel-1]);
    _painter->end();
    delete _painter;
    _painter = new QPainter(_pixmapList[_actualPixel]);

    _painter->setPen(pen);
    _painter->drawEllipse(_xPress,_yPress,_xRelease-_xPress,_yRelease-_yPress);
    _label->setPixmap(*_pixmapList[_actualPixel]);
}
void Canvas::drawCircleTemporary()
{
    QPen pen;
    pen.setColor(_window->getColor());
    pen.setWidth(_window->getSliderValue());

    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
    _actualPixel = _actualPixel+1;
    _pixmapList[_actualPixel]->operator =(*_pixmapList[_actualPixel-1]);
    _painter->end();
    delete _painter;
    _painter = new QPainter(_pixmapList[_actualPixel]);

    _painter->setPen(pen);
    _painter->drawEllipse(_xPress,_yPress,_xMove-_xPress,_yMove-_yPress);
    _label->setPixmap(*_pixmapList[_actualPixel]);
    _pixmapList.remove(_actualPixel);
    _actualPixel = _pixmapList.size()-1;
}

void Canvas::drawLine()
{
    QPen pen;
    pen.setColor(_window->getColor());
    pen.setWidth(_window->getSliderValue());

    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
    _actualPixel = _actualPixel+1;
    _pixmapList[_actualPixel]->operator =(*_pixmapList[_actualPixel-1]);
    _painter->end();
    delete _painter;
    _painter = new QPainter(_pixmapList[_actualPixel]);

    _painter->setPen(pen);
    _painter->drawLine(_xPress,_yPress,_xRelease,_yRelease);
    _label->setPixmap(*_pixmapList[_actualPixel]);

}
void Canvas::drawLineTemporary()
{
    QPen pen;
    pen.setColor(_window->getColor());
    pen.setWidth(_window->getSliderValue());

    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
    _actualPixel = _actualPixel+1;
    _pixmapList[_actualPixel]->operator =(*_pixmapList[_actualPixel-1]);
    _painter->end();
    delete _painter;
    _painter = new QPainter(_pixmapList[_actualPixel]);

    _painter->setPen(pen);
    _painter->drawLine(_xPress,_yPress,_xMove,_yMove);
    _label->setPixmap(*_pixmapList[_actualPixel]);
    _pixmapList.remove(_actualPixel);
    _actualPixel = _pixmapList.size()-1;
}


//void Canvas::drawPolygon()
//{
//    QPen pen;
//    pen.setColor(window->getColor());
//    pen.setWidth(window->getSliderValue());

//    pixmapList.push_back(new QPixmap(xMax,yMax));
//    pixActuel = pixActuel+1;
//    pixmapList[pixActuel]->operator =(*pixmapList[pixActuel-1]);
//    painter->end();
//    delete painter;
//    painter = new QPainter(pixmapList[pixActuel]);

//    painter->setPen(pen);

//   // painter->drawPie(xPress,yPress,xRelease);
// //  painter->drawPolygon(xPress,yPress,xRelease,yRelease);
//   // painter->drawLine(xPress,yPress,xRelease,yRelease);
//    label->setPixmap(*pixmapList[pixActuel]);

//}
//void Canvas::drawTempPolygon()
//{
//    QPen pen;
//    pen.setColor(window->getColor());
//    pen.setWidth(window->getSliderValue());

//    pixmapList.push_back(new QPixmap(xMax,yMax));
//    pixActuel = pixActuel+1;
//    pixmapList[pixActuel]->operator =(*pixmapList[pixActuel-1]);
//    painter->end();
//    delete painter;
//    painter = new QPainter(pixmapList[pixActuel]);

//    painter->setPen(pen);
//    QRectF rect = QRectF(0, 0, 100, 100);

//    QPainterPath path;
//    path.moveTo(rect.left() + (rect.width() / 2), rect.top());
//    path.lineTo(rect.bottomLeft());
//    path.lineTo(rect.bottomRight());
//    path.lineTo(rect.left() + (rect.width() / 2), rect.top());

//    painter->fillPath(path, QBrush(QColor ("blue")));

//  //  painter->drawLine(xPress,yPress,xMove,yMove);
//    label->setPixmap(*pixmapList[pixActuel]);
//    pixmapList.remove(pixActuel);
//    pixActuel = pixmapList.size()-1;
//}

void Canvas::filling()
{
    _painter->end();
    delete _painter;
    QRgb couleurCible,couleurReproduit;
    QColor couleurBuff;

    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
    _actualPixel =  _actualPixel+1;
    _pixmapList[_actualPixel]->operator =(*_pixmapList[_actualPixel-1]);


    _image = new QImage(_maximalX,_maximalY,QImage::Format_RGB32);
    *_image = _pixmapList[_actualPixel]->toImage();
    couleurCible = _image->pixel(_xPress,_yPress);
    couleurReproduit = _window->getColor().rgb();
    fillageFour(_xPress,_yPress,couleurCible,couleurReproduit);




    _pixmapList[_actualPixel]->convertFromImage(*_image);
    _painter = new QPainter(_pixmapList[_actualPixel]);

    delete _image;


    _label->setPixmap(*_pixmapList[_actualPixel]);
}
//Algorithme de remplissage d'une surface
int Canvas::fillageFour(int x,int y,QRgb colcible, QRgb colrep)
{
    int a,b,i;
    int lastPosition;
    QVector<Point*> listPosition;

    if(_image->pixel(x,y)!= colcible)
    {
        return 1;
    }
    if(x<0||y<0||x>(_maximalX-1)||y>(_maximalY-1)||colcible==colrep)
    {
        return 0;
    }

    listPosition.push_back(new Point(x,y));

    while(listPosition.empty()==0)
    {


        a = listPosition[listPosition.size()-1]->getX();
        b = listPosition[listPosition.size()-1]->getY();

        if(a==1||b==1||a==(_maximalX-1)||b==(_maximalY-1))
        {
            for(i=0;i<_maximalX;i++)
            {
               _image->setPixel(i,0,colrep);
               _image->setPixel(i,_maximalY-1,colrep);
            }
            for(i=0;i<_maximalY;i++)
            {
               _image->setPixel(0,i,colrep);
               _image->setPixel(_maximalX-1,i,colrep);
            }
        }
        lastPosition = listPosition.size()-1;
        listPosition.remove(lastPosition);

        _image->setPixel(a,b,colrep);

        if(_image->pixel(a,b-1)==colcible)
        {
            listPosition.push_back(new Point(a,b-1));
        }

        if(_image->pixel(a,b+1)==colcible)
        {
            listPosition.push_back(new Point(a,b+1));
        }
        if(_image->pixel(a+1,b)==colcible)
        {
            listPosition.push_back(new Point(a+1,b));
        }
        if(_image->pixel(a-1,b)==colcible)
        {
            listPosition.push_back(new Point(a-1,b));
        }
    }
    return 1;
}

//Fonction slots
void Canvas::saveCanvas()
{
    QString fichier = QFileDialog::getSaveFileName(0, "Save image", QString(), "Images (*.png)");

    _pixmapList[_actualPixel]->save(fichier);
}

void Canvas::openCanvas()
{
    QString fichier = QFileDialog::getOpenFileName(0,"Open image",QString(),"Images (*.png *.gif *.jpg *.jpeg)");
    _painter->end();
    delete _painter;
    _pixmapList.remove(_actualPixel);
    _pixmapList.push_back(new QPixmap(fichier));
    _painter = new QPainter(_pixmapList[_actualPixel]);
    _label->setPixmap(*_pixmapList[_actualPixel]);

}

void Canvas::newCanvas()
{
    _painter->end();
    delete _painter;
    _pixmapList.erase(_pixmapList.begin(),_pixmapList.end());
    delete _label;
    _maximalX = NewImage::getWidth();
    _maximalY = NewImage::getHeight();

    _pixmapList.push_back(new QPixmap(_maximalX,_maximalY));
    _actualPixel = _pixmapList.size()-1;
    _pixmapList[_actualPixel]->fill();

    _label = new QLabel(this);
    _label->setPixmap(*_pixmapList[_actualPixel]);
    _label->show();
    _painter = new QPainter(_pixmapList[_actualPixel]);
}
void Canvas::undoCanvas()
{
    if(_actualPixel ==0) return;
    _pixmapList.remove(_actualPixel);
    _actualPixel = _pixmapList.size()-1;
    _painter->end();
    delete _painter;
    _painter = new QPainter(_pixmapList[_actualPixel]);
    _label->setPixmap(*_pixmapList[_actualPixel]);

}
