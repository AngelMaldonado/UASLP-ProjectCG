#include "../../include/glinterface.h"
#include <iostream>

GLInterface::GLInterface() {
    // Default framework viewing and window values
    wndWith = wndHeight = 500;
    wndPosX = wndPosY = 50;
    wndName = (char*)"Glut App";
    matrixMode = GL_MODELVIEW;
    orthoVleft = orthoVtop = 0;
    orthoVright = orthoVtop = 1;
    nearVal = -1; farVal = 1;
    rotAngle = 0;
    rotX = rotY = rotZ = 0;

    view = VIEW_3D;
}

GLInterface::GLInterface(int wndWith, int wndHeight, int wndPosX, int wndPosY, char* wndName) {
    this->wndWith = wndWith;
    this->wndHeight = wndHeight;
    this->wndPosX = wndPosX;
    this->wndPosY = wndPosY;
    this->wndName = wndName;
}

void GLInterface::displayWrapper() {
    glClear(GL_COLOR_BUFFER_BIT);
    instance->display();
    glFlush();
}

void GLInterface::runWrapper() {
    instance->run();
}

void GLInterface::startFramework(int argc, char *argv[]) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(wndPosX, wndPosY);
    glutInitWindowSize(wndWith, wndHeight);
    glutCreateWindow(wndName);
    initView();

    // Function callbacks
    glutDisplayFunc(displayWrapper);

    // Start the main GLUT loop/thread
    //glutIdleFunc(runWrapper);
    glutMainLoop();
}

void GLInterface::initView(void) {
    // Select clearing (background) color
    glClearColor (0.0, 0.0, 0.0, 0.0);

    // Initialize viewing values
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);
    if(view == VIEW_3D)
    {
        glOrtho(orthoVleft, orthoVright, orthoVbottom, orthoVtop, nearVal, farVal);
        // Rotate the whole scene so that three faces of the cube are seen
        glRotatef (rotAngle, rotX, rotY, rotZ);
    }
    else
        gluOrtho2D(orthoVleft, orthoVright, orthoVbottom, orthoVtop);
}

void GLInterface::setInstance(GLInterface* framework) {
    instance = framework;
}

void GLInterface::display() {}

void GLInterface::run() {}

// Initialize the instance of GLInterface to a null reference
GLInterface* GLInterface::instance = NULL;