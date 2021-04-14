#include "../../include/trajectories.h"

void TrajectoryHandler::initDrawingTrajectory() {
    // Set the line color and point size
    glColor3f(red, green, blue);
    glPointSize(pointSize);
}

float TrajectoryHandler::slope(float x1, float y1, float x2, float y2) {
    float m = (y2 - y1) / (x2 - x1);
    return m;
}

TrajectoryHandler::TrajectoryHandler() {
    fx1 = fy1 = fx2 = fy2 = -1;
    fincrement = 0.05;
    ix1 = iy1 = ix2 = iy2 = -1;
    red = green = blue = 1;
    pointSize = 1;
    lineStyle = GL_POINTS;
    algorithm = ALG_GEO_DRAW_LINE;
}

void TrajectoryHandler::setAlgorithm(Algorithm algorithm) {
    this->algorithm = algorithm;
}

void TrajectoryHandler::setfCoordinates(float fx1, float fy1, float fx2, float fy2) {
    this->fx1 = fx1; this->fy1 = fy1;
    this->fx2 = fx2; this->fy2 = fy2;
}

void TrajectoryHandler::setiCoordinates(int ix1, int iy1, int ix2, int iy2) {
    this->ix1 = ix1; this->iy1 = iy1;
    this->ix2 = ix2; this->iy2 = iy2;
}

void TrajectoryHandler::setfIncrement(float fincrement) {
    this->fincrement = fincrement;
}

void TrajectoryHandler::setDrawingValues(float pointSize, GLenum lineStyle, int red, int green, int blue) {
    this->pointSize = pointSize;
    this->lineStyle = lineStyle;
    this->red = red; this->green = green; this->blue = blue;
}

void TrajectoryHandler::display() {
    switch(algorithm)
    {
        case ALG_GEO_DRAW_LINE:
            geoDrawLine();
        break;
        case ALG_DDA_DRAW_LINE:
            ddaDrawLine();
        break;
        case ALG_BRSNHM_DRAW_LINE:
            bresenhamDrawLine();
        break;
    }
}
void TrajectoryHandler::geoDrawLine() {
    // m -> slope, b-> point that intersects with y axis, x and y -> coordinates to draw
    float m, b, x, y;

    // Compute the slope (m)
    m = slope(fx1, fy1, fx2, fy2);
    // Compute b
    b = fy1 - m * fx1;
    
    initDrawingTrajectory();

    glBegin(lineStyle);
        // Travel from x1 to x2 with some increment and start drawing the points
        for(x = fx1; x <= fx2; x+=fincrement)
        {
            y = m * x + b;
            glVertex2f(x, y);
        }
    glEnd();
}

void TrajectoryHandler::ddaDrawLine() {
    float x, y;
    int dx = ix2 - ix1, dy = iy2 - iy1;
    int n = max(abs(dx), abs(dy));
    float dt = n, dxdt = dx / dt, dydt = dy / dt;

    x = ix1;
    y = iy1;
    initDrawingTrajectory();

    glBegin(lineStyle);
        while(n--) {
            glVertex2i((x), (y));
            x += dxdt;
            y += dydt;
        }
    glEnd();
}

void TrajectoryHandler::bresenhamDrawLine() {
    float x, y;
    int pk;
    int dx = ix2 - ix1, dy = iy2 - iy1;
    int _2dy = 2 * dy, _2dx = 2 * dx;
    int _2dy_Minus_2dx, _2dx_Minus_2dy;
    int n = max(abs(dx), abs(dy));
    float m = slope(ix1, iy1, ix2, iy2);
    
    x = ix1;
    y = iy1;
    initDrawingTrajectory();

    glBegin(lineStyle);
        if(m >= 0 && m <= 1) {
            _2dy_Minus_2dx = _2dy - _2dx;
            pk = _2dy - dx;

            while(n--) {
                if(pk < 0)
                {
                    glVertex2i(++x, y);
                    pk = pk + _2dy;
                }
                else
                {
                    glVertex2i(++x, ++y);
                    pk = pk + _2dy_Minus_2dx;
                }
            }
        }
        else if(m > 1)
        {
            _2dx_Minus_2dy = _2dx - _2dy;
            pk = _2dx - dy;

            while(n--) {
                if(pk < 0)
                {
                    glVertex2i(x, ++y);
                    pk = pk + _2dx;
                }
                else
                {
                    glVertex2i(++x, ++y);
                    pk = pk + _2dx_Minus_2dy;
                }
            }
        }
    glEnd();
}