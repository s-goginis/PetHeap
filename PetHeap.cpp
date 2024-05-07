//Shreya Gogini
//PetHeap.cpp
//Purpose : cpp file for the functions that are in the PetHeap class. 
//          Here, we can use the functions to adjust the pet heap and
//          maintain the heap function

#include <iostream>
#include "PetHeap.h"

using namespace std;

//desc : constructor for the Petheap class
//pre : vector stl is initialized
//post : petHeap is created with type Pet pointers
PetHeap :: PetHeap(){
    petHeap = vector<Pet*>();
}

//desc : percolate up function which sorts inputs
//pre : insert function sends correct input
//post : sorted heap is finished and satisfies the heap property
void PetHeap :: percolateUp(int index){
    //base case
    if(index == 0){
        return;
    }
    //finding the index of the parent to compare
    int parentIndex = (index-1)/2;
    //if the order is already correct, return
    if(petHeap[index]->arrival > petHeap[parentIndex]->arrival){
        return;
    }
    //if the parent is greater than the input, 
    //swap and percolate up to check again
    if(petHeap[index]->arrival < petHeap[parentIndex]->arrival){
        Pet *temp = petHeap [parentIndex];
        petHeap[parentIndex] = petHeap[index];
        petHeap[index] = temp;
        percolateUp(parentIndex);

    }
}

//desc : percolate down function to sort heap after deletion
//pre : called by deleteMin with correct input
//post : heap is sorted and satisfies heap property
void PetHeap :: percolateDown(int index){
    //gets the number of elements in the heap
    int length = petHeap.size();
    //gets the indexes of the right and left child of the current index
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;
    //saves a variable for the current index since we change it
    int new_index = index;
    //no right child
    if(rightChild >= length){
        //no left child, index is a leaf node
        if(leftChild >= length){
            return;
        }
        //if no right child, set as left child
        else{
            new_index = leftChild;
        }
    }
    else{
        //comparing parent with children to sort in min heap order
        if(petHeap[leftChild]->arrival <= petHeap[rightChild]->arrival){
            if(petHeap[new_index]->arrival > petHeap[leftChild]->arrival)
                new_index = leftChild;
        }
        else{
            new_index = rightChild;
        }
    }
    //swapping the indexes and percolating down again to sort
    if(new_index != index){
        Pet *temp = petHeap[new_index];
        petHeap[new_index] = petHeap[index];
        petHeap[index] = temp;

        percolateDown(new_index);
    }

}
//desc : deletes the minimum value (root)
//pre : tree exists
//post : root is deleted and a call of percolate down restores heap property
void PetHeap :: deleteMin(){
    //getting the size of the heap
    int length = petHeap.size();
    //printing for reference
    cout << "Deleting "<<petHeap[0]->name<< " "<< petHeap[0]->arrival << endl;
    //swap
    Pet *temp = petHeap[0];
    petHeap[0] = petHeap[length-1];
    petHeap[length-1] = temp;
    //delete the last element
    petHeap.pop_back();
    //restore heap property
    percolateDown(0);
    
}

//desc : adopts the oldest pet in the heap
//pre : calls to functions are accessible
//post : returns the pet that was adopted 
Pet* PetHeap :: adoptOldestPet(){
    //getting the size of the heap
    int length = petHeap.size();
    //checking if the heap is empty
    if(length == 0){
        cout << "Heap is empty" << endl;    
    }
    else{
        //output for user
        cout << "You are adopting :" << peekMin()->name 
             << " " << peekMin()->arrival << endl;
        //saving return pet
        Pet *temp = peekMin();
        //deleting the adopted pet and restoring heap property
        deleteMin();
    
        return temp;
    }
    return nullptr;
}

//desc : inserts a new pet into the heap
//pre : new pet is initialized correctly
//post : pet is inserted and heap condition is satisfied
void PetHeap :: insert(Pet* pet){
    //new pet is at the end of the heap
    petHeap.push_back(pet);
    //getting the index of the current spot of the pet
    int index = petHeap.size() - 1;
    //getting parent index to compare
    int parent_index = (index - 1)/2;
    
    //comparing with parent index and swapping as needed
    while(index > 0 && petHeap[parent_index] > petHeap[index]){
        Pet *temp = petHeap[index];
        petHeap[index] = petHeap[parent_index];
        petHeap[parent_index] = temp;

        index = parent_index;
    }
    //calling percolateUp to maintain heap condition
    percolateUp(index);
   

}

//desc : returns the root 
//pre : tree exists and return value is stored appropriately
//post : none aside from description
Pet* PetHeap :: peekMin(){
    //min value is at the top for min heap
    return petHeap[0];

}

//desc : returns the number of pets in the heap
//pre : vector commands are initialized
//post : none aside from description
int PetHeap :: numPets(){
    return petHeap.size();
}

//desc : displays the pet heap in level order
//pre : heap exists
//post : none aside from description
void PetHeap :: displayPets(){
    int length = petHeap.size();
    //runs through the heap until it reaches the end
    for(int i = 0; i < length; i++){
        cout << petHeap[i]->name << " " << petHeap[i]->arrival << endl;
    }
}

//desc : function to delete the memory after the code is completed
//pre : function called appropriately
//post : heap is properly deallocated without memory leak
void PetHeap :: clear(){
    int length = petHeap.size();
    int num = 0;
    //as long as the heap isn't empty and the current index is within bounds
    while(!petHeap.empty() && num < length){
        //deletes the pet pointer at the index
        delete petHeap[num];
        //increments the index
        num++;
    }
}

//desc : test function that tests all the commands
//pre : functions are initialized
//post : none aside from description
void PetHeap :: tests(){
    //inserting pets
    cout << "1. Inserting pets" << endl;
    insert(new Pet("Max", 1));
    insert(new Pet("Jill", 4));
    insert(new Pet("Brad", 10));
    insert(new Pet("Charlie", 2));
    insert(new Pet("Phil", 29));
    insert(new Pet("Rick", 3));
    insert(new Pet("Sally", 13));
    insert(new Pet("Minnie", 5));
    insert(new Pet("Tigger", 8));
    insert(new Pet("Garfield", 7));
    /*insert(new Pet("Pusheen", 1));
    insert(new Pet("Garfield", 7));
    insert(new Pet("Simba", 4));
    insert(new Pet("Tigger", 8));
    insert(new Pet("Felix", 3));*/

    //displaying in level order
    cout << "2. Displaying the heap" << endl;
    displayPets();
    cout << endl;

    //adopting some pets
    cout << "3. Adopting Pets" << endl;
    adoptOldestPet();
    //displayPets();
    cout << endl;

    adoptOldestPet();
    //displayPets();
    cout << endl;
    
    adoptOldestPet();
    //displayPets();
    cout << endl;

    //number of pets left
    cout << "4. Display number of pets left" << endl;
    cout << numPets() << " are left "<< endl;

    //adopting the rest of the pets
    cout << "5. Adopt the rest of the pets" << endl;
    int num = numPets();
    while(num > 0){
        adoptOldestPet();
        //displayPets();
        cout << endl;
        num--;
    }
    //adopting when heap is empty
    cout << "6. Attempt to adopt when no pets are available" << endl;
    adoptOldestPet();

}

