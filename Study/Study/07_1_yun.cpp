/*#include<string>
#include<cstring>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
class Book
{
public:
	Book(string s1, string s2, int num)
	{
		title = new char[s1.length() + 1];
		strcpy_s(title, s1.length(), s1.c_str());
		isbn = new char[s2.length() + 1];
		strcpy_s(title, s2.length(), s2.c_str());
		price = num;
	}
	Book(const char* s1, const char* s2, int num)
	{
		title = new char[strlen(s1)+1];
		strcpy(title, s1); //?? strcpy_s
		isbn = new char[strlen(s2) + 1];
		strcpy(isbn, s2);
		price = num;
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title<<endl;
		cout << "ISBN: " << isbn<<endl;
		cout << "가격: " << price<<endl;
	}
private:
	char* title;
	char* isbn;
	int price;

};
class EBook : public Book
{
public:
	EBook(string s1, string s2, int num, string s3) : Book(s1, s2, num)
	{
		DRMKey=new char[s3.length()+1];
		strcpy(DRMKey, s3.c_str());
	}
	EBook(char* s1, char* s2, int num, char* s3) : Book(s1, s2, num)
	{
		DRMKey = new char[strlen(s3) + 1];
		strcpy(DRMKey, s3);
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
private:
	char* DRMKey;
};

int main()
{
	Book book("adsf", "asdf", 3);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("fdas", "fda", 123, "gsdfg");
	ebook.ShowBookInfo();
	return 0;
}
*/