//Shreya Gogini
//PetHeap.h
//Purpose : Holds the function signatures for the PetHeap class
//          and has the constructor for the pet* elements in the heap
#include <iostream>
#include <vector>

using namespace std;

//struct for pet variables in the heap
struct Pet {
    string name;
    int arrival;
    //pet contructor
    Pet (string pet_name, int pet_arrival){
      name = pet_name;
      arrival = pet_arrival;
    }
};

class PetHeap{
    private:
        vector<Pet*> petHeap; //new heap
        void percolateUp(int index); //sorts new inputs
        void percolateDown(int index); //sorts after output
        void deleteMin(); //removes min value
        Pet* peekMin(); //looks at min value
    
    public:
        PetHeap(); //constructor
        void insert(Pet*pet); //insert into heap
        Pet* adoptOldestPet(); //adopts pet at top at the hear
        int numPets(); //returns number of elements in heap
        void displayPets(); //displays pets in level order
        void clear(); //deletes the heap

        void tests(); //runs the tests

};

