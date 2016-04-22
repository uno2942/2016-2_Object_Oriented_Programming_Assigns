#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class floatArray{
public:
	floatArray() : ar(NULL), length(0) {	}
	void print(); // ar 의 모든 내용을 출력한다. 
protected:
	float* ar; // input file을 읽어 배열을 동적할당한다.
	int length; // 데이터 개수
};

void floatArray::print()
{
	for (int i = 0; i < length; i++)
	{
		cout << ar[i];
	}
	cout << endl;
}

class Matrix : floatArray
{
public:
	Matrix(string& s)
	{
		resolveint(s);
	}
	~Matrix()
	{
		delete[] ar;
	}
	void add(Matrix&);
	void sub(Matrix&);
	void mul(Matrix&);
	void inverse();
	float getdata(int i) const
	{
		return ar[i];
	}
	void print()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				outfile << ar[i*n + j] << ' ';
			outfile << endl;
		}
		outfile << endl;
	}
private:
	static ofstream outfile;
	int n;
	int num = 0;
	int j = 0;
	void resolveint(string& s)
	{
		for (int i = 0; s[i] != NULL; i++)
		{
			if (s[i] == ' ')
				length++;
		}
		length++;
		ar = new float[length];
		for (int i = 0; i<length; i++)
		{
			while (s[j] != ' ' && s[j] != NULL)
			{
				num = num * 10 + s[j] - '0';
				j++;
			}
			ar[i] = num;
			num = 0;
			j++;
		}
		n = sqrt(length);
	}

};
ofstream Matrix::outfile("Output_1.txt");

void Matrix::add(Matrix& b)
{
	for (int i = 0; i < length; i++)
		ar[i] = ar[i] + b.getdata(i);
}
void Matrix::sub(Matrix& b)
{
	for (int i = 0; i < length; i++)
		ar[i] = ar[i] - b.getdata(i);
}
void Matrix::mul(Matrix& b)
{
	int sum = 0;
	float *c = new float[length];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				sum = sum + ar[i*n + k]*(b.getdata(k*n + j));
			c[i*n + j] = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < length; i++)
		ar[i] = c[i];
	delete[] c;
}
void Matrix::inverse()
{
	float *b = new float[length];
	float *c = new float[length];
	float temp;
	for (int i = 0; i < length; i++)
	{
		b[i] = ar[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				c[i*n + j] = 1;
			else
				c[i*n + j] = 0;
		}

	try{
		for (int i = 0; i < n; i++)
		{
			if (b[i*(n + 1)] == 0)
			{
				for (int j = i + 1; j < n; j++)
					if (b[i + j*n] != 0) // 역행렬 존재?
					{
						float temp;
						for (int k = i; k < n; k++)
						{
							temp = b[i*n + k];
							b[i*n + k] = b[k + j*n];
							b[k + j*n] = temp;
							temp = c[i*n + k];
							c[i*n + k] = c[k + j*n];
							c[k + j*n] = temp;
						}
						break;
					}
				if (b[i*(n + 1)] == 0)
					throw - 100;
			}

			for (int j = i + 1; j < n; j++)
			{
				temp = -b[i + j*n] / b[i*(n + 1)]; //앞에 계수
				b[i + j*n] = 0;
				for (int k = i + 1; k < n; k++)
				{
					b[j*n + k] = b[j*n + k] + temp * b[k + i*n];//U
				}
				for (int k = 0; k < n; k++)
				{
					c[j*n + k] = c[j*n + k] + temp * c[k + i*n];//L
				}
			}
		}

			for (int i = n - 1; i >= 0; i--)
			{
				if (b[i*(n + 1)] == 0)
					throw - 100;
					for (int j = i - 1; j >= 0; j--)
					{
						temp = -b[i + j*n] / b[i*(n + 1)]; //계수
						b[i + j*n] = 0;
						for (int k = 0; k < n; k++)
						{
							c[j*n + k] = c[j*n + k] + temp * c[k + i*n]; //L
						}
					}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					c[i*n + j] = c[i*n + j] / b[i*(n + 1)]; //마지막 나눠주기
				}
			}
			for (int i = 0; i < length; i++)
				ar[i] = c[i];
		}

	catch (int e)
	{
		if (e == -100)
			outfile << "unable to reverse"<<endl;
	}

	delete[] b;
	delete[] c;
}
int main()
{
	ifstream infile("input.txt");
	string s;
	char c1, c2;
	getline(infile, s);
	Matrix a(s);
	getline(infile, s);
	Matrix b(s);
	while (infile >> s)
	{
		if (!s.compare("print"))
			a.print();
		else if (!s.compare("inverse"))
			a.inverse();
		else
		{
			Matrix* temp1, *temp2;
			infile >> c1 >> c2;
			if (c1 == 'a')
			{
				temp1 = &a;
				temp2 = &b;
			}
			else
			{
				temp1 = &b;
				temp2 = &a;
			}

			if (!s.compare("add"))
				(*temp1).add(*temp2);
			else if (!s.compare("sub"))
				(*temp1).sub(*temp2);
			else if (!s.compare("mul"))
				(*temp1).mul(*temp2);
		}
	}
	return 0;
}