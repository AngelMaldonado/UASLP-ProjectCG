#pragma once
#include <GL/glut.h>

/**
 * To use this interface subclasses are necessary to use the callbacks
 */
enum View {
    VIEW_3D,
    VIEW_2D
};

class GLInterface {
    protected:
        /*
         * This is an instance pointer of GLInterface class to be able to instantiante the
         * function calls.
         */
        static GLInterface *instance;
    private:
        // Window values
        int wndWith, wndHeight;
        int wndPosX, wndPosY;
        char* wndName;
        GLenum matrixMode;
        float orthoVleft, orthoVright, orthoVbottom, orthoVtop;
        float nearVal, farVal;
        float rotAngle, rotX, rotY, rotZ;

        // This variable sets the 3D or 2D view of the framework
        View view;
    public:
        // Empty GLInterface constructor
        GLInterface();
        // Custom window values for GLInterface constructor
        GLInterface(int wndWith, int wndHeight, int wndPosX, int wndPosY, char* wndName);
        // Main display function of OpenGL framework
        static void displayWrapper();
        // Function to include in glutIdleFunc
        static void runWrapper();
        // Function to initialize the 3D view
        void initView (void);
        // Starts the main framework
        void startFramework(int argc, char *argv[]);
        // Run app
        void run();
        // Display function
        virtual void display(void);

        // Function to set instance to GLInterface
        static void setInstance(GLInterface* framework);
};