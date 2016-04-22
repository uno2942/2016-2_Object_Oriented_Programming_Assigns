#include"member.h"
void person::change(const char* s1,const char* s2,const char* s3,const char* s4)
{
	delete name;
	name = new char[strlen(s1) + 1];
	strcpy(name, s1);
	delete mail;
	mail = new char[strlen(s4) + 1];
	strcpy(mail, s4);
	pos(s2);
	dep(s3);
}
const char* person::get_name() const
{
	return name;
}
void Faculty::Inquire() const
{
	string s1;
	string s2;
	switch (dept+1)
	{
	case 1: s1 = "수학과";
	case 2: s1 = "물리학과";
	case 3: s1 = "화학과";
	case 4: s1 = "생명공학과";
	case 5: s1 = "신소재공학과";
	case 6: s1 = "기계공학과";
	case 7: s1 = "산업경영공학과";
	case 8: s1 = "전자전기공학과";
	case 9: s1 = "컴퓨터공학과";
	case 10: s1 = "화학공학과";
	case 11: s1 = "창의IT공학과";
	}
	switch (posit)
	{
	case 1: s2 = "정교수";
	case 2: s2 = "부교수";
	case 3: s2 = "객원교수";
	}
	right;
	cout << setw(10) << name << "| " << setw(15) << id << "| " << setw(20) << s1 << "| " << setw(15) << s2 << "| " << setw(15) << mail<<endl;
}
void Student::Inquire() const
{
	string s1;
	string s2;
	switch (dept+1)
	{
	case 1: s1 = "수학과";
	case 2: s1 = "물리학과";
	case 3: s1 = "화학과";
	case 4: s1 = "생명공학과";
	case 5: s1 = "신소재공학과";
	case 6: s1 = "기계공학과";
	case 7: s1 = "산업경영공학과";
	case 8: s1 = "전자전기공학과";
	case 9: s1 = "컴퓨터공학과";
	case 10: s1 = "화학공학과";
	case 11: s1 = "창의IT공학과";
	}
	switch (posit)
	{
	case 1: s2 = "학부생";
	case 2: s2 = "대학원생";
	}
	cout << setw(10) << name << "| " << setw(15) << id << "| " << setw(20) << s1 << "| " << setw(15) << s2 << "| " << setw(15) << mail << endl;
}
void Staff::Inquire() const
{
	string s1;
	string s2;
	switch (dept-10)
	{
	case 1: s1 = "대학본부";
	case 2: s1 = "구매관재팀";
	case 3: s1 = "총무안전팀";
	case 4: s1 = "학생지원팀";
	case 5: s1 = "주거운영팀";
	case 6: s1 = "국제협력팀";
	case 7: s1 = "복지회";
	case 8: s1 = "POSCO국제관";
	case 9: s1 = "상담센터";
	case 10: s1 = "대학원업무팀";
	}
	switch (posit+1)
	{
	case 1: s2 = "정직원";
	case 2: s2 = "계약직";
	case 3: s2 = "인턴";
	}
	cout << setw(10) << name << "| " << setw(15) << id << "| " << setw(20) << s1 << "| " << setw(15) << s2 << "| " << setw(15) << mail << endl;
}
person::person(const char* s1, const int n1,const char* s2,const char* s3,const char* s4) : next(NULL)
{
	name = new char[strlen(s1) + 1];
	strcpy(name, s1);
	id = n1;
	mail = new char[strlen(s4) + 1];
	strcpy(mail, s4);
	posit=pos(s2);
	dept=dep(s3);
}
person::person() : next(NULL)
{
	name = NULL;
	id = 0;
	mail = NULL;
	posit = -1;
	dept = -1;
}
int person::dep(const char* s)
{
	if (!strcmp(s, "수학과"))
		return 0;
	else if (!strcmp(s, "물리학과") )
		return 1;
	else if (!strcmp(s, "화학과") )
		return 2;
	else if (!strcmp(s, "생명공학과") )
		return 3;
	else if (!strcmp(s, "신소재공학과") )
		return 4;
	else if (!strcmp(s, "기계공학과") )
		return 5;
	else if (!strcmp(s, "산업경영공학과") )
		return 6;
	else if (!strcmp(s, "전자전기공학과") )
		return 7;
	else if (!strcmp(s, "컴퓨터공학과") )
		return 8;
	else if (!strcmp(s, "화학공학과"))
		return 9;
	else if (!strcmp(s, "창의IT공학과"))
		return 10;
	else if (!strcmp(s, "대학본부"))
		return 11;
	else if (!strcmp(s, "구매관재팀"))
		return 12;
	else if (!strcmp(s, "총무안전팀"))
		return 13;
	else if (!strcmp(s, "주거운영팀"))
		return 14;
	else if (!strcmp(s, "국제협력팀"))
		return 15;
	else if (!strcmp(s, "복지회"))
		return 16;
	else if (!strcmp(s, "POSCO국제관"))
		return 17;
	else if (!strcmp(s, "상담센터"))
		return 18;
	else if (!strcmp(s, "대학원업무팀"))
		return 19;
	else return -1;
}
int person::pos(const char* s)
{
	if (!strcmp(s, "정교수") || !strcmp(s, "정직원") || !strcmp(s, "학부생"))
		return 0;
	else if (!strcmp(s, "부교수") || !strcmp(s, "계약직") || !strcmp(s, "대학원생"))
		return 1;
	else if (!strcmp(s, "객원교수") || !strcmp(s, "인턴"))
		return 2;
	else return -1;
}
person*& person::get_next()
{
	return next;
}
int person::get_dept() const
{
	return dept;
}
int person::get_id() const
{
	return id;
}
Faculty::Faculty(const char* s1, int n1, const char* s2, const char* s3, const char* s4) : person(s1, n1, s2, s3, s4)
{}
Staff::Staff(const char* s1, int n1, const char* s2, const char* s3, const char* s4) : person(s1, n1, s2, s3, s4)
{}
Student::Student(const char* s1, int n1, const char* s2, const char* s3, const char* s4) : person(s1, n1, s2, s3, s4)
{}