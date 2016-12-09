#ifndef MATRIX_VIS_H
#define MATRIX_VIS_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

#include "Matrix.h"

class Matrix_Vis : public QWidget
{
    Q_OBJECT
public:
    Matrix_Vis(QWidget* parent = 0);
public slots:
    void updateData(const Matrix4f);
private:
    void initGui();
    QLabel* m11;
    QLabel* m12;
    QLabel* m13;
    QLabel* m14;

    QLabel* m21;
    QLabel* m22;
    QLabel* m23;
    QLabel* m24;

    QLabel* m31;
    QLabel* m32;
    QLabel* m33;
    QLabel* m34;

    QLabel* m41;
    QLabel* m42;
    QLabel* m43;
    QLabel* m44;
};

#endif // MATRIX_VIS_H
