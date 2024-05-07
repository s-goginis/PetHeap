//Shreya Gogini
//lab4.cpp
//Purpose : Heap basic operations for a min heap of Pets
//          by arrival, sorting and deleting
#include <iostream>
#include "PetHeap.h"

using namespace std;

int main(){
    //creating an instance of the class
    PetHeap heap;

    int choice; //for the user's choice
    bool repeat = true; //whether or not to continue

    do{ 
        //output
        cout << "Welcome to Lab 4 on Basic Heap Operation." << 
            "What would you like to test?"<< endl;
        cout << "1. Insert Pet" << endl;
        cout << "2. Adopt Pet" << endl;
        cout << "3. Number of Pets" << endl;
        cout << "4. Display Pets" << endl;
        cout << "5. Run Tests" << endl;
        cout << "6. Exit" << endl;
        cin >> choice; //get input

        string pet_name; //name of pet
        int arrival_num; //arrival number

        switch(choice){
            //insert
            case 1:
                cout << "Enter the pet name: " << endl;
                cin >> pet_name;
                cout << "Enter the pet's arrival number: " << endl;
                cin >> arrival_num;
                heap.insert(new Pet(pet_name, arrival_num));
                break;
            //adopt oldest pet
            case 2:
                heap.adoptOldestPet();
                break;
            //number of pets
            case 3:
                cout<<"The shelter heap has "<<heap.numPets()<<" pets"<<endl;
                break;
            //display heap
            case 4:
                cout << "Displaying Pets: " << endl;
                heap.displayPets();
                break;
            //run tests
            case 5:
                cout << "Running tests..." << endl;
                heap.tests();
                break;
            //exit
            case 6:
                repeat = false;
                cout << "Exiting..." << endl;
                break;
            //invalid input
            default:
                cout << "Error. Invalid Input." << endl;
                repeat = false;
                break;
        }
    }while(repeat == true);

    //deallocating the memory
    heap.clear();
    
    

    return 0;
}
