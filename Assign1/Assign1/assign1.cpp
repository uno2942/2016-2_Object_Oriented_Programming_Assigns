#include<iostream>
#include<fstream>
#include<string>

struct twodim{
	int r;
	int c;
	float* a;
};

void get_twodim(twodim&, int, int);
float& val(int, int, twodim&);
void free_twodim(twodim&);


int main()
{
	std::ifstream infile;
	std::ofstream outfile;
	twodim parray;
	int r, c;
	infile.open("204_input1.txt");
	if (!infile)
	{
		std::cout << "Unable to open";
		return 1;
	}
	outfile.open("204_output1.txt");

	infile >> r;	infile >> c;

	get_twodim(parray, r, c);

	for (int j = 0; j < r; j++)
	{
		for (int k = 0; k < c; k++)
		{
			infile >> val(j, k, parray);
			outfile << (val(j, k, parray)=val(j,k,parray)*(j+1)*(k+1)) << ' ';
		}
		outfile << std::endl;
	}

	free_twodim(parray);
	infile.close();
	outfile.close();
return 0;
}

void get_twodim(twodim& parray, int row, int col)
{
	parray.r = row;
	parray.c = col;
	parray.a = new float[row*col];
}
float& val(int i, int j, twodim& parray)
{
	return parray.a[i*parray.c + j];
}

void free_twodim(twodim& parray)
{
	delete[] parray.a;
	}