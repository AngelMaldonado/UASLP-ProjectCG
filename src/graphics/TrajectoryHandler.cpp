#include "../../include/trajectories.h"
#include <iostream>

TrajectoryHandler::TrajectoryHandler() {
    fx1 = fy1 = fx2 = fy2 = -1;
    fincrement = 0.05;
    ix1 = iy1 = ix2 = iy2 = -1;
    red = green = blue = 1;
    algorithm = ALG_GEO_DRAW_LINE;
}

void TrajectoryHandler::setAlgorithm(Algorithm algorithm) {
    this->algorithm = algorithm;
}

void TrajectoryHandler::setfCoordinates(float fx1, float fy1, float fx2, float fy2) {
    this->fx1 = fx1; this->fy1 = fy1;
    this->fx2 = fx2; this->fy2 = fy2;
}

void TrajectoryHandler::setfIncrement(float fincrement) {
    this->fincrement = fincrement;
}

void TrajectoryHandler::display() {
    switch(algorithm)
    {
        case ALG_GEO_DRAW_LINE:
            geoDrawLine();
        break;
        case ALG_DDA_DRAW_LINE:
        break;
        case ALG_BRSNHM_DRAW_LINE:
        break;
    }
}
void TrajectoryHandler::geoDrawLine() {
    // m -> slope, b-> point that intersects with y axis, x and y -> coordinates to draw
    float m, b, x, y;

    // Compute the slope (m)
    m = (fy2 - fy1) / (fx2 - fx1);
    // Compute b
    b = fy1 - m * fx1;
    
    // Set the line color and point size
    glColor3f(red, green, blue);
    glPointSize(3.0);

    glBegin(GL_POINTS);
        // Travel from x1 to x2 with some increment and start drawing the points
        for(x = fx1; x <= fx2; x+=fincrement)
        {
            y = m * x + b;
            glVertex2f(round(x), round(y));
        }
    glEnd();
}