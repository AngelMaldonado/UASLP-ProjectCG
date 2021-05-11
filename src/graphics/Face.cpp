//
// Created by Angel Maldonado on 3/3/2021.
//
#ifndef std

using namespace std;

#endif
#include "../../include/geometry.h"

Face::Face(vector<int> vertices) {
    //copy(vertices.begin(), vertices.end(), back_inserter(this->vertices));
    for(int vertex : vertices)
        this->vertices.push_back(vertex);
}

void Face::showsFaceFormatted() {
    cout << "Face composed of: \n";
    for(int vertex : vertices)
        cout << "Vertex #" << vertex << ' ';
    cout << '\n';
}

void Face::showFace() {
    for(int vertex : vertices) {
            cout << vertex << ' ';
        } cout << '\n';
}

vector<int> Face::getVertices() {
    return vertices;
}
