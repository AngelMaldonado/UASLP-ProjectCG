#include "../../include/trajectories.h"

TrajectoryHandler::TrajectoryHandler() {}

void TrajectoryHandler::geoDrawLine(float x1, float y1, float x2, float y2, int red, int green, int blue) {
    // m -> slope, b-> point that intersects with y axis, x and y -> coordinates to draw
    float m, b, x, y;

    // Compute the slope (m)
    m = (y2 - y1) / (x2 - x1);
    // Compute b
    b = y1 - m * x1;
    
    glBegin(GL_POINTS);
    // Travel from x1 to x2 with some increment
    for(x = x1; x <= x2; x++)
    {
        y = m * x + b;
        glColor3f(red, green, blue);
        glVertex2i(round(x), round(y));
    }
    glEnd();
}