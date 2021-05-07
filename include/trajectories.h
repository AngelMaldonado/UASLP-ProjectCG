#pragma once
#include "glinterface.h"
#include <math.h>
#include <iostream>

using namespace std;

/**
 * TrajectoryHandler class: this class allow the handling of linear and curve trajectories, when an instance of this
 * class is created, it can draw or move objects calling the specific trajectory method.
 **/
enum Algorithm {
            ALG_BRSNHM_DRAW_LINE = 1,
            ALG_HERMITE_DRAW_CURVE = 2
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

// Coordinates: X, Y and Z
typedef struct {
    // X coordinate
    float x;
    // Y coordinate
    float y;
} Coordinates;

// Values for Bresenham algorithm
typedef struct {
    // Dx for Bresenham
    int dx;
    // Dy for Bresenham
    int dy;
    // Amount of steps for Bresenham
    int n;
    // Decision parameter for Bresenham
    int pk;
    // 2dy value for Bresenham
    int _2dy;
    // 2dx value for Bresenham
    int _2dx;
    // 2dy - 2dx value for Bresenham
    int _2dy_Minus_2dx;
    // 2dx - 2dy value for Bresenham
    int _2dx_Minus_2dy;
    // Slope value for Bresenham
    float m;
    // Point 1 for Bresenham
    Coordinates p1;
    // Point 2 for Bresenham
    Coordinates p2;
    // Brush to paint the line with Bresenham
    Brush brush;
} Bresenham;

// Values for Hermite algorithm
typedef struct {
    // Steps to draw the curve's points
    float increment;
    // Point 1 for Hermite
    Coordinates p1;
    // Vector 1 for Hermite
    Coordinates r1;
    // Point 2 for Hermite
    Coordinates p4;
    // Vector 2 for Hermite
    Coordinates r4;
    // Brush to paint the curve with Hermite
    Brush brush;
} Hermite;

class TrajectoryHandler : public GLInterface{
    private:
        // Selected algorithm/method
        Algorithm algorithm;

        // Handler for Bresenham's algorithm
        Bresenham bresenham;
        // Handler for Hermite's algorithm
        Hermite hermite;

        // Initialize the drawing line
        void initDrawingTrajectory(Brush brush);

        // Compute the slope of the given 2 pairs of coordinates
        float slope(float x1, float y1, float x2, float y2);

        // Compute the values for Bresenham algorithm (the points needs to be set before)
        void initBresenham();
    public:
        // Empty constructor
        TrajectoryHandler();

        // Sets the algorithm that GLInterface is going to execute
        void setAlgorithm(Algorithm algorithm);

        // Set the values for Bresenham
        void setBresenhamValues(float fx1, float fy1, float fx2, float fy2,
                                int red, int green, int blue, float pointSize, GLenum lineStyle);

        // Sets custom hermite curve values
        void setHermiteValues(float xP1, float yP1, float xP4, float yP4,
                              float xR1, float yR1, float xR4, float yR4,
                              float increment,
                              int red, int green, int blue, float pointSize, GLenum lineStyle);

        // Overrided display function from GLInterface
        virtual void display();

        // Draw a line following the DDA algorithm
        void ddaDrawLine();

        // Draw a line following the Bresenham algorithm
        void bresenhamDrawLine();

        // Draw a curve following the Hermite algorithm
        void hermiteDrawCurve();
};