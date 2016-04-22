#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
class CardGame{
protected:   
	struct card { int s; int n; };
	static ofstream outfile;
	 card** head;
	 int temp1, temp2;
	 int check[52];
	 void deal()
	 {
		 srand(time(NULL));
		 int j, k;
		 for (int i = 0; i < temp1*temp2; i++)
		 {
			 j = rand() % 52;
			 for (k = 0; k < i; k++)
				 {
					 if (j == check[k])
					 k = i + 1;
				 }
				 if (k == i)
				 {
					 check[i] = j;
					 head[i / temp2][i % temp2].n=j/13;
					 head[i / temp2][i % temp2].s = j % 13;
				 }
				 else
					 i--;
			 }
		 }
public:
	CardGame() : temp1(0), temp2(0)
	{
	}
	void Print()
	{
		for (int i = 0; i < temp1; i++)
		{
			for (int n = 0; n < temp2; n++)
			{
				switch (head[i][n].n)
				{
				case 0: outfile << 'H'; break;
				case 1:	outfile << 'C'; break;
				case 2: outfile << 'D'; break;
				case 3: outfile << 'S';
				}
				if (head[i][n].s == 12)
					outfile << 'A';
				else if (head[i][n].s == 11)
					outfile << 'K';
				else if (head[i][n].s == 10)
					outfile << 'Q';
				else if (head[i][n].s == 9)
					outfile << 'J';
				else
					outfile << head[i][n].s+1;
				outfile << ' ';
			}
			outfile << endl;
		}
	}
};
ofstream CardGame::outfile("output.txt");
class Bridge : public CardGame
{
public:
	Bridge()
	{
		temp1 = 4;
		temp2 = 13;
		head = new card*[temp1];//?(float*)[5]
		for (int i = 0; i < temp1; i++)
		{
			head[i] = new card[temp2];
		}
		deal();
	}
	~Bridge()
	{
		for (int i = 0; i < temp1; i++)
			delete[] head[i];
		delete[] head;
	}
};
class Poker : public CardGame
{
public:
	Poker(int tmp)
	{
		temp1 = tmp;
		temp2 = 5;
		head = new card*[temp1];//?(float*)[5]
		for (int i = 0; i < temp1; i++)
		{
			head[i] = new card[5];
		}
		deal();
	}
	~Poker()
	{
		for (int i = 0; i < temp1; i++)
			delete[] head[i];
		delete[] head;
	}
};
int main(int argv, char* argc[])
{
	string s;
	int n;
	Bridge* a=NULL;
	Poker* b=NULL;
	ifstream infile(argc[1]);
	while (infile >> s)
	{
		if (!s.compare("BRIDGE"))
		{
			a = new Bridge;
		}
		else if (!s.compare("POKER"))
		{
			infile >> n;
			b = new Poker(n);
		}
		else if (!s.compare("PRINT"))
		{
			if (a == NULL)
				b->Print();
			else
				a->Print();
		}
	}
	if (a == NULL)
		delete b;
	else
		delete a;
	return 0;
}
