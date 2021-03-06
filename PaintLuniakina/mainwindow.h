#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QColorDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool getDrawEnable();
    bool getRectangleEnable();
    bool getCircleEnable();
    bool getLineEnable();
    bool getPolygonEnable();
    bool getFillingEnable();
    QColor getColor();
    int getSliderValue();



public slots :
 void slotDraw();
 void slotRectangle();
 void slotCircle();
 void slotLine();
 void slotPolygon();

 void slotFilling();
 void slotColor();
 void slotSlider(int x);
 void slotAbout();


private slots:
 void on_actionRectangle_triggered();
 void on_actionLine_triggered();
 void on_actionPencil_triggered();
 void on_actionCircle_triggered();
 void on_actionPolygon_triggered();

 void on_actionchooseColor_triggered();
 void on_actionfilling_triggered();
 void on_actionAdout_triggered();

private:
    Ui::MainWindow *ui;
    bool drawEnable;
    bool rectangleEnable;
    bool circleEnable;
    bool lineEnable;
    bool polygonEnable;

    bool fillingEnable;
    int sliderValue;
    QColorDialog *colorDialog;
    QColor color;

};

#endif // MAINWINDOW_H
