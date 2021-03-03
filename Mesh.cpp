#include <iostream>

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
	   list<Face> faces;
   public:
}
