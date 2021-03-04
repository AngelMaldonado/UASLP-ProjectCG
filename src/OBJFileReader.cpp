/// Libraries
#include <iostream>
#include <fstream> // Library to work with files
#include <sstream>
#include <conio.h> // DELETE THIS WHEN NEEDED
#include "../include/Mesh.h" // This library includes Face.h, Vertex.h, and containers.h

using namespace std;

class OBJFileReader {
private:
    /*
     * This fstream object allows the program to search and, if it succeeded, manipulates the file
     * with I/O operations
     */
    fstream fileReader;
    // String to store the file's name
    string fileName;
public:
    // Method to read de obj file and store info in a vector of meshes
    bool readFile(string fileName, vector <Mesh> meshes) {

        if (fileName.substr(fileName.find_last_of(".") + 1) == "obj") {

            // Read the user-file
            fileReader.open(fileName, std::fstream::in | std::fstream::out);

            // If the file was successfully opened
            if (fileReader.is_open()) {

                // Local string to iterate through the file
                string lineContent;
                // Local vector of doubles to store the vertices read in file
                vector <double> dblVerticesRead;

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

                                // Push a mew Mesh to the Mesh vector
                                meshes.push_back(Mesh(getMeshNameWithLine(lineContent)));

                                // Print the name from the new Mesh at Mesh vector
                                cout << ">> Object identifier: " << meshes.back().getMeshName();
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

                                // Add the Vertex read to the mesh
                                meshes.back().addVertex(dblVerticesRead);
                                break;

                                // Face case
                            case 'f':
                                cout << "<<Found a face (f)>>" << '\n';
                                getFaceWithLine(lineContent, meshes.back());
                                break;
                        }
                }
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
    vector<Vertex> getFaceWithLine(string currentFileLine, Mesh currentMesh) {
        // Delete the f id from file
        currentFileLine[0] = ' ';
        // Variable to convert the string numbers to integer variables
        stringstream ssCurrentFileLine(currentFileLine);
        // Vector that contains the vertices that conforms the face
        vector<Vertex> verticesOfFace;
        // Index of the vertex at the vector of Vertex in currentMesh
        int vertexIndex;

        // Read all the vertices that conforms the face
        while(ssCurrentFileLine >> vertexIndex)
            verticesOfFace.push_back(currentMesh.getVertex(vertexIndex));

        for(Vertex vertex : verticesOfFace)
            vertex.showCoordinates();
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
        cout << "<<Error with coordinates>>" << '\n';
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
        cout << "<<There is no mesh name to read>>" << '\n';
        return nullptr;
    }

    void closeFile() {
        fileReader.close();
    }
};

int main() {
    OBJFileReader fileReader;
    vector <Mesh> meshes;

    fileReader.readFile("test.obj", meshes);

    getch();
    return 0;
}
