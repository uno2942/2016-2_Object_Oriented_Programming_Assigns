#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class encrypting
{
public: encrypting(char* argc)
	{
		infile.open(argc);
		cout << "asdfsdf";
		outfile.open("Encoding_output.txt");
	}
	void Getline()
	{
		getline(infile, codeString);
		getline(infile, str);
		str_length = str.length();
		code_length = codeString.length();
	}
	void printing()
	{
		for (int i = 0; i < 11; i++)
		{
			outfile << codeString[i%code_length];
		}
		outfile << endl;
	
		for (int i = 0; i < str_length; i++)
		{
			str[i] = (str[i] + codeString[i%code_length] - 64) % 95 + 32;//
			outfile << str[i];
		}
		outfile << endl;
	} 
private:
	const int fail_open_file = 1;
	ifstream infile;
	ofstream outfile;
	string str, codeString;
	int str_length;
	int code_length;
};
class decoding
{
public:
	decoding()
	{
		infile.open("Encoding_output.txt");
		outfile.open("Decoding_output.txt");
	}
	void Getline()
	{
		getline(infile, codestring);
		getline(infile, str);
	}
	void Printing()
	{
		len = codestring.length();
		for (int i = 0; i < len; i++)
		{
			if (str[i] >= codestring[i])
				str[i] = str[i] - codestring[i] + 32;
			else if (str[i] < codestring[i])
			{
				str[i] = str[i] + (95 - codestring[i]) + 32;
			}
			outfile << codestring[i];
		}
		outfile << '\n';
		for (int i = 0; i < len; i++)
		{
			outfile << str[i];
		}
	}
private:
	ifstream infile;
	ofstream outfile;
	string codestring, str;
	int len;

};
int main(int argv, char* argc[])
{
	if (argv != 2)
		return 0;
	encrypting a = encrypting(argc[1]);
	a.Getline();
	a.printing();
	decoding b = decoding();
	b.Getline();
	b.Printing();
	return 0;
	}