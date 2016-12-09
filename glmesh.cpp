#include "glmesh.h"

GLMesh::GLMesh()
{

}

GLMesh::GLMesh(std::string fileName)
{
    std::vector<Vector3<stReal>> vertex;
    std::vector<Vector2<stReal>> texCoord;
    std::vector<Vector3<stReal>> normal;
    std::vector<int> index;

    auto f = QOpenGLContext::currentContext()->functions();

    int numVert = 0;

    auto tMesh = new OBJMesh(fileName);
    numVert = tMesh->getVerticiesSize();
    drawCount = tMesh->getIndiciesSize();
    vertex.reserve(numVert);
    texCoord.reserve(numVert);
    normal.reserve(numVert);

    for(unsigned int i = 0; i < numVert; i++){
        vertex.push_back(*tMesh->verticies[i].getVertex());
        texCoord.push_back(*tMesh->verticies[i].getTexCoord());
        normal.push_back(*tMesh->verticies[i].getNormal());
    }
    index = tMesh->indicies;
    delete tMesh;

    vao.create();
    vao.bind();
    f->glGenBuffers(NUM, m_VBO);

    f->glBindBuffer(GL_ARRAY_BUFFER, m_VBO[VERT]);
    f->glBufferData(GL_ARRAY_BUFFER, numVert * sizeof(vertex[0]), &vertex[0], GL_STATIC_DRAW);
    f->glEnableVertexAttribArray(0);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    f->glBindBuffer(GL_ARRAY_BUFFER, m_VBO[TEX]);
    f->glBufferData(GL_ARRAY_BUFFER, numVert * sizeof(texCoord[0]), &texCoord[0], GL_STATIC_DRAW);
    f->glEnableVertexAttribArray(2);
    f->glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    f->glBindBuffer(GL_ARRAY_BUFFER, m_VBO[VERT]);
    f->glBufferData(GL_ARRAY_BUFFER, numVert * sizeof(normal[0]), &normal[0], GL_STATIC_DRAW);
    f->glEnableVertexAttribArray(2);
    f->glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, 0);


    f->glBindBuffer(GL_ARRAY_BUFFER, m_VBO[IND]);
    f->glBufferData(GL_ELEMENT_ARRAY_BUFFER, drawCount*sizeof(index[0]), &index[0], GL_STATIC_DRAW);
    vao.release();
}

void GLMesh::draw(){
    auto f = QOpenGLContext::currentContext()->functions();
    vao.bind();
    f->glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
    vao.release();
}
