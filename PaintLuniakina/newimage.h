#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include <QWidget>
#include "canvas.h"
#include <QLineEdit>

class NewImage : public QWidget
{
    Q_OBJECT
public:
    NewImage(Canvas *canevas );
    static int getWidth();
    static int getHeight();



public slots:
    void createClick();
    void getWidthLine(QString lLine);
    void getHeightLine(QString hLine);

private:
    static int width;
    static int height;
    QLineEdit *widthLine;
    QLineEdit *heightLine;
    QPushButton *create;



};
#endif
