#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QOpenGLWidget>
#include <QtOpenGL>

#include "Transform.h"

class Viewport : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    Viewport(QWidget* parent = 0);
signals:
    void modelUpdated(const Matrix4f);
public slots:
    void toggleRotationMode(bool);
    void updateX_Axis(int);
    void updateY_Axis(int);
    void updateZ_Axis(int);
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
private:
    QOpenGLContext* context;
    bool            useQuaternion;
    Transform*      transform;
};

#endif // VIEWPORT_H
