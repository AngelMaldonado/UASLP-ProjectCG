#include "../../include/trajectories.h"

void givenX1Y1X2Y2_whenMIsEqualUnder1_thenLineDraws(int argc, char* argv[]) {
    // Given
    TrajectoryHandler* trajectoryHandler = new TrajectoryHandler();
    GLInterface* glInterface = new GLInterface();
    
    // When
    trajectoryHandler->setfCoordinates(20, 20, 200, 200);
    glInterface->setInstance(trajectoryHandler);

    // Then
    glInterface->startFramework(argc, argv);
}

int main(int argc, char* argv[]) {
    givenX1Y1X2Y2_whenMIsEqualUnder1_thenLineDraws(argc, argv);
    return 0;
}