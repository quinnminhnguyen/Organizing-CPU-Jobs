#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstddef>
#include <queue>
#include <string>
#include <math.h>
#include <vector> 
#include "BinaryHeap.h"
using namespace std;


class PriorityQueue{
private:
	BinaryHeap T;
	static const int DEF_SIZE = 8;
public:
	PriorityQueue(int size = DEF_SIZE) : T(size){}	//priority queue constructor

	bool isEmpty() const {return T.isEmpty();}	//check if the queue is empty
	void insertItem(const Item& newItem){	//insert the newitem by calling insert of Binary heap class
		T.insert(newItem);
	}

	void removeMin(){	//delete min element
		if(T.isEmpty()) throw MyException("Empty Queue");
		T.deleteMin();	//delete the min by calling deleteMin of Binary heap class
	}

	void processJob(){
		int i = T.size();

		//cout << "size = " << i <<endl;		
		string fileName = "cpu-jobs-output.txt";	//file output
		ofstream myfile;
	  	myfile.open(fileName);


		for(; i >0; i--){	//go through all of the elements of the queue
			int j = T.Min().getLength();	//get the length of the current min
			for(; j > 0; --j){
				myfile << "Job " <<T.Min().getJobID() <<" with length " <<T.Min().getLength() <<" and priority " <<T.Min().getPriority() <<endl;
				T.Min().setLength(T.Min().getLength() -1);	//decrease the length everytime.
			}
			T.deleteMin();	//delete min element
		}
		myfile << "No more jobs waiting." <<endl; //when everything is finished
		myfile.close(); //close file output
	}
};

