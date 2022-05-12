
#include "header.h"


int main()
{
	Queue q;
	char c;
	do {
		system("cls");
		cout << "a. Add element." << endl;
		cout << "d. Delete element." << endl;
		cout << "s. Queue lenght." << endl;
		cout << "f. Print first element info" << endl;
		cout << "l. Print last element info" << endl;
		cout << "q. Quit." << endl;
		cin >> c;
		switch (c)
		{
		case 'a':
			system("cls");
			int x;
			cout << "Enter your element:";
			cin >> x;
			q.push(x);
			cout << "Element was added to queue"<<endl;
			break;
		case 'd':
			system("cls");
			if (q.get_size() == 0)
			{
				cout << "List is empty!" << endl;
			}
			else
			{
				q.pop();
				cout << "Element was deleted from queue"<<endl;
			}
			break;
		case 's':
			system("cls");
				if (q.is_empty())
				{
					cout << "List is empty!" << endl;
					
				}
				else
				{
					cout << "Queue lenght is : \t " << q.get_size() << endl;
				}
				break;
		case 'f':
			system("cls");
			try 
			{
				cout << "Element is : \t" << q.first_info() << endl;
				
			}
			catch (const char* msg)
			{
				cerr << "Error!" << endl << msg << std::endl;
			}
			break;
		case 'l':
			system("cls");
			try
			{
				cout << "Element is : \t" << q.last_info() << endl;

			}
			catch (const char* msg)
			{
				cerr << "Error!" << endl << msg << std::endl;
			}
			break;
		case 'q':
			exit(0);
			break;
		default:;
		}
		system("pause");
	} while (true);

	return 0;

}