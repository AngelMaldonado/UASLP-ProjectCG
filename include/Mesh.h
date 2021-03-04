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
    vector <Vertex> vertices;
public:
    Mesh(string name) {
        this->name = name;
    }

    bool addVertex(vector<double> coordinates) {
        if (!coordinates.empty()) {
            vertices.push_back(Vertex(coordinates[0],   // x
                                          coordinates[1],   // y
                                          coordinates[2])); // z
            cout << ">> Vertex --- Successfully added to " << name << " --- ";
            vertices.back().showCoordinates();
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
            cout << "~~~ Insufficient vertices to make a face! ~~~" << '\n';
            return false;
        }
    }

    void showVertices() {
        if (!vertices.empty()) {
            for(Vertex vertex : vertices)
                vertex.showCoordinates();
        }
    }

    Vertex getVertex(int vertexIndex) {
        return vertices.at(vertexIndex);
    }

    string getMeshName() {
        return name;
    }
};
