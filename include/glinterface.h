#pragma once
#include <GL/glut.h>

#define DEF_WINDOW_WIDTH 500
#define DEF_WINDOW_HEIGHT 500
#define DEF_WINDOW_SIZE 500
#define DEF_WINDOW_POSX 50
#define DEF_WINDOW_POSY 50
#define DEF_WINDOW_POSXY 50
#define DEF_WINDOW_NAME "OpenGL - Custom framework App"

/**
 * To use this interface subclasses are necessary to use the callbacks:
 * example: 
 * SomeSubclass *mySubClass = new SomeSubClass();
 * GLInterface *glInterface = new GLInterface();
 * 
 * mySubClass->someOperations(void someParameters);
 * glInterface->setView();
 * 
 * glInterface->setInstance(mySubClass);
 * 
 * glInterface->startFramework();
 */

// Enum with the different views for frameworks (2D and 3D)
enum View {
    VIEW_3D,
    VIEW_2D,
    VIEW_PERSP
};

// Brush to paint the line/curve
typedef struct {
    // Red value for Brush
    int red;
    // Green value for Brush
    int green;
    // Blue value for Brush
    int blue;
    // Pixel size for the Brush
    float pointSize; 
    // Drawing style for the Brush
    GLenum lineStyle;
} Brush;

class GLInterface {
    protected:
        /*
         * This is an instance pointer of GLInterface class to be able to instantiante the
         * function callbacks.
         */
        static GLInterface *instance;
    private:
        // Window's width in pixels
        int wndWith;
        // Window's height in pixels
        int wndHeight;
        // Window's X position in pixels
        int wndPosX;
        // Window's Y position in pixels
        int wndPosY;
        // Window's name
        char* wndName;

        // Viewing matrix mode (OpenGL)
        GLenum matrixMode;
        // Ortho left value in pixels (OpenGL)
        float orthoVleft;
        // Ortho right value in pixels (OpenGL)
        float orthoVright;
        // Ortho bottom value in pixels (OpenGL)
        float orthoVbottom;
        // Ortho top value in pixels (OpenGL)
        float orthoVtop;
        // Perspective left value in pixels (OpenGL)
        float perspVleft;
        // Perspective right value in pixels (OpenGL)
        float perspVright;
        // Perspective bottom value in pixels (OpenGL)
        float perspVbottom;
        // Perspective top value in pixels (OpenGL)
        float perspVtop;
        // Z near value in pixels (OpenGL)
        float near;
        // Z far value in pixels (OpenGL)
        float far;
        // Camera's rotating angle value (OpenGL)
        float rotAngle;
        // Percentage of the rotAngle in X
        float rotX;
        // Percentage of the rotAngle in Y
        float rotY;
        // Percentage of the rotAngle in Z
        float rotZ;

        /************************/
        float fov;
        float aspect;

        // Variable to set the 3D or 2D view of the framework instance
        View view;
    public:
        // Time variable for the timer function of OpenGL
        unsigned int time;

        // Empty GLInterface constructor
        GLInterface();
        // Custom window values for GLInterface constructor
        GLInterface(int wndWith, int wndHeight, int wndPosX, int wndPosY, const char* wndName);

        // Main display function of OpenGL framework
        static void displayWrapper();
        // Instance wrapper for the glutIdleFunc
        static void runWrapper(int timerValue);

        // Set the 2D window's viewing values
        void setView2D(GLenum matrixMode,
                       float orthoVleft, float orthoVright, float orthoVbottom, float orthoVtop);
        // Set the 3D window's viewing values
        void setView3D(GLenum matrixMode,
                       float orthoVleft, float orthoVright, float orthoVbottom, float orthoVtop,
                       float near, float far, float rotAngle, float rotX, float rotY, float rotZ);

        // Set the 3D perspective view
        void setPerspective(GLenum matrixMode,
                            float perspVleft, float perspVright, float perspVbottom, float perspVtop,
                            float near, float far);

        // Initialize the window's view
        void initView (void);
        // Starts the main framework
        void startFramework(int argc, char *argv[]);

        // Run app
        virtual void run();
        // Display function
        virtual void display(void);

        // Set instance to GLInterface
        static void setInstance(GLInterface* framework);
};

// This class makes every object drawable
class Drawable {
    protected:
        // Brush to define the color, pointSize and lineStyle of the drawable object
        Brush brush;
    public:
        // Default constructor
        Drawable();
        // Constructor with custom values
        Drawable(int red, int green, int blue, float pointSize, GLenum lineStyle);
        // Draw method, the extended class needs to define its implementation
        virtual void draw();
};