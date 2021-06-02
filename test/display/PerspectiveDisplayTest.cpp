//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../../include/objreader.h"
#include "../../include/glinterface.h"
#include "../../include/transformations.h"

class Drawable : public TrajectoryHandler {
    public:
        vector<Mesh> object;
        Coordinates origin;

        virtual void display();
        virtual void run();
        
        Drawable() {
            origin.x = 0;
            origin.y = 0;
            origin.z = 0;
        }

        void setOrigin(float x, float y, float z) {
            origin.x = x, origin.y = y, origin.z = z;
            TransformationsHandler::translateObject(object, x, y, z);
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
                    glBegin(GL_LINE_LOOP);
                    for(int vertex : face.getVertices())
                    {
                        vertices = mesh.getVertex(vertex).getCoordinates();
                        glVertex3f(vertices[0], vertices[1], vertices[2]);
                    }
                    glEnd();
                }
            }
        }
};

void Drawable::display() {
    drawObject();
    //hermiteDrawCurve();

    glColor3f(0, 1, 0);
    glBegin(GL_POINTS);
        glVertex3i(round(origin.x), round(origin.y), round(origin.z));
    glEnd();
}

void Drawable::run() {
    //hermiteAnimateObject(object, origin);
    TransformationsHandler::rotateObject(object, origin, 0.1, 0, 0);
}

void givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(int argc, char* argv[]) {
    // Given
    OBJFileReader fileReader;
    Drawable *drawableObject = new Drawable();
    GLInterface *glInterface = new GLInterface();
    drawableObject->object= fileReader.readFile("objs/test/cube.obj", 'n');
    //TransformationsHandler::scaleObject(drawableObject->object, 1.5);
    drawableObject->setOrigin(1, 0, -5);

    // When
    drawableObject->setHermiteValues(100, 100, 0, 400, 100, 0, 100, 2000, 0, 400, -600, 0, 0.001, 1, 1, 1, 3, GL_POINTS);
    drawableObject->time = 10;
    glInterface->setInstance(drawableObject);
    glInterface->setPerspective(GL_PROJECTION, -2, 2, -2, 2, 1, 10);

    // Then
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(argc, argv);

    return 0;
}
