//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../include/objreader.h"

int main(int argc, char* argv[]) {
    OBJFileReader fileReader;
    vector <Mesh> meshes;
    string fileName;

    cin >> fileName;

    fileReader.readFile(fileName, meshes);
    return 0;
}

