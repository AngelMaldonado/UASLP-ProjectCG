#include "../../include/trajectories.h"

void TrajectoryHandler::initDrawingTrajectory(Brush brush) {
    // Set the line color and point size
    glColor3f(brush.red, brush.green, brush.blue);
    glPointSize(brush.pointSize);
}

float TrajectoryHandler::slope(float x1, float y1, float x2, float y2) {
    float m = (y2 - y1) / (x2 - x1);
    return m;
}

void TrajectoryHandler::initBresenham() {
    bresenham.dx = bresenham.p2.x - bresenham.p1.x, bresenham.dy = bresenham.p2.y - bresenham.p1.y;
    bresenham._2dy = 2 * bresenham.dy, bresenham._2dx = 2 * bresenham.dx;
    bresenham.n = max(abs(bresenham.dx), abs(bresenham.dy));
    bresenham.m = slope(bresenham.p1.x, bresenham.p1.y, bresenham.p2.x, bresenham.p2.y);
}

TrajectoryHandler::TrajectoryHandler() {
    algorithm = ALG_BRSNHM_DRAW_LINE;
}

void TrajectoryHandler::setAlgorithm(Algorithm algorithm) {
    this->algorithm = algorithm;
}

void TrajectoryHandler::setBresenhamValues(float fx1, float fy1, float fx2, float fy2,
                                int red, int green, int blue, float pointSize, GLenum lineStyle) {
    bresenham.p1.x = fx1; bresenham.p1.y = fy1;
    bresenham.p2.x = fx2; bresenham.p2.y = fy2;
    
    bresenham.brush.red = red;
    bresenham.brush.green = green;
    bresenham.brush.blue = blue;
    bresenham.brush.pointSize = pointSize;
    bresenham.brush.lineStyle = lineStyle;

    initBresenham();
}

void TrajectoryHandler::setHermiteValues(float xP1, float yP1, float xP4, float yP4,
                                         float xR1, float yR1, float xR4, float yR4,
                                         float increment,
                                         int red, int green, int blue, float pointSize, GLenum lineStyle) {
        hermite.p1.x = xP1; hermite.p1.y = yP1;
        hermite.p4.x = xP4; hermite.p4.y = yP4;
        hermite.r1.x = xR1; hermite.r1.y = yR1;
        hermite.r4.x = xR4; hermite.r4.y = yR4;

        hermite.increment = increment;

        hermite.brush.red = red;
        hermite.brush.green = green;
        hermite.brush.blue = blue;
        hermite.brush.pointSize = pointSize;
        hermite.brush.lineStyle = lineStyle;
    }

void TrajectoryHandler::display() {
    switch(algorithm)
    {
        case ALG_BRSNHM_DRAW_LINE:
            bresenhamDrawLine();
        break;
        case ALG_HERMITE_DRAW_CURVE:
            hermiteDrawCurve();
    }
}

void TrajectoryHandler::bresenhamDrawLine() {
    float x, y;
    int n = bresenham.n;
    
    x = bresenham.p1.x;
    y = bresenham.p1.y;
    initDrawingTrajectory(bresenham.brush);

    glBegin(bresenham.brush.lineStyle);
        if(bresenham.m >= 0 && bresenham.m <= 1) {
            bresenham._2dy_Minus_2dx = bresenham._2dy - bresenham._2dx;
            bresenham.pk = bresenham._2dy - bresenham.dx;

            while(n--) {
                if(bresenham.pk < 0)
                {
                    glVertex2i(++x, y);
                    bresenham.pk = bresenham.pk + bresenham._2dy;
                }
                else
                {
                    glVertex2i(++x, ++y);
                    bresenham.pk = bresenham.pk + bresenham._2dy_Minus_2dx;
                }
            }
        }
        else if(bresenham.m > 1)
        {
            bresenham._2dx_Minus_2dy = bresenham._2dx - bresenham._2dy;
            bresenham.pk = bresenham._2dx - bresenham.dy;

            while(n--) {
                if(bresenham.pk < 0)
                {
                    glVertex2i(x, ++y);
                    bresenham.pk = bresenham.pk + bresenham._2dx;
                }
                else
                {
                    glVertex2i(++x, ++y);
                    bresenham.pk = bresenham.pk + bresenham._2dx_Minus_2dy;
                }
            }
        }
    glEnd();
}

void TrajectoryHandler::hermiteDrawCurve() {
    float t;
    float x, y;
    
    initDrawingTrajectory(hermite.brush);

    glBegin(hermite.brush.lineStyle);
        for(t = 0; t <= 1; t += hermite.increment)
        {
            x = (2*pow(t, 3) - 3*pow(t, 2) + 1)*hermite.p1.x + (-2*pow(t, 3) + 3*pow(t, 2))*hermite.p4.x
                + (pow(t, 3) - 2*pow(t, 2) + t)*hermite.r1.x + (pow(t, 3) - pow(t, 2))*hermite.r4.x;
            y = (2*pow(t, 3) - 3*pow(t, 2) + 1)*hermite.p1.y + (-2*pow(t, 3) + 3*pow(t, 2))*hermite.p4.y
                + (pow(t, 3) - 2*pow(t, 2) + t)*hermite.r1.y + (pow(t, 3) - pow(t, 2))*hermite.r4.y;
            
            glVertex2i(round(x), round(y));
        }
    glEnd();
}