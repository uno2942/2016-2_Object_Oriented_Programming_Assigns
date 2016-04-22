#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Queue
{
protected:
	enum { f, e };
	enum error { overflow, underflow };
	struct Node {
		int x;
		struct Node* p;
	};
public:
	Queue() : length(0)
	{
		ptr[f] = &empty;
		ptr[e] = &empty;
		empty.x = 0;
		empty.p = NULL;
	}
	virtual ~Queue()
	{
		ptr[f] = ptr[f]->p;
		Node* temp=ptr[f];
		for (int i = 0; i < length-1; i++)
		{ 
			ptr[f] = temp->p;
			delete temp;
			temp = ptr[f];
		}
		delete temp;
	}
	void push_back(int n);
	int pop_front();
	int front() const;
	int end() const;
	int at(int index) const;
	int size() const;
	void reverse();
	void print(ofstream&) const;
	virtual void push_front(int n) {}
	virtual int pop_back() { return 0; }
protected:
	void rev(Node* temp1);
	Node* ptr[2];
	Node empty;
	int length;
};

class Deque : public Queue
{
public:
	Deque() : Queue() {}
	virtual void push_front(int n);
	virtual int pop_back();
};

void Deque::push_front(int n)
{
	Node* temp = new Node;
	temp->x = n;
	temp->p = ptr[f]->p;
	ptr[f]->p = temp;
	length++;
}
int Deque::pop_back()
{
	try{
		if (size() == 0)
			throw underflow;
		Node* temp = ptr[f];
		for (int i = 0; i < length - 1; i++)
			temp = temp->p;
		int n = ptr[e]->x;
		temp->p = ptr[e]->p;
		delete ptr[e];
		ptr[e] = temp;
		length--;
		return n;
	}
	catch (error)
	{
		cout << "Queue's size 0";
		return -1;
	}
}
void Queue::push_back(int n)
{
	Node* temp = new Node;
	temp->x = n;
	temp->p = ptr[e]->p;
	ptr[e]->p = temp;
	ptr[e] = temp;
	length++;
}

int Queue::pop_front()
{
	try{
		if (size() == 0)
			throw underflow;
		Node* temp = ptr[f]->p;
		int n = temp->x;
		ptr[f]->p = temp->p;
		delete temp;
		length--;
		return n;
	}
	catch (error)
	{
		cout << "Queue's size 0";
		return -1;
	}
}

int Queue::front() const //맨 앞에 의미없는 노드 존재
{
	return ptr[f]->p->x;
}
int Queue::end() const
{
	return ptr[e]->x;
}
int Queue::at(int index) const
{
	try
	{
		Node* temp = ptr[f];
		if (index > length)
			throw overflow;
		if (index <= 0)
			throw underflow;
		for (int i = 0; i < index; i++)
			temp = temp->p;
		return temp->x;
	}
	catch (error t)
	{
		if (t == overflow)
			cout << "index is bigger than length";
		if (t == underflow)
			cout << "index is too small";
		return -1;
	}
}
int Queue::size() const
{
	return length;
}
void Queue::rev(Node* temp1)
{
	if (temp1->p->p != NULL)
		rev(temp1->p);
	Node* temp = temp1->p;
	temp1->p = temp->p;
	temp->p = temp1;
}
void Queue::reverse()
{
	Node* temp = ptr[e];
	rev(ptr[f]->p);
	ptr[e] = empty.p;
	empty.p = temp;
}
void Queue::print(ofstream &outfile) const
{
	Node* temp = ptr[f]->p;
	for (int i = 0; i < length; i++)
	{
		outfile << i + 1 << ": " << temp->x << "   " << endl;
		temp = temp->p;
	}
}

int main()
{
	ifstream infile("Queue_input.txt");
	Queue* Q;
	bool De=false;
	if (!infile.is_open())
	{
		infile.open("Deque_input.txt");
	}
	ofstream outfile("Queue_output.txt");
	string s;
	int n;
	infile >> s;
	if (!s.compare("Queue"))
		Q = new Queue;
	else if (!s.compare("Deque"))
	{
		Q = new Deque;
		De = true;
	}
	else
		return 0;
		
		while (infile >> s)
		{
			if (!s.compare("push_back"))
			{
				infile >> n;
				Q->push_back(n);
			}
			else if (!s.compare("pop_front"))
			{
				outfile << "pop_front: " << Q->pop_front() << endl;
			}
			else if (!s.compare("front"))
			{
				outfile << "front: " << Q->front() << endl;
			}
			else if (!s.compare("end"))
			{
				outfile << "end: " << Q->end() << endl;
			}
			else if (!s.compare("at"))
			{
				infile >> n;
				outfile << "at " << n << ": " << Q->at(n) << endl;
			}
			else if (!s.compare("size"))
			{
				outfile << "size: " << Q->size() << endl;
			}
			else if (!s.compare("reverse"))
			{
				Q->reverse();
				outfile << "reverse completed"<<endl;
			}
			else if (!s.compare("print"))
			{
				Q->print(outfile);
			}
			else if (De&&!s.compare("push_front"))
			{
				infile >> n;
				Q->push_front(n);
			}
			else if (De&&!s.compare("pop_back"))
			{
				outfile << "pop_back: " << Q->pop_back() << endl;
			}
		}
		delete Q;
	return 0;
	}