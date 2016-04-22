/*#include<iostream>

using namespace std;
class Rectangle
{
public:
	Rectangle(const int& a, const int& b) : x(a), y(b)
	{

	}
	void ShowAreaInfo() const
	{
		cout << "¸éÀû: "<< x*y << endl;
	}
private:
	int x;
	int y;
};
class Square : public Rectangle
{
public:
	Square(const int &a) : Rectangle(a, a)
	{

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