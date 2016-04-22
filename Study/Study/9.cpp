#include<iostream>
using namespace std;
class A
{
public:
	void print()
	{
		cout << this << endl;
	}
};
class B : public A
{
public:
	void print()
	{
		cout << this<<endl;
	}
private:
	int x;
};
int main()
{
	B b;
	b.print();
	b.A::print();
	cout << &b;
	return 0;
}