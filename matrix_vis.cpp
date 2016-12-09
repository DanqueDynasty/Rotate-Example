#include "matrix_vis.h"

Matrix_Vis::Matrix_Vis(QWidget *parent) : QWidget(parent)
{
    initGui();
}

void Matrix_Vis::updateData(const Matrix4f matrix)
{
    auto m = matrix.m;
    m11->setText(QString::number(m[0][0]));
    m12->setText(QString::number(m[0][1]));
    m13->setText(QString::number(m[0][2]));
    m14->setText(QString::number(m[0][3]));

    m21->setText(QString::number(m[1][0]));
    m22->setText(QString::number(m[1][1]));
    m23->setText(QString::number(m[1][2]));
    m24->setText(QString::number(m[1][3]));

    m31->setText(QString::number(m[2][0]));
    m32->setText(QString::number(m[2][1]));
    m33->setText(QString::number(m[2][2]));
    m34->setText(QString::number(m[2][3]));

    m41->setText(QString::number(m[3][0]));
    m42->setText(QString::number(m[3][1]));
    m43->setText(QString::number(m[3][2]));
    m44->setText(QString::number(m[3][3]));
}

void Matrix_Vis::initGui()
{
    auto centralLayout = new QGridLayout;

    m11 = new QLabel("1.0", this);
    m12 = new QLabel("0.0", this);
    m13 = new QLabel("0.0", this);
    m14 = new QLabel("0.0", this);
    centralLayout->addWidget(new QLabel("["), 0, 0);
    centralLayout->addWidget(m11, 0, 1);
    centralLayout->addWidget(m12, 0, 2);
    centralLayout->addWidget(m13, 0, 3);
    centralLayout->addWidget(m14, 0, 4);
    centralLayout->addWidget(new QLabel("]"), 0, 5);

    m21 = new QLabel("0.0", this);
    m22 = new QLabel("1.0", this);
    m23 = new QLabel("0.0", this);
    m24 = new QLabel("0.0", this);
    centralLayout->addWidget(new QLabel("["), 1, 0);
    centralLayout->addWidget(m21, 1, 1);
    centralLayout->addWidget(m22, 1, 2);
    centralLayout->addWidget(m23, 1, 3);
    centralLayout->addWidget(m24, 1, 4);
    centralLayout->addWidget(new QLabel("]"), 1, 5);

    m31 = new QLabel("0.0", this);
    m32 = new QLabel("0.0", this);
    m33 = new QLabel("1.0", this);
    m34 = new QLabel("0.0", this);
    centralLayout->addWidget(new QLabel("["), 2, 0);
    centralLayout->addWidget(m31, 2, 1);
    centralLayout->addWidget(m32, 2, 2);
    centralLayout->addWidget(m33, 2, 3);
    centralLayout->addWidget(m34, 2, 4);
    centralLayout->addWidget(new QLabel("]"), 2, 5);

    m41 = new QLabel("0.0", this);
    m42 = new QLabel("0.0", this);
    m43 = new QLabel("0.0", this);
    m44 = new QLabel("1.0", this);
    centralLayout->addWidget(new QLabel("["), 3, 0);
    centralLayout->addWidget(m41, 3, 1);
    centralLayout->addWidget(m42, 3, 2);
    centralLayout->addWidget(m43, 3, 3);
    centralLayout->addWidget(m44, 3, 4);
    centralLayout->addWidget(new QLabel("]"), 3, 5);

    setLayout(centralLayout);
}
