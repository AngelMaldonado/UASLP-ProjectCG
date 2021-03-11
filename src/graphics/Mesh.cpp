//
// Created by Angel Maldonado on 3/3/2021.
//
#include "../../include/geometry.h"

Mesh::Mesh(string name, int lastIndex) {
    vertexIndex = lastIndex;
    this->name = name;
}

Mesh::Mesh(string name) {
    vertexIndex = 0;
    this->name = name;
}

bool Mesh::addVertex(vector<double> coordinates) {
    if (!coordinates.empty()) {
        vertices.push_back(Vertex(coordinates[0],       // x
                                    coordinates[1],     // y
                                    coordinates[2],     // z
                                    vertexIndex++));
        return true;
    }
    return false;
}

bool Mesh::addFace(vector<Vertex> vertices) {
    // Validate the amount of vertices to make a face
    if (vertices.size() >= 3) {
        // Store the face in the list of Face's objects
        faces.push_back(Face(vertices));
        return true;
    } else {
        return false;
    }
}

Face Mesh::getFace(int index) {
    return faces.at(index);
}

vector<Face> Mesh::getFaces() {
    return faces;
}

Face Mesh::getLastFace() {
    return faces.back();
}

vector<Vertex> Mesh::getVertices() {
    return vertices;
}

Vertex Mesh::getLastVertex() {
    return vertices.back();
}

Vertex Mesh::getVertex(int vertexIndex) {
    return vertices.at(vertexIndex);
}

string Mesh::getMeshName() {
    return name;
}

int Mesh::getVertexIndex() {
    return vertexIndex;
}
