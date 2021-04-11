#####################################################################
## Variables
#####################################################################
# Compiler
CC = g++
# Paths
SRC_DIR = src/
INCLUDE_DIR = include/
TEST_DIR = test/
# Source files
SRC_FILES = $(SRC_DIR)*.cpp
# Testing files
SRC_TST_TRAJECTORIES = $(SRC_DIR)/graphics/TrajectoryHandler.cpp $(SRC_DIR)/gl/GLInterface.cpp
TRAJECTORIES_TEST = test/trajectories/TrajectoriesTest.cpp
# Options
CFLAGS=-Wall
# Include
CLINKER = -L/MinGW/include/GL
CINCLUDES = -lGL -lGLU -lglut

all:
	$(CC) $(CFLAGS) $(SRC_FILES) -o main.exe $(CINCLUDES)
	clean

trajectoriesTest:
	$(CC) $(CLINKER) $(CFLAGS) -o test.exe $(SRC_TST_TRAJECTORIES) $(TRAJECTORIES_TEST) $(CINCLUDES)
	clean

clean:
	rm -rf *o hello
