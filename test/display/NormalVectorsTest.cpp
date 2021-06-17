//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../../include/objreader.h"
#include "../../include/glinterface.h"
#include "../../include/transformations.h"

class SimulationFramework : public GLInterface {
    public:
        Object ship;
        virtual void display();
        virtual void run();
        SimulationFramework(){};
};

void SimulationFramework::display() {
    ship.draw();
}

void SimulationFramework::run() {
    TransformationsHandler::rotateObject(ship, ship.getOrigin(), 0.1, 0, 0);
}

void givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(int argc, char* argv[]) {
    // Given
    OBJFileReader fileReader;
    SimulationFramework *simFramework = new SimulationFramework();
    GLInterface *glInterface = new GLInterface(1024, 576, 0, 0, "Normal vectors - Test");
    simFramework->ship = Object(fileReader.readFile("objs/test/cube.obj", 'n'));
    TransformationsHandler::scaleObject(simFramework->ship, 5);
    simFramework->ship.setOrigin(0, 0, -50);

    // When
    simFramework->time = 5;
    glInterface->setInstance(simFramework);
    glInterface->setPerspective(GL_PROJECTION, -70, 70, -60, 60, 30, 600);

    // Then
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(argc, argv);

    return 0;
}