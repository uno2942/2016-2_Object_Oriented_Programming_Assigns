#include"List.h"

List::~List()
{
	person* temp, *temp1;
	for (int i = 0; i < MAX_HASH; i++)
		for (int j = 0; j < MAX_HASH; j++)
			for (int k = 0; k < MAX_HASH; k++)
			{
				temp = hash[i][j][k];
				while (temp != NULL)
				{
					temp1 = temp->get_next();
					delete temp;
					temp = temp1;
				}
			}
}
void FacultyList::Add(const char* name, int id, const char* dept, const char* posit, const char* mail)
{
	person* f = new Faculty(name, id, dept, posit, mail);
	num++;
	int num1, num2, sum=0;
	num1 = strlen(name);
	for (int i = 0; i < num1; i++)
		sum = sum + name[i];
	num2 = sum % MAX_HASH;
	num1 = id % MAX_HASH;
		f->get_next()=hash[num1][num2][f->get_dept()]->get_next();
		hash[num1][num2][f->get_dept()]->get_next() = f;
}
void StaffList::Add(const char* name, int id, const char* dept, const char* posit, const char* mail)
{
	person* f = new Staff(name, id, dept, posit, mail);
	num++;
	int num1, num2, sum = 0;
	num1 = strlen(name);
	for (int i = 0; i < num1; i++)
		sum = sum + name[i];
	num2 = sum % MAX_HASH;
	num1 = id % MAX_HASH;
	f->get_next() = hash[num1][num2][f->get_dept()]->get_next();
	hash[num1][num2][f->get_dept()-11]->get_next() = f;
}
void StudentList::Add(const char* name, int id, const char* dept,const char* posit,const  char* mail)
{
	person* f = new Student(name, id, dept, posit, mail);
	num++;
	int num1, num2, sum = 0;
	num1 = strlen(name);
	for (int i = 0; i < num1; i++)
		sum = sum + name[i];
	num2 = sum % MAX_HASH;
	num1 = id % MAX_HASH;
	f->get_next() = hash[num1][num2][f->get_dept()]->get_next();
	hash[num1][num2][f->get_dept()]->get_next() = f;
}
person* List::search(int id)
{
	person* temp;
	for (int i = 0; i < MAX_HASH; i++)
		for (int j = 0; j < MAX_HASH; j++)
		{
			temp = hash[id%11][i][j];
			if (temp == NULL)
				continue;
			if (temp->get_next() == NULL)
				continue;
			while (temp->get_next()->get_next() != NULL)
			{
				if (temp->get_next()->get_id() == id)
					return temp;
				temp = temp->get_next();
			}
			if (temp->get_next()->get_id())
				return temp;
		}
	return NULL;
}
void List::Modify(int id)
{
	person* temp;
	temp=search(id);
	if (temp != NULL)
	{
		char* s1, *s2, *s3, *s4;
		get_info(s1, s2, s3, s4);
		temp->get_next()->change(s1, s2, s3, s4);
	}
}
void List::get_info(char*& s1, char*& s2, char*& s3, char*& s4)
{
	cout << "이름 입력: ";
	cin >> s1;
	cout << "학과(부서) 입력";
	cin >> s2;
	cout << "직급 입력: ";
	cin >> s3;
	cout << "메일 입력: ";
	cin >> s4;
}
void List::Delete(int id)
{
	person* temp, *temp1;
	temp = search(id);
	if (temp != NULL)
	{
		temp1 = temp->get_next();
		temp->get_next() = temp->get_next()->get_next();
		delete temp1;
	}
	num--;
}
void List::InquireByName(const char* name)
{
	int num1, num2, sum = 0;
	num1 = strlen(name);
	for (int i = 0; i < num1; i++)
		sum = sum + abs(name[i]);
	num2 = sum % MAX_HASH;
	person* temp;
	for (int i = 0; i < MAX_HASH; i++)
		for (int j = 0; j < MAX_HASH; j++)
		{
			if (hash[i][num2][j] == NULL)
				continue;
			temp = hash[i][num2][j]->get_next();
			while (temp != NULL)
			{
				if (!strcmp(temp->get_name(), name))
				{
					temp->Inquire();
				}
				temp = temp->get_next();
			}
		}
}
void List::InquireByID(int id)
{
	person* temp = search(id);
	if (temp != NULL)
		temp->get_next()->Inquire();
}
void List::InquireByDept(const char* dept)
{
	int depta;
	depta=person::dep(dept);
	for (int i = 0; i < MAX_HASH; i++)
		for (int j = 0; j < MAX_HASH; j++)
		{
			person* temp = hash[i][j][depta]->get_next();
			while (temp != NULL)
			{
				temp->Inquire();
				temp = temp->get_next();
			}
		}
}
void StaffList::InquireByDept(char* dept)
{
	int depta;
	depta = person::dep(dept);
	if (depta < 11)
		return;
	for (int i = 0; i < MAX_HASH; i++)
		for (int j = 0; j < MAX_HASH; j++)
		{
			person* temp = hash[i][j][depta-11]->get_next();
			while (temp != NULL)
			{
				temp->Inquire();
				temp = temp->get_next();
			}
		}
}
void List::InquireAll()
{
	person* temp;
	for (int i = 0; i < MAX_HASH; i++)
		for (int j = 0; j < MAX_HASH; j++)
			for (int k = 0; k < MAX_HASH; k++)
			{
				if (hash[i][j][k] == NULL)
					continue;
				temp = hash[i][j][k]->get_next();
				while (temp != NULL)
				{
					temp->Inquire();
					temp = temp->get_next();
				}
			}
}