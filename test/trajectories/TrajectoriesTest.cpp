#include "../../include/trajectories.h"
#include "../../include/glinterface.h"

int main(int argc, char* argv[]) {

    return 0;
}

void givenX1Y1X2Y2_whenMIsEqualUnder1_thenLineDraws(int argc, char* argv[]) {
    // Given
    GLInterface glInterface = GLInterface();
    TrajectoryHandler trajectoryHandler;
    float x1, y1, x2, y2;

    // When
    glInterface.initGLWindow(argc, argv, 300, 300, 100, 100);
    glInterface.initView();
    x1 = 1; y1 = 2;
    x2 = 9; y2 = 4;

    // Then
    trajectoryHandler.geoDrawLine(x1, y1, x2, y2, 1, 1, 1);
    glInterface.startGLloop();
}