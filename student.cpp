#include "Student.h"
#include <iostream>
#include <cstring>


Student::Student()
{
	mAge = 0;
	mLast = 0;
	mFirst = 0;
	mEmail = 0;
	mSSN[0] = 0;
}

Student::Student(const int age, const char *last, const char *first, const char *email, const char *ssn)
	:mAge(0), mLast(0), mFirst(0), mEmail(0)
{
	mSSN[0] = 0;
	setAge(age);
	setLast(last);
	setFirst(first);
	setEmail(email);
	setSsn(ssn);
}

Student::Student(const Student &src)
	:mAge(0), mLast(0), mFirst(0), mEmail(0)
{
	mSSN[0] = 0;
	*this = src;
}

Student::~Student()
{
	delete [] mFirst;
	delete [] mLast;
	delete [] mEmail;
}

int Student::getAge() const
{
	return mAge;
}

const char *Student::getLast() const
{
	if (mLast == 0)
	{
		return 0;
	}
	return mLast;
}

const char *Student::getFirst() const
{

	return mFirst;
}

const char *Student::getEmail() const
{
	if (mEmail == 0)
	{
		return 0;
	}
	return mEmail;
}

const char *Student::getSsn() const
{
	return mSSN;
}

bool Student::setAge(const int age)
{
	if (age > 150 || age < 0)
	{
		mAge = 0;
		return false;
	}
	else
	{
		mAge = age;
		return true;
	}
}

bool Student::setLast(const char *last)
{
	if (mLast)
	{
		delete[] mLast;
		mLast = 0;
	}
	if (last)
	{
		mLast = new char[std::strlen(last) + 1];
	}
	else
	{
		mLast = 0;
	}
	if (mLast)
	{
		std::strcpy(mLast, last);
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::setFirst(const char *first)
{
	if (mFirst)
	{
		delete [] mFirst;
		mFirst = 0; 
	}

	if (first)
	{
		mFirst = new char[std::strlen(first) + 1];
	}
	else
	{
		mFirst = 0;
	}
	if (mFirst)
	{
		std::strcpy(mFirst, first);
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::setEmail(const char *email)
{
	if (mEmail)
	{
		delete [] mEmail;
		mEmail = 0;
	}

	if (email)
	{
		mEmail = new char[std::strlen(email) + 1];
	}
	else
	{
		mEmail = 0;
	}
	if (mEmail)
	{
		std::strcpy(mEmail, email);
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::setSsn(const char *ssn)
{
	int i;
	bool flag = true;
	for (i = 0; ssn[i] != 0; i++)
	{
		if (i < 11)
		{
			mSSN[i] = ssn[i];
		}
		else
		{
			mSSN[0] = 0;
			flag = false;
			break;
		}
	}
	if (i<11)
	{
		mSSN[0] = 0;
		flag = false;
	}
	if (flag)
	{
		mSSN[i] = 0;
	}
	return flag;
}

Student &Student::operator=(const Student &rhs)
{
	mAge = rhs.mAge;
	std::strcpy(mSSN, rhs.mSSN);
	setLast(rhs.mLast);
	setFirst(rhs.mFirst);
	setEmail(rhs.mEmail);
	return *this;
}

bool Student::operator==(const Student &rhs) const
{
	if (mSSN && rhs.getSsn())
	{
		if (std::strcmp(mSSN, rhs.getSsn()) == 0)
		{
			return true;
		}
	}
	return false;
}

bool Student::operator!=(const Student &rhs) const
{
	if (std::strcmp(mSSN, rhs.getSsn()) != 0)
	{
		return true;
	}
	return false;
}

bool Student::operator<=(const Student &rhs) const
{
	if (mSSN && rhs.getSsn())
	{
		if (std::strcmp(mSSN, rhs.getSsn()) != 0)
		{
			return true;
		}
	}
	return false;
}

bool Student::operator<(const Student &rhs) const
{
	if (mSSN && rhs.getSsn())
	{
		if (std::strcmp(mSSN, rhs.getSsn()) < 0)
		{
			return true;
		}
	}
	return false;
}

bool Student::operator>=(const Student &rhs) const
{
	if (std::strcmp(mSSN, rhs.getSsn()) >= 0)
	{
		return true;
	}
	return false;
}

bool Student::operator>(const Student &rhs) const
{
	if (mSSN && rhs.getSsn())
	{
		if (std::strcmp(mSSN, rhs.getSsn()) > 0)
		{
			return true;
		}
	}
	return false;
}

std::ostream &operator<<(std::ostream &os, const Student &rhs)
{
	int age = rhs.getAge();
	const char *first;
	const char *last;
	const char *email;
	const char *ssn;
	
	if (rhs.getFirst() == 0)
	{
		first = "NONE";
	}
	else
	{
		first = rhs.getFirst();
	}

	if (rhs.getLast() == 0)
	{
		last = "NONE";
	}
	else
	{
		last = rhs.getLast();
	}

	if (rhs.getEmail() == 0)
	{
		email = "NONE";
	}
	else
	{
		email = rhs.getEmail();
	}

	if (rhs.getSsn()[0]  == 0)
	{
		ssn = "NONE";
	}
	else
	{
		ssn = rhs.getSsn();
	}

	os << age << " " << last << " " << first << " " << email << " " << ssn;
	return os;
}

std::istream &operator>>(std::istream &is, Student &rhs)
{
	int age;
	char *first = new char[MAX_LENGTH];
	char *last = new char[MAX_LENGTH];
	char *email = new char[MAX_LENGTH];
	char ssn[12];
	is >> age >> last >> first >> email >> ssn;

	if (std::strcmp(first, "NONE") == 0)
	{	
		delete[] first;
		first = 0;
	}
	if (std::strcmp(last, "NONE") == 0)
	{	
		delete[] last;
		last = 0;
	}
	if (std::strcmp(email, "NONE") == 0)
	{	
		delete[] email;
		email = 0;
	}
	if (std::strcmp(ssn, "NONE") == 0)
	{
		ssn[0] = 0;
	}
	if (is)
	{
		rhs.setAge(age);
		rhs.setEmail(email);
		rhs.setFirst(first);
		rhs.setLast(last);
		rhs.setSsn(ssn);
	}
	delete[] first;
	delete[] last;
	delete[] email;
	return is;
}


