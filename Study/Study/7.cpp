/*#include<iostream>
#include<string>

using namespace std;
class A
{
protected:
	A()
	{
		x = 1;
		y = 2;
		z = 3;
	}
public:
	int x;
	virtual int add(int a, int b)
	{
		return a + b;
	}
protected:
	int y;
private:
	int z;
};
class B : public A
{
	
public:
	using A::add;
	int add(int a, int b)
	{
		return a - b;
	}
	virtual string add(string s)
	{
		return s;
	}
	void prin()
	{
		cout << x;
		cout << y;
	}
private:
	
};
int main()
{
	B b;
	cout<<b.add(1, 2);

	return 0;
}
*/