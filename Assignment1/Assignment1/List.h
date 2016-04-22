#ifndef _LIST_H_

#define _LIST_H_
#include<iostream>
#include<string>
#include"member.h"
class List
{
protected:
	List() : num(0), MAX_HASH(11)
	{
		for (int i = 0; i < MAX_HASH; i++)
			for (int j = 0; j < MAX_HASH; j++)
				for (int k = 0; k < MAX_HASH; k++)
					hash[i][j][k] = NULL;
	}
	int num;
	const int MAX_HASH;
	person* hash[11][11][11];//id, name, dep
public:
	~List();
	virtual void Add(const char*, int, const char*, const char*, const char*)=0;
	void Delete(int);
	void InquireByName(const char*);
	void InquireByID(int id);
	virtual void InquireByDept(const char*);
	void InquireAll();
	void get_info(char*&,char*&, char*&, char*&);
	person* search(int);
	void Modify(int);
};
class FacultyList : public List
{
public:
	FacultyList()
	{
		for (int i = 0; i < MAX_HASH; i++)
			for (int j = 0; j < MAX_HASH; j++)
				for (int k = 0; k < 11; k++)
					hash[i][j][k] = new Faculty;
	}
	void Add(const char*, int, const char*, const char*, const char*);
};
class StaffList : public List
{
public:
	StaffList()
	{
		for (int i = 0; i < MAX_HASH; i++)
			for (int j = 0; j < MAX_HASH; j++)
				for (int k = 0; k < 10; k++)
					hash[i][j][k] = new Staff;
	}
	void Add(const char*, int, const char*, const char*, const char*);
	virtual void InquireByDept(char*);
};
class StudentList : public List
{
public:
	StudentList()
	{
		for (int i = 0; i < MAX_HASH; i++)
			for (int j = 0; j < MAX_HASH; j++)
				for (int k = 0; k < 2; k++)
					hash[i][j][k] = new Student;
	}
	void Add(const char*, int, const char*, const char*, const char*);
};
#endif