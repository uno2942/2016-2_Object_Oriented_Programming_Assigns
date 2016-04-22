/*#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class VendingMachine
{
private: enum error {sold_out, shortage_of_money, shortage_of_coin};
public:
	enum bever {coke, cider};
	
	VendingMachine(int& co_p, int& co_s, int& ci_p, int& ci_s, int& w_1, int& w_5) : remainder(0), outfile("vending_output.txt")
	{
	coke_p = co_p; coke_s = co_s;
	cider_p = ci_p; cider_s = ci_s;
	won_1 = w_1; won_5 = w_5;
	}
	void write_status()
	{
		outfile << "coke: " << coke_s << ' ';
		outfile << "cider: " << cider_s << ' ';
		outfile << "remainder: " << remainder << endl;
	}
	void choose_item(bever t)
	{
		try{
			int temp;
			if (t == coke)
			{
				temp = remainder - coke_p;
				set_stock(coke);
				if (temp < 0)
					throw shortage_of_money;
				cal_coin(temp);
				coke_s--;
				outfile << "Coke out"<<endl;
			}
			if (t == cider)
			{
				temp = remainder - cider_p;
				set_stock(cider);
				if (temp < 0)
					throw shortage_of_money;
				cal_coin(temp);
				cider_s--;
				outfile << "Cider out" << endl;
			}
			remainder = temp;
		}
		catch (error e)
		{
			if (e == shortage_of_coin)
			{
				outfile << "Shortage of coin"<<endl;
			}
			if (e == shortage_of_money)
				outfile << "Shortage of money"<<endl;
			if (e == sold_out)
				outfile << "Sold out"<<endl;
		}
	}

	void inset_coin(int n)
	{
		if (n == 500)
		{
			won_5++;
			remainder += 500;
			outfile << "500 in" << endl;
		}
		else if (n == 100)
		{
			won_1++;
			remainder += 100;
			outfile << "100 in" << endl;
		}
	}

	void return_change()
	{
		int i;
		for (i = 0; i < won_5; i++)
		{
			if ((remainder - 500 * i) < 500)
				break;
		}
		won_5 -= i;
		won_1 = won_1 - (remainder - 500 * i) / 100;
		outfile << "Remainder: " << remainder<<endl;
		remainder = 0;
	}
private:
	void set_stock(bever t)
	{
		if (t == coke)
		{
			if (coke_s == 0)
				throw sold_out;
		}
		else
		{
			if (cider_s == 0)
				throw sold_out;
		}
	}
	void cal_coin(int temp)
	{
		int i;
		for (i = 0; i < won_5; i++)
		{
			if ((temp - 500 * i) < 500)
				break;
		}
		if (((temp - 500 * i) - 100 * won_1) > 0) //어느 순간에도 사용자에게 거스름돈을 지급할 수 있도록 함.
			throw shortage_of_coin;		
	}
	string s;
	int coke_p, coke_s;
	int cider_p, cider_s;
	int won_1, won_5;
	int remainder;
	ofstream outfile;
};
int main()
{
	ifstream infile1("vending_input1.txt");
	ifstream infile2("vending_input2.txt");
	string s;
	int coke_p, coke_s;
	int cider_p, cider_s;
	int won_1, won_5;
	int n;
	while (!infile1.eof())
	{
		infile1 >> s;
		if (!s.compare("Coke"))
		{
			infile1 >> coke_p;
			infile1 >> coke_s;
		}
		else if (!s.compare("Cider"))
		{
			infile1 >> cider_p;
			infile1 >> cider_s;
		}
		else if (!s.compare("100won"))
			infile1 >> won_1;
		else if (!s.compare("500won"))
			infile1 >> won_5;
	}
	VendingMachine VM(coke_p, coke_s, cider_p, cider_s, won_1, won_5);
	while (infile2 >> s)
	{
		if (!s.compare("push_coke"))
			VM.choose_item(VM.coke);
		else if (!s.compare("push_cider"))
			VM.choose_item(VM.cider);
		else if (!s.compare("insert_coin"))
		{
			infile2 >> n;
			if (n == 500)
				VM.inset_coin(500);
			else if (n == 100)
				VM.inset_coin(100);
		}
		else if (!s.compare("return_change"))
			VM.return_change();
		else if (!s.compare("write_status"))
			VM.write_status();
	}
	}*/