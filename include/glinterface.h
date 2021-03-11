#pragma once
#include <GL/glut.h>

class GLInterface {
    private:

    public:
        // Empty GLInterface constructor
        GLInterface();
        // Function to initialize an OpenGL window
        void initGLWindow(int argc, char** argv, int width, int height, int posX, int posY);

        // Function to initialize the 3D view
        void initView (void);

        // Function to set a display function in OpenGL
        void setDisplayFunction(void (*callback)());

        // Function to start the main OpenGL loop
        void startGLloop();

        // Function to display a Mesh in screen with graphics
        //static void displayMesh();
};