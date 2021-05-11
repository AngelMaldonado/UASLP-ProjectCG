//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../../include/objreader.h"
#include "../../include/glinterface.h"
#include "../../include/trajectories.h"

class Drawable : public TrajectoryHandler {
    public:
        vector<Mesh> object;
        Coordinates origin;

        virtual void display();
        virtual void run();
        
        Drawable(float originX, float originY, float originZ) {
            origin.x = originX;
            origin.y = originY;
            origin.z = originZ;

            setBresenhamValues(0, 0, 0, 4, 1, 1, 1, 1, GL_POINTS);
            setHermiteValues(0, 0, 5, 4, 0, 10, 5, -10, 0.1, 1, 1, 1, 3, GL_POINTS);
            time = 1000;
        }
        void drawObject() {
            // Local array of primitive coorinates of vertices (x, y, z)
            double* vertices;

            // Define color
            glColor3f (1.0, 1.0, 1.0);
            
            // For each stored mesh in vector<Mesh>
            for(Mesh mesh : object)
            {
                // For each Face that mesh has
                for (Face face : mesh.getFaces()) 
                {
                    // Initialize the wirefrime drawing
                    glBegin(GL_POINTS);
                    // For each Vertex that the face has
                    for(int vertex : face.getVertices())
                    {
                        // Store the coordinates in the local array of doubles
                        vertices = mesh.getFaceVertex(vertex);
                        cout << vertices[0] << ' ' << vertices[1] << ' ' << vertices[2] << endl;
                        // Draw the vertex
                        glVertex3f(vertices[0], vertices[1], vertices[2]);
                    }
                    glEnd();     
                }
            }
        }
};

void Drawable::display() {
    drawObject();
    //bresenhamDrawLine();
    //hermiteDrawCurve();

    glColor3f(0, 1, 0);
    glBegin(GL_POINTS);
        glVertex3i(round(origin.x), round(origin.y), round(origin.z));
    glEnd();
}

void Drawable::run() {
    //hermiteAnimateObject(object, origin);
    //bresenhamAnimateObject(object, origin);
}

void givenModel_whenCertainViewAndCertainDisplayFunction_thenModelDisplays(int argc, char* argv[]) {
    // Given
    OBJFileReader fileReader;
    Drawable *drawableObject = new Drawable(0, 0, 0);
    GLInterface *glInterface = new GLInterface();
    vector<Mesh> object = fileReader.readFile("objs/test/cube.obj", 'n');
    drawableObject->object = object;

    // When
    glInterface->setInstance(drawableObject);
    glInterface->setView3D(GL_PROJECTION, -3, 3, -3, 3, -30, 30, 90, 0, 0, 0);

    // Then
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    givenModel_whenCertainViewAndCertainDisplayFunction_thenModelDisplays(argc, argv);

    return 0;
}
