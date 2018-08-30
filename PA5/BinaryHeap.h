#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstddef>
#include <queue>
#include <string>
#include <math.h>
#include <vector> 
using namespace std;


struct MyException : std::range_error {
	explicit MyException(char const* msg = NULL) : range_error(msg) {}
};
class Item{
	private:
		int jobID;	//3 members variable
		int length;
		int priority;
	public:
		Item(const int j = 0, const int l = 0, const int p = 0): jobID(j), length(l), priority(p){}	//default constructor
		const int getJobID() const {return jobID;}	//getters and setters for each variable
		const int getLength() const {return length;}
		const int getPriority() const {return priority;}

		void setJobID(const int j){jobID = j;}
		void setLength(const int l){length = l;}
		void setPriority(const int p){priority = p;}

		bool operator==(const Item& copyItem){	//== overloading operator to know if there is a duplicate of an item
			if(copyItem.getJobID() == jobID && copyItem.getLength() == length && priority == copyItem.getPriority())
				return true;
			return false;
		}

		/*Item& operator=(const Item& copyItem){
			jobID = copyItem.getJobID();
			length = copyItem.getLength();
			priority = copyItem.getPriority();
			return *this;
		}*/
};

class BinaryHeap{
	private:
		static const int DEF_SIZE = 8;
		vector<Item> Items;
		bool comp(Item a, Item b){ //true means a has higher priority than b
			if(a.getPriority() < b.getPriority()){
				return true;	
			}
			else if(a.getPriority() == b.getPriority()){
				if(a.getJobID() < b.getJobID())
					return true;
				return false;
			}
			else{
				return false;
			}
		}
	public:
		BinaryHeap(int size = DEF_SIZE){	//default constructor
			Items.reserve(size);
		}
		int size(){ return Items.size();}

		Item& Min(){	//get min element
			if(Items.empty()) throw MyException("Empty heap");
			return Items.at(0);
		}


		bool isEmpty() const{ return Items.size() == 0;} //check if it is empty

		void insert(Item x){
			Items.push_back(x);	//insert the element to the last position
			int hole = Items.size() -1; //start by last element of the vector
			for(; hole > 0 && comp(x,Items.at((hole-1)/2)); hole = (hole-1)/2){ //walk up 
				Items.at(hole) = Items.at((hole-1)/2);	//if x has higer priority than its parent, then swap its parent
			}
			Items.at(hole) = x;// to make sure that x is in the right place
		}

		void deleteMin(){	//delete min function
			if(Items.empty()) throw MyException("Empty heap");	
			Items.at(0) = Items.at(Items.size() - 1); //swap  the first and last element of the heap
			walkdown(0);	//walk down so that the binary heap can be maintained
			Items.pop_back();// delete the last element
				
		}

		void walkdown(int hole){	//walk down operation
			//cout << "Starting" <<endl;
			//cout << "hole = " <<hole <<endl;
			Item key = Items.at(hole);	
			int child = 0;
			for(; 2*hole + 1 < Items.size(); hole = child){
				child = 2*hole +1; //left child
				if(child != Items.size()-1 && comp(Items.at(child+1),Items.at(child))) //if right child has higher priority than left child
					++child;
				//cout << "stop 1" <<endl;
				if(comp(Items.at(child),key)){// if the current child has higher priority than key
					Items.at(hole) = Items.at(child); //swap 
					//cout <<" stop 2" <<endl;
				}
				else{
					//cout <<"break stop" <<endl;
					break; 
				}
			}
			//cout << "last stop" <<endl;
			
			Items.at(hole) = key; // to make sure that key is in the right place
		}
};

