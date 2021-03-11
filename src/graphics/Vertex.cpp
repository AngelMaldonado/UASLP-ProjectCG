//
// Created by Angel Maldonado on 3/3/2021.
//
#include "../../include/geometry.h"

Vertex::Vertex(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vertex::Vertex(double x, double y, double z, int index) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->index = index;
}

void Vertex::showCoordinatesFormatted() {
    cout << fixed << index << " (" << x << ", " << y << ", " << z << ')' << "\n";
}

void Vertex::showCoordinates() {
    cout << fixed << x << ' ' << y << ' ' << z << '\n';
}

int Vertex::getIndex() {
    return index;
}

