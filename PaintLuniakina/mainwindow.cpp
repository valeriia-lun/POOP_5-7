#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newimage.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(700,600);
    //Initialisation variables
    drawEnable = 0;
    rectangleEnable = 0;
    polygonEnable = 0;

    circleEnable = 0;
    lineEnable = 0;
    sliderValue = 1;


    Canvas *canvas = new Canvas(this);
    NewImage* panel = new NewImage(canvas);
    setCentralWidget(canvas);


    connect(ui->actionNew,SIGNAL(triggered(bool)),panel,SLOT(createClick()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),canvas,SLOT(saveCanvas()));
    connect(ui->actionOpen,SIGNAL(triggered(bool)),canvas,SLOT(openCanvas()));


    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(1,15);
    ui->mainToolBar->addWidget(slider);
    colorDialog = new QColorDialog;
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(slotSlider(int)));
    connect(ui->actionUndo_2,SIGNAL(triggered(bool)),canvas,SLOT(undoCanvas()));
    ui->actionUndo_2->setShortcut(QKeySequence("Ctrl+Z"));
}


bool MainWindow::getDrawEnable()
{
    return drawEnable;
}
bool MainWindow::getRectangleEnable()
{
    return rectangleEnable;
}
bool MainWindow::getPolygonEnable()
{
    return polygonEnable;
}
bool MainWindow::getCircleEnable()
{
    return circleEnable;
}
bool MainWindow::getLineEnable()
{
    return lineEnable;
}

bool MainWindow::getFillingEnable()
{
    return fillingEnable;
}

QColor MainWindow::getColor()
{
    return color;
}
int MainWindow::getSliderValue()
{
    return sliderValue;
}

//SLOTS
void MainWindow::slotDraw()
{
    drawEnable = 1;
    rectangleEnable = 0;
    circleEnable = 0;
    fillingEnable = 0;
    lineEnable = 0;
    polygonEnable = 0;

}
void MainWindow::slotRectangle()
{
    drawEnable = 0;
    rectangleEnable = 1;
    circleEnable = 0;
    fillingEnable = 0;
    lineEnable = 0;
    polygonEnable = 0;

}
void MainWindow::slotPolygon()
{
    drawEnable = 0;
    polygonEnable = 1;
    circleEnable = 0;
    fillingEnable = 0;
    lineEnable = 0;
    rectangleEnable = 0;
}
void MainWindow::slotCircle()
{
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 1;
    fillingEnable = 0;
    lineEnable = 0;
    polygonEnable = 0;

}
void MainWindow::slotFilling()
{
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    fillingEnable = 1;
    lineEnable = 0;
    polygonEnable = 0;

}

void MainWindow::slotLine()
{
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    fillingEnable = 0;
    lineEnable = 1;
    polygonEnable = 0;

}

void MainWindow::slotColor()
{
    color = colorDialog->getColor();
}

void MainWindow::slotSlider(int x)
{
    sliderValue = x;
}

void MainWindow::slotAbout()
{
    QMessageBox::information(this, trUtf8("About"),
                             trUtf8("Simple paint.\n"
                                    "Able to draw rectangle, polygon, circle, straight and custom lines\n"
                                  "Change color of figures, width of border\n"
                                    "Filling enable\n"
                                    "Also Ctrl+Z to undo action\n"
                                    "Save your image in png\n"
                                    ));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRectangle_triggered()
{
    slotRectangle();
    ui->actionRectangle->setChecked(true);
    ui->actionLine->setChecked(false);
    ui->actionCircle->setChecked(false);
    ui->actionactionPolygon->setChecked(false);
    ui->actionPencil->setChecked(false);
    ui->actionfilling->setChecked(false);
}

void MainWindow::on_actionLine_triggered()
{
    slotLine();
    ui->actionRectangle->setChecked(false);
    ui->actionLine->setChecked(true);
    ui->actionCircle->setChecked(false);
    ui->actionPencil->setChecked(false);
    ui->actionfilling->setChecked(false);
    ui->actionactionPolygon->setChecked(false);

}

void MainWindow::on_actionPencil_triggered()
{
    slotDraw();
    ui->actionRectangle->setChecked(false);
    ui->actionLine->setChecked(false);
    ui->actionCircle->setChecked(false);
    ui->actionPencil->setChecked(true);
    ui->actionfilling->setChecked(false);
    ui->actionactionPolygon->setChecked(false);

}

void MainWindow::on_actionCircle_triggered()
{
    slotCircle();
    ui->actionRectangle->setChecked(false);
    ui->actionLine->setChecked(false);
    ui->actionCircle->setChecked(true);
    ui->actionPencil->setChecked(false);
    ui->actionfilling->setChecked(false);
    ui->actionactionPolygon->setChecked(false);

}
void MainWindow::on_actionPolygon_triggered()
{
    slotCircle();
    ui->actionRectangle->setChecked(false);
    ui->actionLine->setChecked(false);
    ui->actionCircle->setChecked(false);
    ui->actionPencil->setChecked(false);
    ui->actionfilling->setChecked(false);
    ui->actionactionPolygon->setChecked(true);

}

void MainWindow::on_actionchooseColor_triggered()
{
    slotColor();
}

void MainWindow::on_actionfilling_triggered()
{
    slotFilling();
    ui->actionRectangle->setChecked(false);
    ui->actionLine->setChecked(false);
    ui->actionCircle->setChecked(false);
    ui->actionPencil->setChecked(false);
    ui->actionfilling->setChecked(true);
    ui->actionactionPolygon->setChecked(false);

}



void MainWindow::on_actionAdout_triggered()
{
    slotAbout();
}
