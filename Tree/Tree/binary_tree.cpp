#include<iostream>

class array_tree
{
public:
	array_tree() : num(100), pos(0)
	{
	}
	void add(int n)
	{
		a[pos] = n;
		pos++;
	}
	int find(int n) const
	{
		for (int i = 0; i < pos; i++)
			if (a[i] == n)
				return i;
		return -1;
	}
	int root(int n) const
	{
		int k = find(n);
		if (k > 0)
			return a[(k + 1) / 2];
		else
			return -1;
	}
	int child_left(int n)
	{
		int k = 1;
		while (k <= pos+1)
			k = 2*k;
		k = k / 2;
		if (n > k)
			return -1;
		else
			return a[n * 2 - 1];
	}
	int depth()
	{
		int n = 0;
		while ((pos + 1) / 2 < 1)
		{
			n++;
			pos = (pos + 1) / 2 - 1;
		}
	}
	int heigth()
	{

	}
	int data(int n)
	{
		return a[n];
	}
	bool is_full()
	{
		int k = 1;
		while (k <= pos + 1)
			k = 2 * k;
		if ((pos + 2) == k)
			return true;
		return false;
	}
	bool is_proper();
private:
	int a[100];
	int num;
	int pos;
};
class linked_tree
{

};
int main()
{

}