#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T09:50:36
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RotationExample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    viewport.cpp \
    matrix_vis.cpp \
    glmesh.cpp \
    STMesh.cpp

HEADERS  += mainwindow.h \
    viewport.h \
    matrix_vis.h \
    Euler.h \
    Matrix.h \
    Quaternion.h \
    STCore.h \
    Transform.h \
    Vector.h \
    glmesh.h \
    STMesh.h \
    Vertex.h
