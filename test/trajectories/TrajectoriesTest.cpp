#include "../../include/trajectories.h"

void givenX1Y1X2Y2_whenMIsEqualUnder1_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 1; int y1 = 2;
    int x2 = 9; int y2 = 4;
    
    // WHEN
    // TrajectoryHanler automatically computes the slope at geoDrawLine()
    trajectoryHandler->setAlgorithm(ALG_GEO_DRAW_LINE);
    trajectoryHandler->setfCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setfIncrement(0.00001);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, 10, 0, 10);

    // THEN
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    givenX1Y1X2Y2_whenMIsEqualUnder1_thenLineDraws(argc, argv);
    return 0;
}