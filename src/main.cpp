//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../include/objreader.h"

int main() {
    OBJFileReader fileReader;
    vector <Mesh> meshes;

    fileReader.readFile("../models/sphere.obj", meshes);
    return 0;
}

