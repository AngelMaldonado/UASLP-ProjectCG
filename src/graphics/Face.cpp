//
// Created by Angel Maldonado on 3/3/2021.
//
#ifndef std

using namespace std;

#endif
#include "../../include/geometry.h"

Face::Face(vector<Vertex> vertices) {
    this->vertices = vertices;
}

void Face::showsFaceFormatted() {
    cout << "Face composed of: \n";
        for(Vertex vertex : vertices)
            vertex.showCoordinatesFormatted();
        cout << '\n';
}

void Face::showFace() {
    for(Vertex vertex : vertices) {
            cout << vertex.getIndex() << ' ';
        } cout << '\n';
}
