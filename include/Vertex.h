//
// Created by Angel Maldonado on 3/3/2021.
//
#pragma once
#ifndef CONTAINERS_H

#include "containers.h"

#endif

/**
 * >> Vertex: is a point where two or more curves, lines, or edges meet.
 *
 * Vertex class: that contains x, y and z coordinates which describes the
 * position of the Vertex in the space.
 **/

class Vertex {
private:
    // Index to identify the vertex
    int index;
    // Coordinate in x.
    double x;
    // Coordinate in y.
    double y;
    // Coordinate in z.
    double z;
public:
    // Constructor for Vertex with user-defined coordinates.
    Vertex(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        index = -1;
    }

    // Constructor for Vertex with user-defined coordinates and index/id
    Vertex(double x, double y, double z, int index) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->index = index;
    }

    void showCoordinatesFormatted() {
        cout << fixed << index << " (" << x << ", " << y << ", " << z << ')' << "\n";
    }

    void showCoordinates() {
        cout << fixed << x << ' ' << y << ' ' << z << '\n';
    }

    int getIndex() {
        return index;
    }
};

