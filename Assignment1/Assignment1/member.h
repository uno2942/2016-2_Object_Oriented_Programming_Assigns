#ifndef _MEMBER_H_
#define _MEMBER_H_
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
enum depart {math, phys, chem, bio, mater, mech, indu, elec, comp, chemindu, creative};

class person
{
public:
	void change(const char* s1, const char* s2,const char* s3,const char* s4);
	int get_id() const;
	int get_dept() const;
	const char* get_name() const;
	person(const char* s1, int n1,const char* s2,const char* s3, const char* s4);
	person();
	virtual ~person()
	{

	}
	person*& get_next();
	virtual void Inquire() const = 0;
	static int pos(const char* s);
	static int dep(const char* s);
protected:
	char* name;
	int id;
	char* mail;
	int dept;
	int posit;
	person* next;
};

class Faculty : public person
{
public:
	Faculty(const char* s1, int n1,const char* s2, const char* s3,const  char* s4);
	Faculty()
	{}
	void Inquire() const;
};
class Staff : public person
{
public:
	Staff(const char* s1, int n1, const char* s2, const char* s3, const  char* s4);
	Staff()
	{}
	void Inquire() const;
};
class Student : public person
{
public:
	Student(const char* s1, int n1, const char* s2, const char* s3, const  char* s4);
	Student()
	{}
	void Inquire() const;
};
#endif