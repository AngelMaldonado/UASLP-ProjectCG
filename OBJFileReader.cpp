#include <iostream>
#include <fstream>

using namespace std;

class OBJFileReader {
   private:
	   /*
	    * This fstream object allows the program to search and, if it succeeded, manipulate the file
	    * with I/O operations.
	    */
	   fstream fileReader;
	   // String to store the file's name.
	   string fileName;
   public:
	   bool readFile(string fileName) {
              string content
	      // Read the user-file
	      fileReader.open(fileName, std::fstream::in | std::fstream::out);
	      // If the file was successfully opened
	      if(fileReader.is_open()) {
	         while(getline(fileReader, content))
			 cout << content << "\n";
	         return true;
	      }
	      return false;
	   }
};

int main() {
   OBJFileReader fileReader;

   fileReader.readFile("test.txt");
   return 0;
}
