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
	case 1: s1 = "���а�";
	case 2: s1 = "�����а�";
	case 3: s1 = "ȭ�а�";
	case 4: s1 = "������а�";
	case 5: s1 = "�ż�����а�";
	case 6: s1 = "�����а�";
	case 7: s1 = "����濵���а�";
	case 8: s1 = "����������а�";
	case 9: s1 = "��ǻ�Ͱ��а�";
	case 10: s1 = "ȭ�а��а�";
	case 11: s1 = "â��IT���а�";
	}
	switch (posit)
	{
	case 1: s2 = "������";
	case 2: s2 = "�α���";
	case 3: s2 = "��������";
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
	case 1: s1 = "���а�";
	case 2: s1 = "�����а�";
	case 3: s1 = "ȭ�а�";
	case 4: s1 = "������а�";
	case 5: s1 = "�ż�����а�";
	case 6: s1 = "�����а�";
	case 7: s1 = "����濵���а�";
	case 8: s1 = "����������а�";
	case 9: s1 = "��ǻ�Ͱ��а�";
	case 10: s1 = "ȭ�а��а�";
	case 11: s1 = "â��IT���а�";
	}
	switch (posit)
	{
	case 1: s2 = "�кλ�";
	case 2: s2 = "���п���";
	}
	cout << setw(10) << name << "| " << setw(15) << id << "| " << setw(20) << s1 << "| " << setw(15) << s2 << "| " << setw(15) << mail << endl;
}
void Staff::Inquire() const
{
	string s1;
	string s2;
	switch (dept-10)
	{
	case 1: s1 = "���к���";
	case 2: s1 = "���Ű�����";
	case 3: s1 = "�ѹ�������";
	case 4: s1 = "�л�������";
	case 5: s1 = "�ְſ��";
	case 6: s1 = "����������";
	case 7: s1 = "����ȸ";
	case 8: s1 = "POSCO������";
	case 9: s1 = "��㼾��";
	case 10: s1 = "���п�������";
	}
	switch (posit+1)
	{
	case 1: s2 = "������";
	case 2: s2 = "�����";
	case 3: s2 = "����";
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
	if (!strcmp(s, "���а�"))
		return 0;
	else if (!strcmp(s, "�����а�") )
		return 1;
	else if (!strcmp(s, "ȭ�а�") )
		return 2;
	else if (!strcmp(s, "������а�") )
		return 3;
	else if (!strcmp(s, "�ż�����а�") )
		return 4;
	else if (!strcmp(s, "�����а�") )
		return 5;
	else if (!strcmp(s, "����濵���а�") )
		return 6;
	else if (!strcmp(s, "����������а�") )
		return 7;
	else if (!strcmp(s, "��ǻ�Ͱ��а�") )
		return 8;
	else if (!strcmp(s, "ȭ�а��а�"))
		return 9;
	else if (!strcmp(s, "â��IT���а�"))
		return 10;
	else if (!strcmp(s, "���к���"))
		return 11;
	else if (!strcmp(s, "���Ű�����"))
		return 12;
	else if (!strcmp(s, "�ѹ�������"))
		return 13;
	else if (!strcmp(s, "�ְſ��"))
		return 14;
	else if (!strcmp(s, "����������"))
		return 15;
	else if (!strcmp(s, "����ȸ"))
		return 16;
	else if (!strcmp(s, "POSCO������"))
		return 17;
	else if (!strcmp(s, "��㼾��"))
		return 18;
	else if (!strcmp(s, "���п�������"))
		return 19;
	else return -1;
}
int person::pos(const char* s)
{
	if (!strcmp(s, "������") || !strcmp(s, "������") || !strcmp(s, "�кλ�"))
		return 0;
	else if (!strcmp(s, "�α���") || !strcmp(s, "�����") || !strcmp(s, "���п���"))
		return 1;
	else if (!strcmp(s, "��������") || !strcmp(s, "����"))
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