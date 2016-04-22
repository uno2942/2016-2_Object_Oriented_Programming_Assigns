/*#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class CardGame{
protected: enum suit {ace, king ,queen, jack};
		   struct card { int s; int n; };
public:
	CardGame()
	{
		for (int i = 0; i < 52; i++)
		{
			c[i] = new card;
			c[i]->s = i / 13;
			c[i]->n = i % 13+1;
		}
	}
	~CardGame()
	{
		for (int i = 0; i < 52; i++)
		{
			delete c[i];
		}
	}
	card* get_card(int n)
	{
		return c[n];
	}
private:
	card* c[52];
};
class Bridge : public CardGame
{
public:
	Bridge() : CardGame()
	{
		deal();
	}
	card* get_deal(int n)
	{
		return deal_card[n];
	}
	void deal()
	{
		srand(time(NULL));
		int j, k;
		for (int i = 0; i < 52; i++)
		{
			j = rand()%52;
			for (k = 0; k < i; k++)
			{
				if (j == check[k])
					k = i+1;
			}
			if (k == i)
			{
				check[i] = j;
				deal_card[i] = get_card(j);
			}
			else
				i--;
		}
	}
private: int check[52];
		 card* deal_card[52];
};
class Poker : Bridge
{
private: struct poker { card* c; poker* next; };
public:
	Poker(int tmp) : temp(tmp), Bridge()
	{
		poker* temp_p;
		for (int i = 0; i < 4; i++)
		{
			head[i] = NULL;
			for (int n = 0; n < temp; n++)
			{
				temp_p = new poker;
				temp_p->c = get_deal(n+temp*i);
				temp_p->next = head[i];
				head[i] = temp_p;
			}
		}
	}
	~Poker()
	{
		poker* temp_p;
		for (int i = 0; i < 4; i++)
		{
			temp_p = head[i];
			for (int n = 0; n < temp; n++)
			{
				temp_p = head[i]->next;
				delete head[i];
				head[i] = temp_p;
			}
		}
	}
	void Print()
	{
		poker* temp_p;
		for (int i = 0; i < 4; i++)
		{
			temp_p = head[i];
			for (int n = 0; n < temp; n++)
			{
				cout << temp_p->c->n<<" "<<temp_p->c->s<<endl;
				temp_p = temp_p->next;
			}
		}
	}
private:
	poker* head[5];
	int temp;
};
int main()
{
	Poker p(7);
	p.Print();
	return 1;
	}*/