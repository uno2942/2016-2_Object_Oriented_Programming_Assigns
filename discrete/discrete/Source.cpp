#include<iostream>

using namespace std;
class C
{
	static int x;
};
int main()
{
	int C::x;
	cout << C::x;
}