#include "StudentLinkedList.h"
#include "Student.h"
#include <iostream>


StudentLinkedList::StudentLinkedList()
{
	mHead = 0;
}
StudentLinkedList::StudentLinkedList(const StudentLinkedList &src)
{
	mHead = 0;
	*this = src;
}
StudentLinkedList::~StudentLinkedList()
{
	Node *curr = mHead, *temp = 0;
	while (curr != 0)
	{
		temp = curr;
		curr = curr->Next;
		delete temp;
	}
}


bool StudentLinkedList::Exists(const Student &key) const
{
	if (mHead)
	{
		Node *curr;
		for (curr = mHead; curr != 0; curr = curr->Next)
		{
			if (curr->Payload == key)
			{
				return true;
			}
		}
		return false;
	}
	return false;
}

bool StudentLinkedList::Insert(const Student &value)
{
	if (!Exists(value))
	{
		Node *curr = new Node;
		curr->Next = mHead;
		curr->Payload = value;
		mHead = curr;
		mSize++;
		return true;
	}
	return false;
	
}

bool StudentLinkedList::Delete(const Student &key)
{
	Node *curr, *prev = 0;
	for (curr = mHead; curr != 0; curr = curr->Next)
	{
		if (curr->Payload == key)
		{
			if (prev == 0)
			{
				mHead = curr->Next;
			}
			else
			{
				prev->Next = curr->Next;
			}
			delete curr;
			return true;
		}
		prev = curr;
	}
	return false;
}

Student StudentLinkedList::Retrieve(const Student &key)
{
	Node *curr;
	for (curr = mHead; curr != 0; curr = curr->Next)
	{
		if (curr->Payload == key)
		{
			return curr->Payload;
		}
	}
	return Student();
}

int StudentLinkedList::getSize() const
{
	return mSize;
}

Student StudentLinkedList::getItem(int num) const
{
	Node *curr;
	int i = 0;
	for (curr = mHead; curr != 0 && i < num; curr = curr->Next)
	{
		i++;
	}
	if (curr)
	{
		return curr->Payload;
	}
	else
	{
		return Student();
	}
}

Student StudentLinkedList::Smallest() const
{
	Node *curr;
	if (mHead)
	{
		Student smallest = mHead->Payload;
		for (curr = mHead; curr != 0; curr = curr->Next)
		{
			if (curr->Payload < smallest)
			{
				smallest = curr->Payload;
			}
		}
		return smallest;
	}
	return Student();
}

StudentLinkedList &StudentLinkedList::operator=(const StudentLinkedList &rhs)
{
	Node *curr;
	for(curr = rhs.mHead; curr != 0; curr = curr->Next)
	{
		Insert(curr->Payload);
	}
	return *this;
} 


std::ostream &operator<<(std::ostream &os, const StudentLinkedList &rhs)
{
	int i;
	if (rhs.getSize() == 0)
	{
		return os;
	}
	for (i = 0; i < rhs.getSize()-1; i++)
	{
		os << rhs.getItem(i) << std::endl;
	}
	os << rhs.getItem(i);
	return os;
}

std::istream &operator>>(std::istream &is, StudentLinkedList &rhs)
{
	Student s;
	while (is)
	{
		is >> s;
		rhs.Insert(s);
	}
	return is;
}