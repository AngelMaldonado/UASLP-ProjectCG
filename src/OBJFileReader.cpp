/// Libraries
#include <iostream>
#include <fstream> // Library to work with files
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
    bool readFile(string fileName) {

        if (fileName.substr(fileName.find_last_of(".") + 1) == "obj") {
            // Read the user-file
            fileReader.open(fileName, std::fstream::in | std::fstream::out);

            // If the file was successfully opened
            if (fileReader.is_open()) {
                // Create a local string to iterate through the file
                string content;
                // Show in console that file was successfully opened
                cout << "******** Successfully opened the file ********" << "\n";
                // Store the file's name in fileName attribute
                this->fileName = fileName;

                // Read the file line by line
                while (getline(fileReader, content)) {

                    // If the first position of the content on the line read is a comment ('#')
                    if (content[0] == '#')
                        cout << "<<Found a comment (#)>>" << "\n";
                    else
                        // Else, read the 3D object's info
                        switch (content[0]) {
                            // Object case
                            case 'o':
                                cout << "<<Found an object (o)>>" << "\n";
                                break;
                                // Vertex case
                            case 'v':
                                cout << "<<Found a vertex (v)>>" << "\n";
                                break;
                                // Face case
                            case 'f':
                                cout << "<<Found a face (f)>>" << "\n";
                                break;
                        }
                }
                // Return true when the reading finished
                return true;
            }
        } else
            cout << "******** Invalid file extension ********" << "\n";

        // If the file couldn't be read
        // Show message in console
        cout << "******** Failed to read the file ********" << "\n";
        // Return false
        return false;
    }

    void closeFile() {
        fileReader.close();
    }
};

int main() {
    OBJFileReader fileReader;
    vector <Mesh> meshes;

    //fileReader.readFile("test.txt");

    getch();
    return 0;
}
