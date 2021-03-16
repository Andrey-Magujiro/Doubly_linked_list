#include <iostream>
#include <string>
#include "List.h"


void main()
{
	List list;
	unsigned int action;
	cout << "1- added to list one element; 2-delete elem from back side list; 3-show list; 4-show size of list; 0-exit from programm." << endl;
	cout << "enter number of action: ";
	cin >> action;
	cout << endl;

	while (action)
	{
		switch (action)
		{
			case(1):
			{
				unsigned int pos;
				cout << "enter number positio list: ";
				cin >> pos;
				cout << endl;
				list.push(pos);
				break;
			}
			case(2):
			{
				list.pop_back();
				break;
			}
			case(3):
			{
				list.showList();
				break;
			}
			default:
				cout << "entered not write value, try again !" << endl;
				break;
		}
		cout << "enter number of action: ";
		cin >> action;
		cout << endl;
	}

}