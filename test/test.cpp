//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../include/objreader.h"
#include "../include/glinterface.h"

vector<Mesh> meshes;

void displayMesh() {
    // Local array of primitive coorinates of vertices (x, y, z)
    double* vertices;

    // Clear all pixels
    glClear (GL_COLOR_BUFFER_BIT);
    // Define color
    glColor3f (1.0, 1.0, 1.0);
    
    // For each stored mesh in vector<Mesh>
    for(Mesh mesh : meshes)
    {
        // For each Face that mesh has
        for (Face face : mesh.getFaces()) 
        {
            // Initialize the wirefrime drawing
            glBegin(GL_LINE_LOOP);
            // For each Vertex that the face has
            for(Vertex vertex : face.getVertices())
            {
                // Store the coordinates in the local array of doubles
                vertices = vertex.getCoordinates();
                // Draw the vertex
                glVertex3f(vertices[0], vertices[1], vertices[2]);
            }
            glEnd();    
        }
    }
    // Start processing buffered OpenGL routines 
    glFlush ();
}

int main(int argc, char* argv[]) {
    // Given
    OBJFileReader fileReader;
    GLInterface glInterface = GLInterface();
    meshes = fileReader.readFile("models/monkey.obj", 'n');
    
    // When
    glInterface.initGLWindow(argc, argv, 300, 300, 100, 100);
    glInterface.initView();
    glInterface.setDisplayFunction(displayMesh);

    // Then
    glInterface.startGLloop();

    return 0;
}

