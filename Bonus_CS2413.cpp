#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // used for remove
#include <math.h>

using namespace std;

/*
	HashTableVector is a hash table represented as a vector. It uses generics rather than a single data type.
	The hashing function, H(x) = firstLetter - A, essentially defines keys reative to 'A' = 0, so for strictly alphabetic values a word starting with 'Z' has a key of 25.
	HashTableVector contsins methods for insertion, removal, display, as well as a function for computing the hashed key for a given value.
*/
template <class DT>
class HashTableVector
{	
  protected:
    vector< vector < DT > >* htable;

  public:
    HashTableVector<DT>();
    ~HashTableVector();
    void insert(string str); // Insertion method calculates hash key before inserting.
    int hashing(char a); // H(x) = a - A (as ASCII values).
	void displayTable(); // Displays numeric keys followed by stored values.
	void remove(string str); // Removal method.
	int find(string a); // searches for a given value.
};

// Default constructor is the only constructor.
template <class DT>
HashTableVector<DT>::HashTableVector(){
    htable = new vector< vector < DT > >[0];
}

// Destructor deletes htable.
template <class DT>
HashTableVector<DT>::~HashTableVector(){
    delete [] htable;
}

// Insert generates the key, resizes the vector of vectors to have space for new keys if necessary, then adds the given value to the end of the appropriate key vector.
template <class DT>
void HashTableVector<DT>::insert(string str){

	//////////////////////////////////////////////////////////////////////////////////
	int foundBool = find(str);

	if(foundBool == -1) {
		int key = hashing(str[0]);

		if (key >= htable->size()){
			htable->resize(key+1);
		}

		htable->at(key).push_back(str);
		// cout << (*htable)[index][0] << endl;
	}
	else {
		cout << "element to be added already existent: " << str << endl;
	}
	//////////////////////////////////////////////////////////////////////////////////

	/*
    int key = hashing(str[0]);

	// resize if necessary
	if(htable->size() <= key){
		htable->resize(key+1); 
	}

	htable->at(key).push_back(str);
	*/
}

// "find" helper method lets us verify if a value has already been added
template <class DT>
int HashTableVector<DT>::find(string a){

	for (int i = 0; i < this->htable->size(); i++) {
		for (int j = 0; j < this->htable->at(i).size(); j++)
			if(this->htable->at(i).at(j) == a)
				return i; 
	}

return -1;
}

// Our hash function is a simple sum of two ASCII values.
template <class DT>
int HashTableVector<DT>::hashing(char a){
	return (int) (a - 'A');
}

// A comamand-line display method (keyA: value1, value2, ...)
template <class DT>
void HashTableVector<DT>::displayTable(){

	// a temp value for storing and monitoring the length of each key vector.
	int vecLength;

	// execute for each key in table
	for(int i = 0; i < htable->size(); i ++){

		cout << i << ": ";
		vecLength = htable->at(i).size();

		// execute for each value in key vector EXCEPT the last one
		for(int j = 0; j < vecLength - 1; j++){

			cout << htable->at(i)[j] << " => ";
		}

		// gets last value
		if(vecLength > 0)
			cout << (htable->at(i)[vecLength - 1]);
		cout << endl;
	}
}

// removal method calculates key before searching a specified key vector.
template <class DT>
void HashTableVector<DT>::remove(string str){

	int key = hashing(str[0]);
	int vecLength = htable->at(key).size();
	
	for(int i = 0; i < vecLength; i ++){
		if(htable->at(key)[i] == str){
			htable->at(key).erase(htable->at(key).begin() + i);
			return;
		}
	}
}




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
						h1->displayTable();
						break;
					}
			case 'I':
					{
						cin >> tempName;
						cout << "adding " << tempName << endl;
						h1->insert(tempName);
						break;
					}
			case 'R':
					{
						cin >> tempName;
						cout << "removing " << tempName << endl;
						h1->remove(tempName);
						break;
					}
		} // switch case
	} // while

	delete h1;

    return 0;
}