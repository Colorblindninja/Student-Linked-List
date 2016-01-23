#pragma once
#ifndef _STUDENT_LINKED_LIST_H_
#define _STUDENT_LIINKED_LIST_H_
#include "Student.h"

class StudentLinkedList
{
	class Node
	{
	public:
		Student Payload;
		Node *Next;
	};

public:
	StudentLinkedList();
	StudentLinkedList(const StudentLinkedList &src);
	~StudentLinkedList();
	bool Exists(const Student &key) const;
	bool Insert(const Student &value);
	Student Retrieve(const Student &key);
	bool Delete(const Student &key);
	int getSize() const;
	Student getItem(int num) const; 
	StudentLinkedList &operator=(const StudentLinkedList &rhs);
	Student Smallest() const;



private:
	Node *mHead;
	int mSize = 0;
};

std::ostream &operator<<(std::ostream &os, const StudentLinkedList &rhs);
std::istream &operator>>(std::istream &is, StudentLinkedList &rhs);


#endif
