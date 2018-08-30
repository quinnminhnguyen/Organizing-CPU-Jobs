#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <queue>
#include <string>
#include <math.h>
#include <vector> 
//#include "BinaryHeap.h"
#include "PriorityQueue.h"
using namespace std;








int main(){
	
	/*Item item1(281,5,12);
	Item item2(825,2,2);
	Item item3(111,10,19);
	Item item4(382,3,-7);
	*/

	/*Item item1(7,7,8);
	Item item2(1,2,11);
	Item item3(6,2,15);
	Item item4(3,8,3);
	Item item5(2,10,-16);
	Item item6(8,3,-3);
	Item item7(4,7,-16);
	Item item8(9,9,-3);
	Item item9(10,9,-3);
	Item item10(10,9,-3);
	Item item11(5,9,11);
 	
	PriorityQueue pq;
	pq.insertItem(item1);
	pq.insertItem(item2);
	pq.insertItem(item3);
	pq.insertItem(item4);
	pq.insertItem(item5);
	pq.insertItem(item6);
	pq.insertItem(item7);
	pq.insertItem(item8);
	pq.insertItem(item9);
	pq.insertItem(item10);
	pq.processJob();*/
	

	PriorityQueue pq;	//initiate a priority queue
	string fileName;	//file input
	cout << "Please input our file name: ";
	cin >> fileName;

	ifstream inFS(fileName);
  	inFS.ignore(1000, '\n');	//skip the first line

  	if(!inFS.is_open())
  		cerr << "ERROR: File Failed to Open!" <<endl;	//if failed to read the fileName

  	int jobID, length, priority;	//3 members of Item
  	string jobIDStr, lengthStr, priorityStr;
  	Item oldTemp(0,0,0); 

  	//int count = 0;
  	while(inFS.good()){
  		getline(inFS,jobIDStr,',');	//reading each type as a string and then covert it into int
  		if(!inFS.eof())
  			jobID = stoi(jobIDStr);

  		getline(inFS,lengthStr,',');
  		if(!inFS.eof())
  			length = stoi(lengthStr);

  		getline(inFS,priorityStr,'\n');
  		if(!inFS.eof())
  			priority = stoi(priorityStr);

  		Item temp(jobID,length, priority);
  		if(temp == oldTemp)	//to avoid reading the last element twice
  			break;
  		oldTemp = temp;
  		pq.insertItem(temp);

  		//count++;
  	}

  	//cout << "#elements =  " <<count <<endl; 
  	inFS.close();

  	//process jobs

	pq.processJob();	//start by processing jobs
 	
	return 0;
}
