//
// Created by Angel Maldonado on 3/3/2021.
//
#pragma once
#ifndef CONTAINERS_H

#include "containers.h"

#endif

#ifndef std

using namespace std;

#endif

#include "Face.h"

/**
 * >> Mesh: a polygon mesh is a collection of vertices, edges and faces that defines the shape of a
 * >>       polyhedral object.
 *
 * Mesh class: it has only a list of Face objects, since Face class has a vector of Vertex objects
 * it's not necessary to make another list of those in this class. Mesh can interact with Vertex's and
 * Face's objects through their methods.
 **/

class Mesh {
private:
    string name;
    list <Face> faces;
    int vertexIndex;
    vector <Vertex> vertices;
public:
    // If there is more than one Mesh, last index of past Mesh is required
    Mesh(string name, int lastIndex) {
        vertexIndex = lastIndex;
        this->name = name;
    }

    // New mesh
    Mesh(string name) {
        vertexIndex = 0;
        this->name = name;
    }

    bool addVertex(vector<double> coordinates) {
        if (!coordinates.empty()) {
            vertices.push_back(Vertex(coordinates[0],   // x
                                      coordinates[1],   // y
                                      coordinates[2],   // z
                                      ++vertexIndex));
            return true;
        }
        return false;
    }

    bool addFace(vector <Vertex> vertices) {
        // Validate the amount of vertices to make a face
        if (vertices.size() >= 3) {
            // Store the face in the list of Face's objects
            faces.push_back(Face(vertices));
            return true;
        } else {
            return false;
        }
    }

    list<Face> getFaces() {
        return faces;
    }

    Face getLastFace() {
        return faces.back();
    }

    vector<Vertex> getVertices() {
        return vertices;
    }

    Vertex getLastVertex() {
        return vertices.back();
    }

    Vertex getVertex(int vertexIndex) {
        return vertices.at(vertexIndex);
    }

    string getMeshName() {
        return name;
    }

    int getVertexIndex() {
        return vertexIndex;
    }
};
