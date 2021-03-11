#include "../../include/glinterface.h"

GLInterface::GLInterface() {}

void GLInterface::initGLWindow(int argc, char** argv, int width, int height, int posX, int posY) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (width, height); 
    glutInitWindowPosition (posX, posY);
    glutCreateWindow (":: M E S H ::");
}

void GLInterface::initView(void) {
    // Select clearing (background) color
    glClearColor (0.0, 0.0, 0.0, 0.0);

    // Initialize viewing values
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);

    // Rotate the whole scene so that three faces of the cube are seen
    glRotatef (30.0, 1.0, 1.0, 1.0);
}

void GLInterface::setDisplayFunction(void (*callback)()) {
    glutDisplayFunc(callback);
}

void GLInterface::startGLloop() {
    glutMainLoop();
}

/*
void GLInterface::displayMesh() {
    // Clear all pixels
    glClear (GL_COLOR_BUFFER_BIT);

    // Define color
    glColor3f (1.0, 1.0, 1.0);

    for (Face face : mesh.getFaces()) 
    {
        glBegin(GL_LINE_LOOP);
        for (Vertex vertex : face.getVertices())
        {
            glVertex3f(vertex.getX(), vertex.getY(), vertex.getZ());
        }
        glEnd();
    }
    // Start processing buffered OpenGL routines 
    glFlush ();
}*/