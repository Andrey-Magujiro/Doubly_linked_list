#pragma once
#include <iostream>
#include <string>


using namespace std;

class Node
{
public:
	int age;
	string name;
	Node *next;
	Node* prev;
	Node() : age(0), name(""), next(nullptr), prev(nullptr) {}
	void setParam()
	{
		bool flag = true;
		do {
			flag = true;
			cout << "Enter age: ";
			cin >> age;
			cout << endl;
			if (cin.fail()) { cin.clear(); cout << "Not correct value, try again !"<<endl;  cin.ignore(32767, '\n'); flag = false;  }
			if(flag ==true)
			{
				cin.ignore(32767, '\n');
				cout << "Enter name: ";
				getline(cin, name);
				cout << endl;
			}
		} while (flag!=true);
	}
};

class List
{
private:
	Node * head;
	Node *tail;
	int size;

public:
	List() { head = nullptr; tail = nullptr; size = 0; }

	int push(unsigned int pos)
	{
		Node *tamp = new Node;
		tamp->setParam();

		if (size == 0)
		{
			tail = head = tamp;
		}
		else if (size != 0 && pos == 1) //add in begin 
		{
			tamp->next = head;
			head->prev = tamp;
			head = tamp;
			head->prev = nullptr;
		}
		else if (size != 0 && pos > size)  // add in end
		{
			tamp->next = nullptr;
			tamp->prev = tail;
			tail->next = tamp;
			tail = tamp;
		}
		else if (size > 1 && pos <= size)  // add anywere but not begining and not end
		{
			Node * copyTamp;
			Node * copyHead = head;
			int i = 0;
			do {
				copyTamp = copyHead;
				copyHead = copyHead->next;
				i++;
			} while (i != pos - 1 || copyHead != tail);

			copyTamp->next = tamp;
			tamp->prev = copyTamp;
			copyHead->prev = tamp;
			tamp->next = copyHead;

		}

		size++;
		cout << "New element is added !" << endl;
		return 0;
	}

	void showSize() { cout << "Size of stract is: " << size << endl; }

	int pop_back()
	{
		if (size == 0) { cout << "Not have alements!"<<endl; return 0; }
		Node *copyTail = tail;
		tail = tail->prev;
		copyTail->prev = nullptr;
		if (size != 1) { tail->next = nullptr; }
		if (size == 1) { head = tail; }
		size--;
		cout << "Element has been deleted!" << endl;
		return 0;
	}

	void showList()
	{
		if (size == 0) { cout << "Not have elements in list! " << endl; }
		Node * copyHead = head;
		while (copyHead != nullptr)
		{
			cout << "age: " << copyHead->age << "\tname: " << copyHead->name << endl;
			copyHead = copyHead->next;
		}
	}

	~List()
	{
		while (head != nullptr)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}
};
