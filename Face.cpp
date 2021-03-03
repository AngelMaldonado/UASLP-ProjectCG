#include <iostream>

/**
 * >> Face: is a flat surface that forms part of the boundary of a solid object (mesh). 
 *
 * Face class: contains a vector of Vertex objects which describes each vertex of the
 * face, then the position of the face in space.
 **/

class Face {
   private:
	   // Vector of Vertex objects
	   vector<Vertex> vertices;
   public:
	   Face(vector<Vertex> vertices) {
	      this->vertices = vertices
	   }
}
