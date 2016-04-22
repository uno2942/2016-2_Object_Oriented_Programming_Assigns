#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class AbsCollection{
protected:
	struct node { int n; node* next; node* before; };
	node head;
	int len;
public:
	int getdata_rotate()
	{
		int n = tempforgetdata->next->n;
		tempforgetdata = tempforgetdata->next;
		if (tempforgetdata->next == NULL)
			tempforgetdata = &head;
		return n;
	}
	int getlen() const
	{
		return len;
	}
	AbsCollection() : len(0), tempforgetdata(&head)
	{
		head.next = NULL;
		head.before = NULL;
	}
	~AbsCollection()
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
		push(n);
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
			outfile << temp->n << ' ';
			temp = temp->next;
		}
		outfile << endl;
	}
protected:
	static ofstream outfile;
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
		if (head.next!=NULL)
			temp->next->before = temp;
		temp->before = &head;
		head.next = temp;
		if (len == 0)
			head.before = temp;
		len++;
	}
	void pop(node* temp)
	{
		node* temp1 = temp->next;
		temp->next = temp->next->next;
		delete temp1;
		if (len == 1)
		{
			head.before = NULL;
		}
		else
			temp->next->before = temp;
		len--;
	}
private:
	node* tempforgetdata;
};
ofstream AbsCollection::outfile("set_output.txt");


class Set : public AbsCollection
{
public:
	Set()
	{

	}
	void Set_convert(const AbsCollection &collection)
	{
		int length = collection.getlen();
		for (int i = 0; i < length; i++)
			add(const_cast<AbsCollection&>(collection).getdata_rotate());
	}
	void add(int n)
	{
		if (search(n) == NULL)
		{
			push(n);
		}
	}
	bool search_e(int n) const
	{
		const node* temp = &head;
		for (int i = 0; i < len; i++)
		{
			if (temp->next->n == n)
				return true;
			temp = temp->next;
		}
		return false;
	}

	void intersection(const Set& s2) //const Set& s2?
	{
		node* temp = &head;
		for (int i = 0; i < len; i++)
		{
			if (s2.search_e(temp->next->n))
			{
				outfile << temp->next->n << ' ';
			}
			temp = temp->next;
		}
		outfile << endl;
	}
	void Union(const Set& s2)
	{
		node* temp = &head;
		int n;
		for (int i = 0; i < len; i++)
		{
			outfile << temp->next->n << ' ';
			temp = temp->next;
		}
		for (int i = 0; i < s2.getlen(); i++)
		{
			n = const_cast<Set&>(s2).getdata_rotate();
			if (search(n) == NULL)
				outfile << n << ' ';
		}
		outfile << endl;
	}
	void difference(const Set& s2)
	{
		node* temp = &head;
		for (int i = 0; i < len; i++)
		{
			if (!s2.search_e(temp->next->n))
			outfile << temp->next->n << ' ';
			temp = temp->next;
		}
		outfile << endl;
	}
	// Construct the Set instance using data in collection
};

class OrderedSet : public Set
{
public:
	OrderedSet()
	{

	}
	void OrderedSet_convert(const Set& set)
	{
		int length = set.getlen();
		for (int i = 0; i < length; i++)
			push(const_cast<Set&>(set).getdata_rotate());
		Quicksort(head.next, head.before);
	}
	void Quicksort(node* temp1, node* temp2)
	{
		if (temp1 != temp2 && temp2->next != temp1)
		{
			node* temp3 = partition(temp1, temp2);
			Quicksort(temp1, temp3->before);
			Quicksort(temp3->next, temp2);
		}
	}
	node* search(int n)
	{
		node* temp = &head;
		while (temp->next!=NULL && n > (temp->next->n))
		{
			if (n == temp->next->n)
				return NULL;
			temp = temp->next;
		}
		return temp;
	}
	void add(int n)
	{
		node* temp1 = search(n);
		if (temp1!=NULL)
		{
			node* temp = new node;
			temp->n = n;
			temp->before = temp1;
			temp->next = temp1->next;
			temp1->next = temp;
			if (temp->next!=NULL)
				temp->next->before = temp;
			len++;
		}
	}
	node* partition(node* temp1, node* temp2)
	{
		int pivot=temp2->n;
		node* temp3 = temp1;
		for (node* temp = temp1; temp!=temp2; temp=temp->next)
		{
			if (temp->n < pivot)
			{
				swap(temp3, temp);
				temp3=temp3->next;
			}
		}
		swap(temp3, temp2);
		return temp3;
	}
	void swap(node* i, node* j)
	{
		int n = i->n;
		i->n = j->n;
		j->n = n;
	}
};
int main()
{
	AbsCollection s0;
	Set s1;
	Set s2;
	OrderedSet s3;
	ifstream infile("set_input.txt");
	string str;
	int n1, n2;
	while (infile>>str)
	{
		if (!str.compare("MAKE_SET"))
		{
			s1.Set_convert(s0);
		}
		else if (!str.compare("UNION"))
		{
			s1.Union(s2);
		}
		else if (!str.compare("INTER"))
		{
			s1.intersection(s2);
		}
		else if (!str.compare("DIFF"))
		{
			s1.difference(s2);
		}
		else if (!str.compare("SET_SORT"))
		{
			s3.OrderedSet_convert(s2);
		}
		else
		{
			infile >> n1;
			if (!str.compare("PRINT"))
			{
				switch (n1)
				{
				case 0: s0.print(); break;
				case 1: s1.print(); break;
				case 2: s2.print(); break;
				case 3: s3.print(); break;
				}
			}
			else
			{
				infile >> n2;
				if (!str.compare("ADD"))
				{
					switch (n1)
					{
					case 0: s0.add(n2); break;
					case 1: s1.add(n2); break;
					case 2: s2.add(n2); break;
					case 3: s3.add(n2);
					}
				}
				else if (!str.compare("REMOVE"))
				{
					switch (n1)
					{
					case 0: s0.remove(n2); break;
					case 1: s1.remove(n2); break;
					case 2: s2.remove(n2); break;
					case 3: s3.remove(n2);
					}
				}
			}
		}
	}
}
