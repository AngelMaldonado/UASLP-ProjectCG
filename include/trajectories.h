#pragma once
#include "glinterface.h"
#include <math.h>

/**
 * TrajectoryHandler class: this class allow the handling of linear and curve trajectories, when an instance of this
 * class is created, it can draw or move objects calling the specific trajectory method.
 **/
enum Algorithms {
            GEO_DRAW_LINE = 1,
            DDA_DRAW_LINE = 2,
            BRSNHM_DRAW_LINE = 3
        };

class TrajectoryHandler : public GLInterface{
    private:
        // Foat coordinates values
        float fx1, fy1, fx2, fy2;
        // Integer coordinates values
        int ix1, iy1, ix2, iy2;

        // RGB line/curve values
        int r, g, b;

        // Selected algorithm/method
        int alg;
    public:
        // Empty constructor
        TrajectoryHandler();

        // Sets custom coordinates f values
        void setfCoordinates(float fx1, float fy1, float fx2, float fy2);

        // Overrided display function from GLInterface
        virtual void display();

        // Draw a line with the geometric method
        static void geoDrawLine(float x1, float y1, float x2, float y2, int r, int g, int b);

        // Draw a line following the DDA algorithm
        void ddaDrawLine(int x1, int y1, int x2, int y2);

        // Draw a line following the Bresenham algorithm
        void bresenhamDrawLine(int x1, int y1, int x2, int y2);
};