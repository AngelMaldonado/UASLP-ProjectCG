#include "../../include/glinterface.h"
#include <iostream>

GLInterface::GLInterface() {
    // Default framework viewing and window values
    wndWith = wndHeight = DEF_WINDOW_SIZE;
    wndPosX = wndPosY = DEF_WINDOW_POSXY;
    wndName = (char*)DEF_WINDOW_NAME;
    matrixMode = GL_MODELVIEW;
    orthoVleft = orthoVbottom = -1;
    orthoVright = orthoVtop = 1;
    near = 0; far = 1;
    rotAngle = 0;
    rotX = rotY = rotZ = 0;

    view = VIEW_3D;

    time = 20;
}

GLInterface::GLInterface(int wndWith, int wndHeight, int wndPosX, int wndPosY, const char* wndName) {
    this->wndWith = wndWith;
    this->wndHeight = wndHeight;
    this->wndPosX = wndPosX;
    this->wndPosY = wndPosY;
    this->wndName = (char *)wndName;
}

void GLInterface::displayWrapper() {
    glClear(GL_COLOR_BUFFER_BIT);
    instance->display();
    glutSwapBuffers();
}

void GLInterface::runWrapper(int timerValue) {
    instance->run();
    glutPostRedisplay();
    glutTimerFunc(timerValue, runWrapper, timerValue);
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
    glutTimerFunc(instance->time, runWrapper, instance->time);

    glutMainLoop();
}

void GLInterface::setView2D(GLenum matrixMode, 
                            float orthoVleft, float orthoVright, float orthoVbottom, float orthoVtop) {
    this->matrixMode = matrixMode;
    this->orthoVleft = orthoVleft;
    this->orthoVright = orthoVright;
    this->orthoVbottom = orthoVbottom;
    this->orthoVtop = orthoVtop;

    view = VIEW_2D;
}

void GLInterface::setView3D(GLenum matrixMode,
                            float orthoVleft, float orthoVright, float orthoVbottom, float orthoVtop,
                            float near, float far, float rotAngle, float rotX, float rotY, float rotZ) {
    this->matrixMode = matrixMode;
    this->orthoVleft = orthoVleft;
    this->orthoVright = orthoVright;
    this->orthoVbottom = orthoVbottom;
    this->orthoVtop = orthoVtop;
    this->near = near;
    this->far = far;
    this->rotAngle = rotAngle;
    this->rotX = rotX;
    this->rotY = rotY;
    this->rotZ = rotZ;

    view = VIEW_3D;
}

void GLInterface::setPerspective(GLenum matrixMode,
                            float perspVleft, float perspVright, float perspVbottom, float perspVtop,
                            float near, float far) {
    this->matrixMode = matrixMode;
    this->perspVleft = perspVleft;
    this->perspVright = perspVright;
    this->perspVbottom = perspVbottom;
    this->perspVtop = perspVtop;
    this->near = near;
    this->far = far;

    view = VIEW_PERSP;
}

void GLInterface::initView(void) {
    // Select clearing (background) color
    glClearColor (0.0, 0.0, 0.0, 0.0);

    // Initialize viewing values
    glMatrixMode(matrixMode);
    glLoadIdentity();

    switch(view)
    {
        case VIEW_2D:
        break;
        case VIEW_3D:
            // Orthographic view
            glOrtho(orthoVleft, orthoVright, orthoVbottom, orthoVtop, near, far); 
        break;
        case VIEW_PERSP:
            // Perspective view
            glFrustum(perspVleft, perspVright, perspVbottom, perspVtop, near, far);
        break;
    }
}

void GLInterface::setInstance(GLInterface* framework) {
    instance = framework;
}

void GLInterface::display() {}

void GLInterface::run() {}

// Initialize the instance of GLInterface to a null reference
GLInterface* GLInterface::instance = NULL;

Drawable::Drawable() {
    brush.red = 1;
    brush.green = 1;
    brush.blue = 1;
    brush.pointSize = 1.0;
    brush.lineStyle = GL_POINTS;
}

Drawable::Drawable(int red, int green, int blue, float pointSize, GLenum lineStyle) {
    brush.red = red;
    brush.green = green;
    brush.blue = blue;
    brush.pointSize = pointSize;
    brush.lineStyle = lineStyle;
}

void Drawable::draw(){}