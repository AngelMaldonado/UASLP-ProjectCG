//
// Created by Angel Maldonado on 3/3/2021.
//
#pragma once
#ifndef CONTAINERS_H

#include "containers.h"

#endif

#include "Vertex.h"

/**
 * >> Face: is a flat surface that forms part of the boundary of a solid object (mesh).
 *
 * Face class: contains a vector of Vertex objects which describes each vertex of the
 * face, then the position of the face in space.
 **/

class Face {
private:
    // Vector of Vertex objects
    vector <Vertex> vertices;
public:
    Face(vector <Vertex> vertices) {
        this->vertices = vertices;
    }
};

