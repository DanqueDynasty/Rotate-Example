#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QSplitter>
#include <QPushButton>

#include "viewport.h"
#include "matrix_vis.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void updateX(int);
    void updateY(int);
    void updateZ(int);
    void reset();
private:
    void initGUI();

    QRadioButton* defaultRotChkBx;
    QRadioButton* quatRotChkBx;

    QLabel* x_valueDisp;
    QLabel* y_valueDisp;
    QLabel* z_valueDisp;

    QSlider* xSlider;
    QSlider* ySlider;
    QSlider* zSlider;

    Viewport* viewport;
    Matrix_Vis* vis;
};

#endif // MAINWINDOW_H
