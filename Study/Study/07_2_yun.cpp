/*#include<iostream>

using namespace std;
class Rectangle
{
public:
	Rectangle(int a = 1, int b = 1)
	{
		r = a; 
		w = b;
	}
	void ShowAreaInfo()
	{
		cout << "Rectangle: ";
		cout << Area() << endl;
	}
protected:
	int Area()
	{
		return r*w;
	}
private:
	int r;
	int w;
};
class Square : public Rectangle
{
public:
	Square(int a=1) : Rectangle(a, a)
	{
	}
	void ShowAreaInfo()
	{
		cout << "Square: ";
		cout << Area() << endl;
	}
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
	}*/