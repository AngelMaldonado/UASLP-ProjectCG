/// Libraries
#ifndef std

using namespace std;

#endif
#include <iostream>
#include <fstream> // Library to work with files
#include <sstream>
#include <ctype.h>
#include "Mesh.h" // This library includes Face.h, Vertex.h, and containers.h

/**
 * OBJFileReader class: this class allows the user to read a *.obj file and store the information from that file
 * to different data structures.
 * First, it is required to define a vector<Mesh> to be able to start reading the file, since Mesh class has as
 * attributes a list<Face> (list of faces) and a vector<Vertex> (vector of vertices), and the readFile() method
 * makes all the work to read each line of the .obj file and recognize the characters that identifies the objects (o),
 * vertices (v), and faces (f).
 **/
class OBJFileReader {
private:
    /*
     * This fstream object allows the program to search and, if it succeeded, manipulates the file
     * with I/O operations
     */
    fstream fileReader;
    // String to store the file's name
    string fileName;
    // Path of the file (if applies)
    string filePath;
public:
    // Method to read de obj file and store info in a vector of meshes
    bool readFile(string fileName, vector <Mesh> meshes) {

        // Checks the extension of the file
        if (fileName.substr(fileName.find_last_of(".") + 1) == "obj") {

            // Read the user-file
            fileReader.open(fileName, std::fstream::in | std::fstream::out);

            // If the file was successfully opened
            if (fileReader.is_open()) {

                // Local string to iterate through the file
                string lineContent;
                // Local vector of doubles to store the vertices read in file
                vector <double> dblVerticesRead;
                // Local vector of Vertices to store a face's vertices
                vector <Vertex> faceVertices;
                // Variable that stores the index of the las Vertex that was added to a mesh
                int lastVertexIndex;

                // Show in console that file was successfully opened
                cout << "**********************************************" << '\n';
                cout << "******** Successfully opened the file ********" << '\n';
                cout << "**********************************************" << "\n\n";

                // Store the file's name in fileName attribute
                this->fileName = fileName;

                // Read the file line by line
                while (getline(fileReader, lineContent)) {

                    // If the first position of the content on the line read is a comment ('#')
                    if (lineContent[0] == '#')
                        cout << "<<Found a comment (#)>>" << "\n\n" << lineContent << "\n\n";
                    else

                        // Else, read the 3D object's info
                        switch (lineContent[0]) {

                            // Object case
                            case 'o':
                                cout << "*********************************" << '\n';
                                cout << "****** Found an object (o) ******" << '\n';
                                cout << "*********************************" << "\n\n";

                                // If there is more than one mesh in file, continue the vertexIndex with last value set
                                if(meshes.size() > 0) {
                                    lastVertexIndex = meshes.back().getVertexIndex();
                                    meshes.push_back(Mesh(getMeshNameWithLine(lineContent), lastVertexIndex));
                                }
                                else {
                                    // Push a new Mesh to the Mesh vector
                                    meshes.push_back(Mesh(getMeshNameWithLine(lineContent)));
                                    lastVertexIndex = 0;
                                }

                                // Print the name from the new Mesh at Mesh vector
                                cout << ">> Object identifier: " << meshes.back().getMeshName() << '\n';
                                cout << " --- Successfully stored in vector<Mesh> ---" << "\n\n";
                                break;

                                // Vertex case
                            case 'v':
                                // Reset the dblVerticesRead
                                dblVerticesRead.clear();
                                cout << "*********************************" << '\n';
                                cout << "******* Found a vertex (v) ******" << '\n';
                                cout << "*********************************" << "\n\n";

                                // Get and push a new Vertex to the verticesRead vector
                                dblVerticesRead = getVertexCoordinatesWithLine(lineContent);

                                // Add the Vertex read to the current mesh
                                if(meshes.back().addVertex(dblVerticesRead)) {
                                    cout << "Vertex: ";
                                    meshes.back().getLastVertex().showCoordinatesFormatted();
                                    cout << "--- Successfully stored in mesh " << meshes.back().getMeshName();
                                    cout << "---" << "\n\n";
                                } else cout << "~~~ Invalid vertex ~~~" << "\n\n";
                                break;

                                // Face case
                            case 'f':
                                // Reset the faceVertices vector
                                faceVertices.clear();
                                cout << "*********************************" << '\n';
                                cout << "******** Found a face (f) *******" << '\n';
                                cout << "*********************************" << "\n\n";

                                // Get a vector of Vertex that describes the face that is reading
                                faceVertices = getFaceWithLine(lineContent, meshes.back(), lastVertexIndex);
                                // Create a new face in current mesh with vector faceVertices
                                if(meshes.back().addFace(faceVertices)) {
                                    meshes.back().getLastFace().showFaceFormatted();
                                    cout << "--- Successfully stored in mesh " << meshes.back().getMeshName();
                                    cout << "---" << "\n\n";
                                }
                                else
                                    cout << "~~~ Insufficient vertices to make a face! ~~~" << "\n\n";
                                break;
                        }
                }
                // Ask to print info stored in vector<Mesh> as the original file
                printInfoAsFile(meshes);

                // Return true when the reading finished
                return true;
            }
        } else
            cout << "******** Invalid file extension ********" << '\n';

        // If the file couldn't be read
        // Show message in console
        cout << "******** Failed to read the file ********" << '\n';
        // Return false
        return false;
    }

    // Returns a vector of Vertex objects that describe a Face in current line at reading process
    // Requires the current mesh which contains the continuity of vertices' indexes that were added
    // Requires the last vertex index that were stored in a previous mesh (if there is more than one mesh)
    vector<Vertex> getFaceWithLine(string currentFileLine, Mesh currentMesh, int lastVrtxIndexInPrevMesh) {
        if(currentFileLine[0] == 'f') {
            // Vector that contains the vertices that conforms the face
            vector<Vertex> verticesOfFace;
            // Index of the vertex at the vector of Vertex in currentMesh
            int vertexIndex;
            // Delete the f id from file
            currentFileLine[0] = ' ';
            // Variable to convert the string numbers to integer variables
            stringstream ssCurrentFileLine(currentFileLine);

            // Read all the vertices that conforms the face
            while(ssCurrentFileLine >> vertexIndex)
                verticesOfFace.push_back(currentMesh.getVertex((vertexIndex-1)-lastVrtxIndexInPrevMesh));

            return verticesOfFace;
        }
        cout << "<<No face char 'f' was found in file>>" << '\n';
        return {};
    }

    // Returns a vector with the coordinates of the vertex in current line at reading process
    vector<double> getVertexCoordinatesWithLine(string currentFileLine) {
        // Validate that currentFileLine is reading a Vertex
        if (currentFileLine[0] == 'v') {

            // Delete the v id from file
            currentFileLine[0] = ' ';
            // Vector that contains the coordinates as doubles
            vector<double> vertexCoordinates;
            // Variable to convert the string numbers to double numbers
            stringstream ssCurrentFileLine(currentFileLine);
            double x, y, z;

            // Read the coordinates from file and add them to the vector of coordinates
            ssCurrentFileLine >> x;
            vertexCoordinates.push_back(x);
            ssCurrentFileLine >> y;
            vertexCoordinates.push_back(y);
            ssCurrentFileLine >> z;
            vertexCoordinates.push_back(z);

            // Return the vector containing the coordinates
            return vertexCoordinates;
        }
        cout << "<<No vertex char 'v' was found in file>>" << '\n';
        return {};
    }

    // This method returns the object's id that is in actual line at reading process
    string getMeshNameWithLine(string currentFileLine) {
        // Validate that currentFileLine is reading an Object
        if (currentFileLine[0] == 'o') {

            // Delete the o id from file
            currentFileLine[0] = ' ';
            stringstream ssCurrentFileLine(currentFileLine);
            // Local meshName
            string meshName;

            // Read the name from file
            ssCurrentFileLine >> meshName;
            // Return the name
            return meshName;
        }
        cout << "<<No object char 'o' was found in file>>" << '\n';
        return nullptr;
    }

    // Print the read info that was stored in vector<Mesh> as the original .obj file
    void printInfoAsFile(vector<Mesh> meshes) {
        char userResponse;
        do
        {
            cout << '\n';
            cout << "Want to print the information stored in vector<Mesh> as the original .obj file? (Y/n) ";
            cin >> userResponse;
            userResponse = toupper(userResponse);
        }while(userResponse != 'N' && userResponse != 'Y');

        // Print the meshes
        for (int mesh = 0; mesh < meshes.size(); mesh++) {
            cout << "o " << meshes[mesh].getMeshName() << '\n';
            // Print the vertices of mesh
            for(Vertex vertex : meshes[mesh].getVertices()) {
                cout << "v ";
                vertex.showCoordinates();
            }
            // Print the faces of mesh
            for(Face face : meshes[mesh].getFaces()) {
                cout << "f ";
                face.showFace();
            }
        }
    }

    bool validateFile(string fileName) {

    }

    void closeFile() {
        fileReader.close();
    }
};
