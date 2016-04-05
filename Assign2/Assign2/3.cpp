/*//maker: parksb2942
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Set
{
private: struct node { int n; node* next; };
public:
	Set() : len(0), tempforgetdata(&head)
	{
		head.next = NULL;
	}
	~Set()
	{
		node* temp = head.next;
		node* temp1 = temp;
		for (int i = 0; i < len; i++)
		{
			temp1 = temp->next;
			delete temp;
			temp = temp1;
		}
	}
	void add(int n)
	{
		if (search(n) == NULL)
		{
			push(n);
		}
	}
	void remove(int n)
	{
		node* temp = search(n);
		if (temp != NULL)
		{
			pop(temp);
		}
	}
	void print()
	{
		node* temp = head.next;
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << ": "<<temp->n<<endl;
			temp = temp->next;
		}
	}
	bool search_e(int n)
	{
		node* temp = &head;
		for (int i = 0; i < len; i++)
		{
			if (temp->next->n == n)
				return true;
			temp = temp->next;
		}
		return false;
	}
	int getdata_rotate()
	{
		int n = tempforgetdata->next->n;
		tempforgetdata = tempforgetdata->next;
		if (tempforgetdata->next == NULL)
			tempforgetdata = &head;
		return n;
	}
	int getlen()
	{
		return len;
	}
	void intersection(Set& s2) //const Set& s2?
	{
		node* temp = &head;
		for (int i = 0; i < len; i++)
		{
			if (s2.search_e(temp->next->n))
				temp = temp->next;
			else
				pop(temp);
		}
	}
	void Union(Set& s2)
	{
		node* temp = &head;
		int n;
		for (int i = 0; i < s2.getlen(); i++)
		{
			n = s2.getdata_rotate();
			if (search(n) == NULL)
				push(n);
		}
	}
	void difference(Set& s2)
	{
		node* temp = &head;
		for (int i = 0; i < s2.getlen(); i++)
		{
			temp = search(s2.getdata_rotate());
			if (temp!=NULL)
				pop(temp);
		}
	}
private:
	node head;
	node* tempforgetdata;
	int len;
	node* search(int n)
	{
		node* temp = &head;
		for (int i = 0; i < len; i++)
		{
			if (temp->next->n == n)
				return temp;
			temp = temp->next;
		}
		return NULL;
	}
	void push(int n)
	{
		node* temp = new node;
		temp->n = n;
		temp->next = head.next;
		head.next = temp;
		len++;
	}
	void pop(node* temp)
	{
		node* temp1 = temp->next;
		temp->next = temp->next->next;
		delete temp1;
		len--;
	}
};
int main()
{
	Set set[2];
	string s;
	int n1, n2;
	while (1)
	{
		cin >> s >> n1 >> n2;

		if (!s.compare("ADD"))
			set[n1-1].add(n2);
		else if (!s.compare("REMOVE"))
			set[n1 - 1].remove(n2);
		else if (!s.compare("PRINT"))
			set[n1 - 1].print();
		else if (!s.compare("DIFF"))
		{
			if (n1 != n2)
				set[n1 - 1].difference(set[n2 - 1]);
		}
		else if (!s.compare("UNION"))
		{
			if (n1 != n2)
				set[n1 - 1].Union(set[n2 - 1]);
		}
		else if (!s.compare("INTERSECT"))
		{
			if (n1 != n2)
				set[n1 - 1].intersection(set[n2 - 1]);
		}
		set[n1 - 1].print();
	}
	return 0;
}
*/