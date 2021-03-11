//
// Created by Angel Maldonado on 3/4/2021.
//
#include "../include/objreader.h"
#include "../include/glinterface.h"

vector<Mesh> meshes;

void displayMesh() {
    // Clear all pixels
    glClear (GL_COLOR_BUFFER_BIT);
    // Define color
    glColor3f (1.0, 1.0, 1.0);
    for(Mesh mesh : meshes)
    {
        for (Face face : mesh.getFaces()) 
        {
            glBegin(GL_LINE_LOOP);
            for (Vertex vertex : face.getVertices())
            {
                glVertex3f(vertex.getX(), vertex.getY(), vertex.getZ());
            }
            glEnd();
        }
    }
    // Start processing buffered OpenGL routines 
    glFlush ();
}

int main(int argc, char* argv[]) {
    OBJFileReader fileReader;
    GLInterface glInterface;

    meshes = fileReader.readFile("models/four_figs.obj", 'n');

    //meshes.front().getFaces().front().showsFaceFormatted();
    
    glInterface.initGLWindow(argc, argv, 300, 300, 100, 100);
    glInterface.initView();
    glInterface.setDisplayFunction(displayMesh);
    glInterface.startGLloop();

    return 0;
}

