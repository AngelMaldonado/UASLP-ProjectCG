//
// Created by Angel Maldonado on 3/3/2021.
//
#ifndef std

using namespace std;

#endif
#include "../../include/geometry.h"

Face::Face(vector <int> verticesIndices, vector<Vertex> faceVertices) {
    for(int vertex = 0; vertex < (int)faceVertices.size(); vertex++) {
        this->verticesIndices.push_back(verticesIndices[vertex]);
        vertices.push_back(faceVertices[vertex]);
    }
}

void Face::showFaceFormatted() {
    cout << "Face composed of: \n";
    for(int vertex : verticesIndices)
        cout << "Vertex #" << vertex << ' ';
    cout << '\n';
    for(Vertex vertex : vertices)
        vertex.showCoordinatesFormatted();
}

void Face::showFace() {
    for(int vertex : verticesIndices) {
            cout << vertex << ' ';
        } cout << '\n';
}

vector<int> Face::getVerticesIndices() {
    return verticesIndices;
}

vector<Vertex> &Face::getVertices() {
    return vertices;
}

void Face::computeNormalVector() {
    Vertex V1 = this->vertices.at(0);
    Vertex V2 = this->vertices.at(1);
    Vertex V3 = this->vertices.at(2);

    Vertex Vi = Vertex(V2.getX() - V1.getX(), V2.getY() - V1.getY(), V2.getZ() - V1.getZ(), -1);
    Vertex Vj = Vertex(V3.getX() - V1.getX(), V3.getY() - V1.getY(), V3.getZ() - V1.getZ(), -1);

    normal.setX((Vi.getY()*Vj.getZ() - Vi.getZ()*Vj.getY()));
    normal.setY((Vi.getZ()*Vj.getX() - Vi.getX()*Vj.getZ()));
    normal.setZ((Vi.getX()*Vj.getY() - Vi.getY()*Vj.getX()));
}

Vertex Face::getNormalVector() {
    return normal;
}
