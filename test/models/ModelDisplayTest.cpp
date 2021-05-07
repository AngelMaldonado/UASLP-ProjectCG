//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../../include/objreader.h"
#include "../../include/glinterface.h"

class Drawable : public GLInterface {
    public:
        vector<Mesh> object;
        virtual void display();
};

void Drawable::display() {
    // Local array of primitive coorinates of vertices (x, y, z)
    double* vertices;

    // Clear all pixels
    glClear (GL_COLOR_BUFFER_BIT);
    // Define color
    glColor3f (1.0, 1.0, 1.0);
    
    // For each stored mesh in vector<Mesh>
    for(Mesh mesh : object)
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

void givenModel_whenCertainViewAndCertainDisplayFunction_thenModelDisplays(int argc, char* argv[]) {
    // Given
    OBJFileReader fileReader;
    Drawable *drawableObject = new Drawable();
    GLInterface *glInterface = new GLInterface();
    drawableObject->object = fileReader.readFile("objs/test/monkey.obj", 'n');

    // When
    glInterface->setInstance(drawableObject);
    glInterface->setView3D(GL_PROJECTION, -3, 3, -3, 3, -3, 3, 180, 0, 1, 0);

    // Then
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    givenModel_whenCertainViewAndCertainDisplayFunction_thenModelDisplays(argc, argv);

    return 0;
}
