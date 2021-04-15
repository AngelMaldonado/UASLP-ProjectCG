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
            ALG_GEO_DRAW_LINE = 1,
            ALG_DDA_DRAW_LINE = 2,
            ALG_BRSNHM_DRAW_LINE = 3,
            ALG_HERMITE_DRAW_CURVE = 4
        };

class TrajectoryHandler : public GLInterface{
    private:
        // Float coordinates values
        float fx1, fy1, fx2, fy2;
        // Float coordinates to set the vectors to hermite curves
        float fxR1, fyR1, fxR2, fyR2;
        // Increment to the geometry methods
        float fincrement;
        // Integer coordinates values
        int ix1, iy1, ix2, iy2;

        // RGB line/curve values
        int red, green, blue;
        // Pixel size for the points
        float pointSize; 
        // Drawing style for the line
        GLenum lineStyle;

        // Selected algorithm/method
        Algorithm algorithm;

        // Initialize the drawing line
        void initDrawingTrajectory();

        // Compute the slope of the given 2 pairs of coordinates
        float slope(float x1, float y1, float x2, float y2);
    public:
        // Empty constructor
        TrajectoryHandler();

        // Sets the algorithm that GLInterface is going to execute
        void setAlgorithm(Algorithm algorithm);

        // Sets custom coordinates f values
        void setfCoordinates(float fx1, float fy1, float fx2, float fy2);

        // Sets custom hermite curve values
        void setHermiteValues(float xP1, float yP1, float xP4, float yP4,
                              float xR1, float yR1, float xR4, float yR4);

        // Sets custom integer coordinates values
        void setiCoordinates(int ix1, int iy1, int x2, int y2);

        // Sets custom fincrement
        void setfIncrement(float setfincrement);

        // Sets custom drawing values for trajectories
        void setDrawingValues(float pointSize, GLenum lineStyle, int red, int green, int blue);

        // Overrided display function from GLInterface
        virtual void display();

        // Draw a line with the geometric method
        void geoDrawLine();

        // Draw a line following the DDA algorithm
        void ddaDrawLine();

        // Draw a line following the Bresenham algorithm
        void bresenhamDrawLine();

        // Draw a curve following the Hermite algorithm
        void hermiteDrawCurve();
};