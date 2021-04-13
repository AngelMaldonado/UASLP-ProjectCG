#####################################################################
## Variables
#####################################################################
# Compiler
CC = g++
# Options
CFLAGS = -Wall -c
# Paths
BIN_DIR = bin/
BIN_TST = $(BIN_DIR)tests/
INCLUDE_DIR = include/
OUT_DIR = out/
OUT_TST = $(OUT_DIR)tests/
SRC_DIR = src/
TEST_DIR = test/

# Source files
OBJ_READER_CPP = $(SRC_DIR)files/OBJFileReader.cpp
GL_INTERFACE_CPP = $(SRC_DIR)gl/GLInterface.cpp
FACE_CPP = $(SRC_DIR)graphics/Face.cpp
MESH_CPP = $(SRC_DIR)graphics/Mesh.cpp
TRAJ_HANLDER_CPP = $(SRC_DIR)graphics/TrajectoryHandler.cpp
VERTEX_CPP = $(SRC_DIR)graphics/Vertex.cpp

# Testing files
TST_TRAJ = test/trajectories/TrajectoriesTest.cpp

# Linkers
CINCLUDES = -lGL -lGLU -lglut

# Make main project
all:
	$(CC) $(CFLAGS) $(SRC_FILES) -o main.exe $(CINCLUDES)
	clean

# Make trajectories Test
# STILL NEEDS TO LINK TO THE TrajectoriesTest.o WHEN COMPILING
traj_tests:${OUT_DIR} ${BIN_DIR} GLInterface.o TrajectoryHandler.o TrajectoriesTest.o
	$(CC) $(OUT_DIR)GLInterface.o $(OUT_DIR)TrajectoryHandler.o $(OUT_TST)TrajectoriesTest.o -o $(BIN_TST)traj_tests $(CINCLUDES)
	./bin/tests/traj_tests

TrajectoriesTest.o: TrajectoryHandler.o GLInterface.o
	$(CC) $(CFLAGS)  $(TST_TRAJ) -o $(OUT_TST)TrajectoriesTest.o

TrajectoryHandler.o: $(TRAJ_HANLDER_CPP)
	$(CC) $(CFLAGS) $(TRAJ_HANLDER_CPP) -o $(OUT_DIR)TrajectoryHandler.o

GLInterface.o: $(GL_INTERFACE_CPP)
	$(CC) $(CFLAGS) $(GL_INTERFACE_CPP) -o $(OUT_DIR)GLInterface.o

${OUT_DIR}:
		mkdir -p ${OUT_DIR}
		mkdir -p ${OUT_TST}
${BIN_DIR}:
		mkdir -p ${BIN_DIR}
		mkdir -p ${BIN_TST}
