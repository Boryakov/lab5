#include "header.h"
void Queue::push(int data)
{
	bool negative = false;  // ** if the number is negative , his remainder of division by 10 is not his last digit,
						// for comfort we turn this digit to positive and bool negative to true ,
						// and after element founding , we change his back to negative
	if (data < 0) { data = data * -1; negative = true; } //**

	if (is_empty()||data%10<this->head->data%10) // if queue if empty , create first element in queue
	{
		if (negative) { data = - data; }
		head = new el(data, head);
		Size++;
	}
	else // if not
	{
		el* current = this->head; // take pointer on 1 element

		while (current->next!=nullptr && data%10 >= current->next->data%10)  // founding place for our element
		{
			current = current->next;
		}

		if (negative) { data = - data; }//**

		el* newEl = new el(data, current->next); // creating new element with pointer on next element
		current->next = newEl; // previous element now pointed on our new element
		Size++; // increase queue size
		
	}
}

void Queue::pop()
{
	el* temp = this->head; // create first element tempoary pointer
	head = head->next; // second element in queue now is first element
	
	delete temp; // delete old first element
	Size--; // decrease queue size
}

int Queue::first_info()
{
	if (is_empty()) throw QUEUE_EMPTY_MSQ; // if queue is empty throw error
	else return head->data; // else return first element data
	
}

bool Queue::is_empty()
{
	if (this->head == nullptr) return true;
	return false;
}

int Queue::last_info()
{
	if (is_empty()) throw QUEUE_EMPTY_MSQ; // if queue is empty throw error
	else
	{
		el* current = this->head; 
		while (current->next != nullptr) current = current->next; // else looking for last element
		return current->data; // return last element
	}
}
Queue::Queue()
{
	head=nullptr; // while first element wasn't added , it is nullpointer
	Size = 0; // size initialization
}