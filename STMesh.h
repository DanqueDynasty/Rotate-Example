#ifndef WAHOO_STMESH_H
#define WAHOO_STMESH_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Vector.h"
#include "Vertex.h"

#include "STCore.h"

struct STMesh_Structure{
    std::vector<int> m_indices;
    std::vector<Vertex> m_vertices;

    Vertex* getVertices(){ return &m_vertices[0]; }
    int* getIndicies(){ return &m_indices[0]; }

    int getVertexSize()const { return (int)m_vertices.size(); }
    int getIndexSize() const { return (int)m_indices.size(); }
};

class OBJMesh{
public:
    OBJMesh();
    OBJMesh(const std::string& filename);
    OBJMesh(const std::string& fileName, Vector2<int> lineBounds);
    OBJMesh(const std::string& fileName, Vector2<int> lineBounds, Vector3<int> maxSize);
    static bool Validate(const std::string& fileName, std::vector<std::string> *tags, std::vector<STMesh_Structure> *dataMesh);
    static bool Validate(const std::string& fileName, bool* errFlag, std::vector<std::string> *tags, std::vector<STMesh_Structure> *dataMesh);
    virtual ~OBJMesh();

    int getVerticiesSize(){ return (int)verticies.size(); }
    int getIndiciesSize(){ return (int)indicies.size(); }

    Vertex* getVertices(){
        return &verticies[0];
    }

    int* getIndicies(){
        int* ret = &indicies[0];
        return ret;
    };

    std::vector<int> indicies;
    std::vector<Vertex> verticies;
private:

    std::vector<Vector3<float>> _vertex;
    std::vector<Vector2<float>> _texCoord;
    std::vector<Vector3<float>> _normal;
    std::vector<int> _index;
};


class STMesh {
public:
    enum Type{
        OBJ = 0,
        GEX = 1,
        FBX = 2
    };

    enum DrawMode{
        LINES = 0,
        TRIANGLES = 1,
        LINE_LOOP = 2,
    };
    static bool Validate(const std::string& fileName, int* typeFlag, std::vector<std::string>* tags, std::vector<STMesh_Structure>* meshes);
    static bool Validate(const std::string& fileName, bool* errFlag, std::vector<std::string>* tags, std::vector<STMesh_Structure>* meshes);
    STMesh(){}
    STMesh(const std::string& fileName, int type){}
    STMesh(float vert[], int vSize, float tex[], int tSize, int ind[], int indSize){ }
    ~STMesh(){  }

    virtual void draw(){}
    virtual void draw(int drawMode){  }

    std::vector<Vector3<float>> new_GenTangent(std::vector<Vector3<float>>& normal){
        std::vector<Vector3<float>> ret;
        Vector3<float> Z(0.0f, 0.0f, 1.0f);
        Vector3<float> Y(0.0f, 1.0f, 0.0f);
        for(unsigned int i = 0; i < normal.size(); i++){
            Vector3<float> c1 = normal.at(i);
            c1 = c1.cross(Z).normalize();
            Vector3<float> c2 = normal.at(i);
            c2 = c2.cross(Y).normalize();
            if(c1.getLength() > c2.getLength() ){
                ret.push_back(c1);
            }else{
                ret.push_back(c2);
            }
        }
        return ret;
    }

    std::vector<Vector3<float>>genTangent(std::vector<Vector3<float>>& vert, std::vector<Vector2<float>>& tex){
        std::vector<Vector3<float>> ret;

        for(unsigned int i = 0, S = vert.size(); i < S; i+= 3){
            Vector3<float> v0 = vert[i];
            Vector3<float> v1 = vert[i+1];
            Vector3<float> v2 = vert[i+2];

            Vector2<float> uv0 = tex[i+0];
            Vector2<float> uv1 = tex[i+1];
            Vector2<float> uv2 = tex[i+2];

            Vector3<float> dP1 = v1 - v0;
            Vector3<float> dP2 = v2 - v0;

            Vector2<float> dUV1 = uv1 - uv0;
            Vector2<float> dUV2 = uv2 - uv0;

            float r = 1.0f / (dUV1.getX() * dUV2.getY() - dUV1.getY() * dUV2.getX());
            Vector3<float> a = (dP1 * dUV2.getY()) * r;
            Vector3<float> b = (dP2 * dUV1.getY()) * r;
            Vector3<float> tangent = a - b;

            ret.push_back(tangent);
            ret.push_back(tangent);
            ret.push_back(tangent);
        }

        return ret;
    }

    std::vector<Vector3<float>>genBiTangent(std::vector<Vector3<float>>& vert, std::vector<Vector2<float>>& tex){
        std::vector<Vector3<float>> ret;

        for(unsigned int i = 0, S = vert.size(); i < S; i+= 3){
            Vector3<float> v0 = vert[i];
            Vector3<float> v1 = vert[i+1];
            Vector3<float> v2 = vert[i+2];

            Vector2<float> uv0 = tex[i+0];
            Vector2<float> uv1 = tex[i+1];
            Vector2<float> uv2 = tex[i+2];

            Vector3<float> dP1 = v1 - v0;
            Vector3<float> dP2 = v2 - v0;

            Vector2<float> dUV1 = uv1 - uv0;
            Vector2<float> dUV2 = uv2 - uv0;

            float r = 1.0f / (dUV1.getX() * dUV2.getY() - dUV1.getY() * dUV2.getX());
            Vector3<float> a = (dP1 * dUV2.getY()) * r;
            Vector3<float> b = (dP2 * dUV1.getY()) * r;
            Vector3<float> tangent = b - a;

            ret.push_back(tangent);
            ret.push_back(tangent);
            ret.push_back(tangent);
        }

        return ret;
    }
};


#endif //WAHOO_STMESH_H
