/*#include<iostream>
#include<fstream>
#include<string>

using namespace std;
void write_str(ofstream&, string, int n=10);



int main()
{
	ifstream infile("205_input.txt");
	ofstream outfile("205_output.txt");
	string s;
	int n=5;
	int i=0;
	while (!infile.eof())
	{
		getline(infile, s);
		infile>>n;
		write_str(outfile, s);
		write_str(outfile, s, n);
		getline(infile, s);
	}
	return 0;
}
void write_str(ofstream& outfile, string s, int n)
{
	int length = s.length();
	if (length > n)
	s.erase(n, length - 1);
	outfile << s << endl;
	}*/