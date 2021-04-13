#include "../../include/trajectories.h"
#include <iostream>

TrajectoryHandler::TrajectoryHandler() {
    fx1 = fy1 = fx2 = fy2 = -1;
    ix1 = iy1 = ix2 = iy2 = -1;
    red = green = blue = 1;
    alg = GEO_DRAW_LINE;
}

void TrajectoryHandler::setfCoordinates(float fx1, float fy1, float fx2, float fy2) {
    this->fx1 = fx1; this->fy1 = fy1;
    this->fx2 = fx2; this->fy2 = fy2;
}

void TrajectoryHandler::display() {
    switch(alg)
    {
        case GEO_DRAW_LINE:
            geoDrawLine();
    }
}
void TrajectoryHandler::geoDrawLine() {
    // m -> slope, b-> point that intersects with y axis, x and y -> coordinates to draw
    float m, b, x, y;

    // Compute the slope (m)
    m = (fy2 - fy1) / (fx2 - fx1);
    // Compute b
    b = fy1 - m * fx1;
    
    glColor3f(red, green, blue);
    glPointSize(3.0);

    glBegin(GL_POINTS);
        glVertex2i(0.5, 0.5);
        glVertex3f(0.8, 0.8, 0);
    glEnd();

    glBegin(GL_LINES);
    // Travel from x1 to x2 with some increment
    for(x = fx1; x <= fx2; x++)
    {
        y = m * x + b;
        glVertex3f(round(x), round(y), 0);
    }
    glEnd();
}