#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // used for remove
#include <math.h>

using namespace std;

template <class DT>
class HashTableVector
{
  protected:
    vector< vector < DT > >* htable;		// vector of vector hash table

  public:
    HashTableVector<DT>();					//TODO: default constructor
    ~HashTableVector(); 					//TODO: destructor
    void insert(string str); 				//TODO: insert a string into the right spot in the hash table
    int hashing(char a); 					//TODO: hash function - returns the key
	void displayTable(); 					//TODO: display the contents of hash table
	void remove(string str); 				//TODO: removes a name from hash table
	//Add more helper functions if necessary
};

int main()
{
	string tempName; 						// to store the name using cin

	HashTableVector<string>* h1 = new HashTableVector<string>(); // hash table object for vector

	char option; 							// to store the option from redirected input

    while(cin >> option)
    {
        switch(option){
			case 'D':
					{
						//TODO: call display method
						break;
					}
			case 'I':
					{
						cin >> tempName;
						cout << "adding " << tempName << endl;
						//TODO: call insert method
						break;
					}
			case 'R':
					{
						cin >> tempName;
						cout << "removing " << tempName << endl;
						//TODO: call remove method
						break;
					}
		} // switch case
	} // while

	delete h1;
    return 0;
}
