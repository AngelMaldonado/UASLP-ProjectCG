//
// Created by Angel Maldonado on 3/4/2021.
//

//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../include/OBJFileReader.h"

int main(int argc, char* argv[]) {
    OBJFileReader fileReader;
    vector <Mesh> meshes;
    string fileName = argv[0];

    fileReader.readFile("models/cube.obj", meshes);
    return 0;
}

