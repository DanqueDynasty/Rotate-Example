#include "viewport.h"

Viewport::Viewport(QWidget *parent) : QOpenGLWidget(parent)
{
    setMinimumSize(640, 480);
    useQuaternion = false;
    transform = new Transform;
    initializeGL();
}

void Viewport::toggleRotationMode(bool value)
{
    useQuaternion = !value;
}

void Viewport::updateX_Axis(int x)
{
    if(useQuaternion)transform->setRotationMode(Transform::Local);
    else transform->setRotationMode(Transform::Local);
    transform->setRotateX(x);
    emit modelUpdated(transform->getModel());
}

void Viewport::updateY_Axis(int y)
{
    if(useQuaternion)transform->setRotationMode(Transform::Local);
    else transform->setRotationMode(Transform::Local);
    transform->setRotateY(y);
    emit modelUpdated(transform->getModel());
}

void Viewport::updateZ_Axis(int z){
    if(useQuaternion)transform->setRotationMode(Transform::Local);
    else transform->setRotationMode(Transform::Local);
    transform->setRotateZ(z);
    emit modelUpdated(transform->getModel());
}

void Viewport::initializeGL()
{

}

void Viewport::resizeGL(int w, int h)
{
    auto f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, w, h);
}

void Viewport::paintGL()
{
    auto f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(0, 0, 0.31, 1);
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
