/*#include<iostream>
#include<string>

using namespace std;

class queue
{
private:
	struct que
	{
		int num;
		que* next;
	};
public:
	enum { underflow };
	queue() : MIN(-1), rear(empty), n(0), empty({ 1, &empty })
	{
		count++;
	}
	queue(int num) : MIN(-1), rear(empty), n(0), empty({ 1, &empty })
	{
		count++;
		enque(num);
	}
	~queue()
	{
		for (int i = 0; i < n; i++)
			pop();
	}
	queue(queue& copy) : MIN(-1), rear(empty), n(0), empty({ 1, &empty })
	{
		count++;
		int temp;
		for (int i = 0; i < n; i++)
		{
			enque(copy.back());
		}

		
				count++;
		for (int i = 0; i < n; i++)
			enque(copy.back());
			가 안되는 이유?
		

	}
	void enque(int& data)
	{
		que* temp = new que;
		temp->next = rear.next;
		temp->num = data;
		rear.next = temp;
		rear = *temp;
		n++;
	}
	void pop()
	{
		if (isempty() == true)
			throw underflow;
		que* temp = rear.next;
		rear.next = temp->next;
		delete temp;
		n--;
	}
	int front() const;
	int back() const
	{
		return rear.num;
	}
	bool isempty() const
	{
		if (n == 0)
			return true;
		else
			return false;
	}
	inline int size() const;
private:
	const int MIN;
	int n;
	que& rear;
	que empty;
	static int count;

};

int queue::count = 0;
int main()
{

	return 0;
}
int queue::front() const
{
	return rear.next->num;
}
int queue::size() const
{
	return n;
}*/