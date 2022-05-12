using namespace std;
#include <iostream>
#define QUEUE_EMPTY_MSQ "Queue is empty"

class Queue
{
public:
	Queue();
	void push(int); // add element to queue
	void pop(); // delete element from queue
	int get_size() { return Size; }  // queue lenght
	int first_info(); // first element data
	int last_info(); // last element data
	bool is_empty(); // is the queue empty?
	
	

private:
	
	class el { // class element in queue
	public:
		el* next; // pointer to next element in queue
		int data; // data which contains element
		el(int data = 0, el* next = nullptr)  // element constructor
		{
			this->data = data; 
			this->next = next; // distribution input variables in to element

		}
	
};
	el* head;  // first element
	unsigned int Size; // size counter
	
};

