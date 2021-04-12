#include "../../include/glinterface.h"

GLInterface::GLInterface() {
    wndWith = 800;
    wndHeight = 800;
    wndPosX = 50;
    wndPosY = 50;
    wndName = (char*)"Glut App";
}

GLInterface::GLInterface(int wndWith, int wndHeight, int wndPosX, int wndPosY, char* wndName) {
    this->wndWith = wndWith;
    this->wndHeight = wndHeight;
    this->wndPosX = wndPosX;
    this->wndPosY = wndPosY;
    this->wndName = wndName;
}

void GLInterface::displayWrapper() {
    instance->display();
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
    glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);

    // Rotate the whole scene so that three faces of the cube are seen
    glRotatef (30.0, 1.0, 1.0, 1.0);
}

void GLInterface::setInstance(GLInterface* framework) {
    instance = framework;
}

void GLInterface::display() {}

void GLInterface::run() {}

// Initialize the instance of GLInterface to a null reference
GLInterface* GLInterface::instance = NULL;