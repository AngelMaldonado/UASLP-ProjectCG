//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../../include/objreader.h"
#include "../../include/glinterface.h"
#include "../../include/transformations.h"

class SimulationFramework : public GLInterface {
    public:
        Object object;
        virtual void display();
        virtual void run();
        SimulationFramework(){};
};

void SimulationFramework::display() {
    object.draw();
}

void SimulationFramework::run() {
    TransformationsHandler::rotateObject(object, object.getOrigin(), 0.1, 0, 0);
}

void givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(int argc, char* argv[]) {
    // Given
    OBJFileReader fileReader;
    SimulationFramework *simFramework = new SimulationFramework();
    GLInterface *glInterface = new GLInterface(1024, 576, 0, 0, "Normal vectors - Test");
    simFramework->object = Object(fileReader.readFile("objs/test/cube.obj", 'n'));
    TransformationsHandler::scaleObject(simFramework->object, 5);
    simFramework->object.setOrigin(0, 0, -20);

    // When
    simFramework->time = 10;
    glInterface->setInstance(simFramework);
    glInterface->setPerspective(GL_PROJECTION, -10, 10, -10, 10, 10, 600);

    // Then
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(argc, argv);

    return 0;
}