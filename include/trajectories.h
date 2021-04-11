#pragma once
#include <GL/glut.h>
#include <math.h>

/**
 * TrajectoryHandler class: this class allow the handling of linear and curve trajectories, when an instance of this
 * class is created, it can draw or move objects calling the specific trajectory method.
 **/
class TrajectoryHandler {
    public:
        // Empty constructor
        TrajectoryHandler();

        // Draw a line with the geometric method
        void geoDrawLine(float x1, float y1, float x2, float y2, int r, int g, int b);

        // Draw a line following the DDA algorithm
        void ddaDrawLine(int x1, int y1, int x2, int y2);

        // Draw a line following the Bresenham algorithm
        void bresenhamDrawLine(int x1, int y1, int x2, int y2);
};