//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../../include/objreader.h"
#include "../../include/glinterface.h"
#include "../../include/transformations.h"

class SimulationFramework : public GLInterface {
    public:
        Object object;
        TrajectoryHandler trajectoryHandler;
        virtual void display();
        virtual void run();
        SimulationFramework(){};
};

void SimulationFramework::display() {
    object.draw();
    trajectoryHandler.draw();
}

void SimulationFramework::run() {
    trajectoryHandler.hermiteAnimateObject(object, object.getOrigin());
    TransformationsHandler::rotateObject(object, object.getOrigin(), 0.1, 0, 0);
}

void Menu(int value) {

}

void givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(int argc, char* argv[]) {
    // Given
    OBJFileReader fileReader;
    SimulationFramework *simFramework = new SimulationFramework();
    GLInterface *glInterface = new GLInterface(1024, 576, 0, 0, "Perspective Display - Test");
    simFramework->object = Object(fileReader.readFile("objs/test/cube.obj", 'n'));
    TransformationsHandler::scaleObject(simFramework->object, 5);
    simFramework->object.setOrigin(-5, 0, -20);

    // When
    simFramework->trajectoryHandler.setHermiteValues(-150, -30, -200, 150, -30, -200, -150, 200, -200, 150, -600, -200, 0.001, 1, 1, 1, 1, GL_POINTS);
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
