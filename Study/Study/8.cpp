/*#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class A{

public:
	int a;
	int b;
	A() {}
	const int* get_c() const
	{
		return &c;
	}
private:
	struct node{ int* a; };
	int c;
};
class B : public A{
public:
	B()
	{
		d = const_cast<int*>(get_c());
		*d=*d+100;
	}
private:
	int* d;
};
int main()
{
	B b;
	cout << *b.get_c();
	return 0;
}
*/