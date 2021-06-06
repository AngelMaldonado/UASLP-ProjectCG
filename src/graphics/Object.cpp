#include "../../include/geometry.h"
#include "../../include/transformations.h"

Object::Object(){}

Object::Object(vector<Mesh> meshes) {
    this->meshes = meshes;

    // Find a way to compute the center of the object to the fine the object's origin
    origin.x = origin.y = origin.z = 0;
    
    drawOrigin = true;
    brush.lineStyle = GL_LINE_LOOP;
    brush.red = brush.green = brush.blue = 1;
}

vector<Mesh> &Object::getMeshes() {
    return meshes;
}

Coordinates &Object::getOrigin() {
    return origin;
}

void Object::setOrigin(float x, float y, float z) {
    origin.x = x;
    origin.y = y;
    origin.z = z;
    TransformationsHandler::translateObject(*this, x, y, z);
}

void Object::showOrigin() {
    drawOrigin = true;
}

void Object::hideOrigin() {
    drawOrigin = false;
}

void Object::draw() {
    // Local array of primitive coorinates of vertices (x, y, z)
    double* vertices;

    // Define color
    glColor3f (brush.red, brush.green, brush.blue);

    // For each stored mesh in vector<Mesh>
    for(Mesh mesh : meshes)
    {
        // For each Face that mesh has
        for (Face face : mesh.getFaces()) 
        {
            glBegin(brush.lineStyle);
            for(int vertex : face.getVerticesIndices())
            {
                vertices = mesh.getVertex(vertex).getCoordinates();
                glVertex3f(vertices[0], vertices[1], vertices[2]);
            }
            glEnd();
        }
    }

    if(drawOrigin) {
        glPointSize(3);
        glColor3f(0, 1, 0);
        glBegin(GL_POINTS);
            glVertex3i(round(origin.x), round(origin.y), round(origin.z));
        glEnd();
    }
}