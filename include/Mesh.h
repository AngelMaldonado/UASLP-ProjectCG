//
// Created by Angel Maldonado on 3/3/2021.
//
#pragma once
#ifndef CONTAINERS_H

#include "containers.h"

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
    list <Face> faces;
public:
    bool addFace(list<Face> )
    bool addFace(vector <Vertex> vertices) {
        // Validate the amount of vertices to make a face
        if (vertex.size() >= 3) {

        } else {
            cout << "~~~ Insufficient vertices to make a face! ~~~" << "\n";
            return false;
        }
    }
};
