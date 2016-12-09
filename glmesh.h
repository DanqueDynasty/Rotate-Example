#ifndef GLMESH_H
#define GLMESH_H

#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <vector>

#include "STCore.h"
#include "STMesh.h"

class GLMesh
{
public:
    GLMesh();
    GLMesh(std::string fileName);
    void draw();
private:
    enum{
      VERT,
      TEX,
      NORM,
      IND,
      NUM
    };

    QOpenGLVertexArrayObject vao;
    stUint m_VBO[NUM];
    stUint drawCount;
    stUint numInd;
};

#endif // GLMESH_H
