/*#include<iostream>
#include<fstream>
#include<string>

struct twodim{
	int r;
	int c;
	float* a;
};

void get_twodim(twodim&, int, int);
float& val(int, int, twodim&, std::ifstream&);
void free_twodim(twodim&);


int main()
{
	std::ifstream infile;
	std::ofstream outfile;
	std::string str[6] = { "204_input1.txt", "204_input2.txt", "204_input3.txt", "204_output1.txt", "204_output2.txt", "204_output3.txt" };
	twodim parray;
	int r, c;
	for (int i = 0; i < 3; i++)
	{
		infile.open(str[i]);
		if (!infile)
		{
			std::cout << "Unable to open";
			continue;
		}
		outfile.open(str[i + 3]);

		infile >> r;	infile >> c;

		get_twodim(parray, r, c);

		for (int k = 0; k < r; k++)
		{
			for (int j = 0; j < c; j++)
			{
				outfile << val(j, k, parray, infile) << ' ';//pointer?
			}
			outfile << std::endl;
		}

		free_twodim(parray);
		infile.close();
		outfile.close();
	}
	return 0;
}

void get_twodim(twodim& parray, int row, int col)
{
	parray.r = row;
	parray.c = col;
	parray.a = new float[row*col];
}
float& val(int i, int j, twodim& parray, std::ifstream& infile)
{
	int temp;
	infile >> temp;
	parray.a[i + j*parray.c] = temp*(i + 1)*(j + 1);
	return parray.a[i + j*parray.c];//¹®Á¦;;;
}

void free_twodim(twodim& parray)
{
	delete parray.a;
	}*/