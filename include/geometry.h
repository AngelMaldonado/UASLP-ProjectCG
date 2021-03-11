/// Libraries
#ifndef std

using namespace std;

#endif
#pragma once
#include <iostream>
#include "containers.h"

/**
 * >> Vertex: is a point where two or more curves, lines, or edges meet.
 *
 * Vertex class: that contains x, y and z coordinates which describes the
 * position of the Vertex in the space.
 **/
class Vertex {
private:
    // Index to identify the vertex
    int index;
    // Coordinate in x.
    double x;
    // Coordinate in y.
    double y;
    // Coordinate in z.
    double z;

public:
    // Constructor for Vertex with user-defined coordinates.
    Vertex(double x, double y, double z);

    // Constructor for Vertex with user-defined coordinates and index/id
    Vertex(double x, double y, double z, int index);

    // Shows the coordinates formatted with ',' and '()'
    void showCoordinatesFormatted();

    // Shows the coordinates x, y and z separated by a single space
    void showCoordinates();

    // Gets the number of vertex (minimum index is 0)
    int getIndex();

    // Returns the x coorinate
    double getX();

    // Returns the y coordinate
    double getY();

    //Returns the z coordinate
    double getZ();

    // Returns an array with the coordinates
    double * getCoordinates();
};

/**
 * >> Face: is a flat surface that forms part of the boundary of a solid object (mesh).
 *
 * Face class: contains a vector of Vertex objects which describes each vertex of the
 * face, then the position of the face in space.
 **/
class Face {
private:
    // Vector of Vertex objects
    vector <Vertex> vertices;
public:
    // Constructor for the Face with a vector of Vertices
    Face(vector <Vertex> vertices);

    // Shows the stored Face with simple format
    void showsFaceFormatted();

    // Shows the Vertices that the Faces are made of
    void showFace();

    // Returns the vector of Vertices
    vector <Vertex> getVertices();
};


/**
 * >> Mesh: a polygon mesh is a collection of vertices, edges and faces that defines the shape of a
 * >>       polyhedral object.
 *
 * Mesh class: it has only a list of Face objects, since Face class has a vector of Vertex objects
 * it's not necessary to make another list of those in this class. Mesh can interact with Vertex's and
 * Face's objects through their methods.
 **/
class Mesh {
private:
    string name;
    vector <Face> faces;
    int vertexIndex;
    vector <Vertex> vertices;

public:
    // If there is more than one Mesh, last index of past Mesh is required
    Mesh(string name, int lastIndex);

    // New mesh
    Mesh(string name);

    // Add a new Vertex to the Mesh passing a vector with its coordinates
    bool addVertex(vector<double> coordinates);
    
    // Add a new Face to the Mesh passing a vector with its vertices
    bool addFace(vector <Vertex> vertices);

    Face getFace(int index);

    // Returns the list of Faces that compose the Mesh
    vector<Face> getFaces();

    // Returns the last Face added to the Mesh
    Face getLastFace();

    // Returns the vector of Vertex that compose the Mesh
    vector<Vertex> getVertices();

    // Returns the last Vertex added to the Mesh
    Vertex getLastVertex();

    // Returns certain Vertex by index
    Vertex getVertex(int vertexIndex);

    // Returns the Mesh name
    string getMeshName();

    // Returns the Vertex index of the vector
    int getVertexIndex();
};