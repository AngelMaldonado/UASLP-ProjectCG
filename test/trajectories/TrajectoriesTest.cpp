#include "../../include/trajectories.h"

void givenX1Y1X2Y2_whenGeometricAlgorithmAndSlopeIs0_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    float x1 = 1; float y1 = 2;
    float x2 = 9; float y2 = 4;
    
    // WHEN
    // TrajectoryHanler automatically computes the slope at geoDrawLine()
    trajectoryHandler->setAlgorithm(ALG_GEO_DRAW_LINE);
    trajectoryHandler->setfCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setfIncrement(0.00001);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIs0_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 250;
    int x2 = 400; int y2 = 250;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_DDA_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIsBetween0And1_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 100;
    int x2 = 400; int y2 = 250;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_DDA_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIs1_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 100;
    int x2 = 400; int y2 = 400;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_DDA_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIsMoreThan1_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 100;
    int x2 = 300; int y2 = 400;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_DDA_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIsUndefined_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 100;
    int x2 = 100; int y2 = 400;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_DDA_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenbBresenhamAlgorithmAndSlopeIs0_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 250;
    int x2 = 400; int y2 = 250;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_BRSNHM_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenBresenhamAndSlopeIsBetween0And1_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 100;
    int x2 = 400; int y2 = 250;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_BRSNHM_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenBresenhamAlgorithmAndSlopeIs1_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 100;
    int x2 = 400; int y2 = 400;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_BRSNHM_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenBresenhamAlgorithmAndSlopeIsMoreThan1_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 100;
    int x2 = 300; int y2 = 400;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_BRSNHM_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenX1Y1X2Y2_whenBresenhamAlgorithmAndSlopeIsUndefined_thenLineDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int x1 = 100; int y1 = 100;
    int x2 = 100; int y2 = 400;

    // WHEN
    // TrajectoryHanler automatically computes the slope at ddaDrawLine()
    trajectoryHandler->setAlgorithm(ALG_BRSNHM_DRAW_LINE);
    trajectoryHandler->setiCoordinates(x1, y1, x2, y2);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

void givenP1P4R1R4_whenHermiteAlgorithm_thenCurveDraws(int argc, char* argv[]) {
    // GIVEN
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    int xP1 = 20; int yP1 = 50;
    int xP4 = 100; int yP4 = 50;
    int xR1 = 20; int yR1 = 90;
    int xR4 = 100; int yR4 = 10;

    // WHEN
    trajectoryHandler->setAlgorithm(ALG_HERMITE_DRAW_CURVE);
    trajectoryHandler->setHermiteValues(xP1, yP1, xP4, yP4, xR1, yR1, xR4, yR4);
    trajectoryHandler->setfIncrement(0.00001);
    trajectoryHandler->setDrawingValues(1, GL_POINTS, 1, 1, 1);
    glInterface->setInstance(trajectoryHandler);
    glInterface->setView2D(GL_PROJECTION, 0, DEF_WINDOW_SIZE, 0, DEF_WINDOW_SIZE);

    // THEN
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    // ***************** GEOMETRIC ALGORITHM TESTS *****************
    //givenX1Y1X2Y2_whenGeometricAlgorithmAndSlopeIs0_thenLineDraws(argc, argv);

    // ***************** DDA ALGORITHM TESTS *****************
    //givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIs0_thenLineDraws(argc, argv);
    //givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIsBetween0And1_thenLineDraws(argc, argv);
    //givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIs1_thenLineDraws(argc, argv);
    //givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIsMoreThan1_thenLineDraws(argc, argv);
    //givenX1Y1X2Y2_whenDdaAlgorithmAndSlopeIsUndefined_thenLineDraws(argc, argv);

    // ***************** BRESENHAM ALGORITHM TESTS *****************
    //givenX1Y1X2Y2_whenbBresenhamAlgorithmAndSlopeIs0_thenLineDraws(argc, argv);
    //givenX1Y1X2Y2_whenBresenhamAndSlopeIsBetween0And1_thenLineDraws(argc, argv);
    //givenX1Y1X2Y2_whenBresenhamAlgorithmAndSlopeIs1_thenLineDraws(argc, argv);
    //givenX1Y1X2Y2_whenBresenhamAlgorithmAndSlopeIsMoreThan1_thenLineDraws(argc, argv);
    //givenX1Y1X2Y2_whenBresenhamAlgorithmAndSlopeIsUndefined_thenLineDraws(argc, argv);

    // ***************** HERMITE ALGORITHM TESTS *****************
    givenP1P4R1R4_whenHermiteAlgorithm_thenCurveDraws(argc, argv);
    return 0;
}