/*#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class stack
{
public:
	enum { empty, nempty };//�̸�?
	stack() : head(NULL)
	{
	}
	stack(string s)
	{
		a=new node;
		push(s);
	}
	~stack()
	{
		node* temp=head;
		while (temp)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	void push(string s="")
	{
		a = new node;
		a->s = s;
		a->next = head;
		head = a;
	}
	void pop()
	{
		node* temp;
		temp = head->next;
		delete head;
		head = temp;
	}
	int isempty()
	{
		if (head == NULL)
			return empty;
		else return nempty;
	}
	void print() const;
private:	 struct node{ string s; node* next; }; //�ؿ��� ����->�Լ� return type���� �� �� ����.node* head;
			 node* a;
			 node* head;
};

int main()
{
	string str;
	stack s("asdfds");
	return 0;
}

void stack::print() const
{
	int i = 0;
	node* temp = head;
	while (temp)
	{
		cout << temp->s << '\t' << ++i << endl;
		temp = temp->next;
	}
	}*/