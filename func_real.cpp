#include "header.h"
void Queue::push(int data)
{
	if (is_empty()||head->data>data) // if queue if empty , create first element in queue
	{
		head = new el(data, head);
		Size++;
	}
	else // if not
	{
		el* current = this->head; // take pointer on 1 element
		bool negative = false;  
		if (data < 0) { data = data * -1; negative = true; }

		while (current->next!=nullptr && data%10>=current->next->data%10) 
		{
			current = current->next;
		}
		if (negative) { data = -data; }
		el* newEl = new el(data, current->next);
		current->next = newEl;
		Size++;
		
	}
}

void Queue::pop()
{
	el* temp = this->head;
	head = head->next;
	
	delete temp;
	Size--;
}

int Queue::first_info()
{
	if (is_empty()) throw QUEUE_EMPTY_MSQ;
	else return head->data;
	
}

bool Queue::is_empty()
{
	if (this->head == nullptr) return true;
	return false;
}

int Queue::last_info()
{
	if (is_empty()) throw QUEUE_EMPTY_MSQ;
	else
	{
		el* current = this->head;
		while (current->next != nullptr) current = current->next;
		return current->data;
	}
}
Queue::Queue()
{
	head=nullptr;
	Size = 0;
}