#include "../../include/trajectories.h"
#include "../../include/glinterface.h"


TrajectoryHandler trajectoryHandler;
float x1, y_1, x2, y2;
void display() {
    trajectoryHandler.geoDrawLine(x1, y_1, x2, y2, 1, 1, 1);
}

void givenX1Y1X2Y2_whenMIsEqualUnder1_thenLineDraws(int argc, char* argv[]) {
    // Given
    GLInterface glInterface = GLInterface();

    // When
    glInterface.initGLWindow(argc, argv, 300, 300, 100, 100);
    glInterface.initView();
    x1 = 1; y_1 = 2;
    x2 = 9; y2 = 4;

    // Then
    glInterface.setDisplayFunction(display);
    glInterface.startGLloop();
}

int main(int argc, char* argv[]) {
    givenX1Y1X2Y2_whenMIsEqualUnder1_thenLineDraws(argc, argv);
    return 0;
}