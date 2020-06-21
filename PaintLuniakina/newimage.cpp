#include "newimage.h"
#include <QtWidgets>



int NewImage::width = 700;
int NewImage::height = 600;

NewImage::NewImage(Canvas *canvas) : QWidget()
{

    QVBoxLayout *layout = new QVBoxLayout(this);
    widthLine = new QLineEdit;
    heightLine = new QLineEdit;
    QFormLayout *form = new QFormLayout;

    form->addRow("Height:",heightLine);
    form->addRow("Width:",widthLine);



    create = new QPushButton("Create new image");
    layout->addLayout(form);
    layout->addWidget(create);
    connect(create,SIGNAL(clicked(bool)),canvas,SLOT(newCanvas()));
    connect(widthLine,SIGNAL(textChanged(QString)),this,SLOT(getWidthLine(QString)));
    connect(heightLine,SIGNAL(textChanged(QString)),this,SLOT(getHeightLine(QString)));

    connect(create,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void NewImage::createClick()
{

    this->show();

}
//Fonctions slots
void NewImage::getWidthLine(QString lLine)
{
    width = lLine.toInt();
}
void NewImage::getHeightLine(QString hLine)
{
    height = hLine.toInt();
}

//FOnctions
int NewImage::getWidth()
{
    return width;
}

int NewImage::getHeight()
{
    return height;
}
