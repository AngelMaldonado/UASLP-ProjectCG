//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../../include/objreader.h"
#include "../../include/glinterface.h"
#include "../../include/transformations.h"
#include <math.h>

#define LEFT_CURVE_X -180
#define RIGHT_CURVE_X 180
#define CURVE_Y -50
#define LEFT_DEF_Y 800
#define RIGHT_DEF_Y -300

class SimulationFramework : public GLInterface {
    public:
        Coordinates origin, fixedVector;
        Object ship;
        Object base;
        Object worldFloor;
        TrajectoryHandler trajectoryHandler;
        float yLEFT, yRIGHT;
        bool start;
        float angle;
        float totalAngle;
        virtual void display();
        virtual void run();
        virtual void keyboard(unsigned char key, int x, int y);
        SimulationFramework(){ 
            yLEFT = LEFT_DEF_Y, yRIGHT = RIGHT_DEF_Y; 
            start = false;
            totalAngle = angle = 0;
        };
};

void SimulationFramework::display() {
    setBackgroundColor(0, 0, 1);
    worldFloor.draw();
    base.draw();
    ship.draw();
    
    trajectoryHandler.draw();
}

void SimulationFramework::run() {
    if(start) {
        trajectoryHandler.hermiteAnimateObject(ship, ship.getOrigin());
        if(ship.getOrigin().x > 50) {
            if(ship.getOrigin().y < 50 && ship.getOrigin().y > -49) {
                TransformationsHandler::rotateObject(ship, ship.getOrigin(), 0, 0, totalAngle/50);
                totalAngle -= totalAngle/50;
            } else if(ship.getOrigin().y == -49) start = false;
        } else if(ship.getOrigin().x < 50){
            angle = acos((fixedVector.x * ship.getOrigin().x + fixedVector.y * ship.getOrigin().y + fixedVector.z * ship.getOrigin().z) /
                    (sqrt(fixedVector.x * fixedVector.x + fixedVector.y * fixedVector.y + fixedVector.z * fixedVector.z) *
                     sqrt(ship.getOrigin().x * ship.getOrigin().x + ship.getOrigin().y * ship.getOrigin().y + ship.getOrigin().z * ship.getOrigin().z)));
            totalAngle += angle;
            TransformationsHandler::rotateObject(ship, ship.getOrigin(), 0, 0, -angle);
        }
        origin.x = ship.getOrigin().x;
        origin.y = ship.getOrigin().y - 30;
        origin.z = 0;
        fixedVector.x = ship.getOrigin().x;
        fixedVector.y = ship.getOrigin().y + 30;
        fixedVector.z = 0;
    }
}

class TestFramework : public GLInterface {
    protected:
        GLInterface *parent;
    public:
        Object cube;
        virtual void display();
        virtual void run();
        TestFramework(GLInterface *parent){ this->parent = parent; }
};

void TestFramework::display() {
    setBackgroundColor(1, 1, 1);
    cube.draw();
}

void TestFramework::run() {
    TransformationsHandler::rotateObject(cube, cube.getOrigin(), 0.3, 0.5, 0);
}

void SimulationFramework::keyboard(unsigned char key, int x, int y) {
    switch(key)
    {
        case 120:
            trajectoryHandler.setHermiteValues(LEFT_CURVE_X, CURVE_Y, 0, RIGHT_CURVE_X, CURVE_Y, 0, LEFT_CURVE_X, yLEFT+=5, 0, RIGHT_CURVE_X, yRIGHT, 0, 0.001, 1, 1, 1, 1, GL_POINTS);
        break;
        case 122:
            trajectoryHandler.setHermiteValues(LEFT_CURVE_X, CURVE_Y, 0, RIGHT_CURVE_X, CURVE_Y, 0, LEFT_CURVE_X, yLEFT-=5, 0, RIGHT_CURVE_X, yRIGHT, 0, 0.001, 1, 1, 1, 1, GL_POINTS);
        break;
        case 99:
            trajectoryHandler.setHermiteValues(LEFT_CURVE_X, CURVE_Y, 0, RIGHT_CURVE_X, CURVE_Y, 0, LEFT_CURVE_X, yLEFT, 0, RIGHT_CURVE_X, yRIGHT-=5, 0, 0.001, 1, 1, 1, 1, GL_POINTS);
        break;
        case 118:
            trajectoryHandler.setHermiteValues(LEFT_CURVE_X, CURVE_Y, 0, RIGHT_CURVE_X, CURVE_Y, 0, LEFT_CURVE_X, yLEFT, 0, RIGHT_CURVE_X, yRIGHT+=5, 0, 0.001, 1, 1, 1, 1, GL_POINTS);
        break;
        case 115:
            start = true;
        break;
    }
}

void givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(int argc, char* argv[]) {
    // Given
    OBJFileReader reader1, reader2, reader3;
    SimulationFramework *simFramework = new SimulationFramework();
    GLInterface *glInterface = new GLInterface(1024, 576, 0, 0, "Perspective Display - Test");
    simFramework->ship = Object(reader1.readFile("objs/Starship2.obj", 'n'));
    simFramework->worldFloor = Object(reader2.readFile("objs/Floor.obj", 'n'));
    simFramework->base = Object(reader3.readFile("objs/Floor.obj", 'n'));
    
    // SHIP
    TransformationsHandler::scaleObject(simFramework->ship, 3.5);
    simFramework->ship.setOrigin(LEFT_CURVE_X, CURVE_Y, 0);
    simFramework->ship.setBrush(0.282, 1.5, 1, 1, GL_POLYGON);

    // REFERENCE FOR ROTATION
    simFramework->origin.x = LEFT_CURVE_X;
    simFramework->origin.y = CURVE_Y - 30;
    simFramework->origin.z = 0;
    simFramework->fixedVector.x = LEFT_CURVE_X;
    simFramework->fixedVector.y = CURVE_Y + 30;
    simFramework->fixedVector.z = 0;

    // BASE
    TransformationsHandler::scaleObject(simFramework->base, 1.2);
    simFramework->base.setOrigin(RIGHT_CURVE_X, CURVE_Y-15, 0);
    simFramework->base.setBrush(1, 0, 0, 1, GL_POLYGON);

    // FLOOR
    TransformationsHandler::scaleObject(simFramework->worldFloor, 50);
    simFramework->worldFloor.setBrush(0, 1, 0, 1, GL_POLYGON);
    simFramework->worldFloor.setOrigin(0, -100, 0);

    // When
    simFramework->trajectoryHandler.setHermiteValues(LEFT_CURVE_X, CURVE_Y, 0, RIGHT_CURVE_X, CURVE_Y, 0, LEFT_CURVE_X, LEFT_DEF_Y, 0, RIGHT_CURVE_X, RIGHT_DEF_Y, 0, 0.001, 1, 1, 1, 1, GL_POINTS);
    simFramework->time = 10;
    glInterface->setInstance(simFramework);
    glInterface->setPerspective(GL_PROJECTION, -20, 20, -15, 15, 10, 600);
    glInterface->setTranslationValues(0, 0, -100);

    // Then
    glInterface->startFramework(argc, argv);
}

void visibleTest(int argc, char* argv[]) {
    // Given
    OBJFileReader reader1;
    GLInterface *glInterface = new GLInterface(1024, 576, 0, 0, "Perspective Display - Test");
    TestFramework *simFramework = new TestFramework(glInterface);
    simFramework->cube = Object(reader1.readFile("objs/Starship2.obj", 'n'));
    
    // SHIP
    TransformationsHandler::scaleObject(simFramework->cube, 9);
    simFramework->cube.setOrigin(0, 0, 0);
    simFramework->cube.setBrush(1.5, 2.4, 0, 1, GL_POLYGON);


    // When
    simFramework->time = 10;
    glInterface->setInstance(simFramework);
    glInterface->setPerspective(GL_PROJECTION, -20, 20, -15, 15, 20, 600);
    glInterface->setTranslationValues(0, 0, -100);

    // Then
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    givenModel_whenPerspectiveViewAndCertainDisplayFunction_thenModelDisplays(argc, argv);
    //visibleTest(argc, argv);

    return 0;
}
