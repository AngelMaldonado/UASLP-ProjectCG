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
TST_MODEL_DISPLAY = test/models/ModelDisplayTest.cpp

# Linkers
CINCLUDES = -lGL -lGLU -lglut

# Make main project
all:
	$(CC) $(CFLAGS) $(SRC_FILES) -o main.exe $(CINCLUDES)
	clean

# Make model display Test
model_display_test:${OUT_DIR} ${BIN_DIR} GLInterface.o Face.o Mesh.o Vertex.o OBJFileReader.o ModelDisplayTest.o
	$(CC) $(OUT_DIR)GLInterface.o $(OUT_DIR)Face.o $(OUT_DIR)Mesh.o $(OUT_DIR)Vertex.o $(OUT_DIR)OBJFileReader.o $(OUT_TST)ModelDisplayTest.o -o $(BIN_TST)model_display_test $(CINCLUDES)
	./bin/tests/model_display_test

# Make trajectories Test
traj_tests:${OUT_DIR} ${BIN_DIR} GLInterface.o TrajectoryHandler.o TrajectoriesTest.o
	$(CC) $(OUT_DIR)GLInterface.o $(OUT_DIR)TrajectoryHandler.o $(OUT_TST)TrajectoriesTest.o -o $(BIN_TST)traj_tests $(CINCLUDES)
	./bin/tests/traj_tests

TrajectoriesTest.o: TrajectoryHandler.o GLInterface.o
	$(CC) $(CFLAGS)  $(TST_TRAJ) -o $(OUT_TST)TrajectoriesTest.o

ModelDisplayTest.o:
	$(CC) $(CFLAGS) $(TST_MODEL_DISPLAY) -o $(OUT_TST)ModelDisplayTest.o

TrajectoryHandler.o: $(TRAJ_HANLDER_CPP)
	$(CC) $(CFLAGS) $(TRAJ_HANLDER_CPP) -o $(OUT_DIR)TrajectoryHandler.o

GLInterface.o: $(GL_INTERFACE_CPP)
	$(CC) $(CFLAGS) $(GL_INTERFACE_CPP) -o $(OUT_DIR)GLInterface.o

Face.o: $(FACE_CPP)
	$(CC) $(CFLAGS) $(FACE_CPP) -o $(OUT_DIR)Face.o

Mesh.o: $(MESH_CPP)
	$(CC) $(CFLAGS) $(MESH_CPP) -o $(OUT_DIR)Mesh.o

Vertex.o: $(VERTEX_CPP)
	$(CC) $(CFLAGS) $(VERTEX_CPP) -o $(OUT_DIR)Vertex.o

OBJFileReader.o: $(OBJ_READER_CPP)
	$(CC) $(CFLAGS) $(OBJ_READER_CPP) -o $(OUT_DIR)OBJFileReader.o

${OUT_DIR}:
		mkdir -p ${OUT_DIR}
		mkdir -p ${OUT_TST}
${BIN_DIR}:
		mkdir -p ${BIN_DIR}
		mkdir -p ${BIN_TST}
