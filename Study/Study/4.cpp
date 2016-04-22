/*#include<iostream>

using namespace std;
class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(char* nam, int ag) : name(nam), age(ag)
	{
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};
class MyFriendDatilInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDatilInfo(char *add, char* phon, char* nam, int n) : MyFriendInfo(nam, n), addr(add), phone(phon)
	{
		ShowMyFriendDetailInfo();
	}
	void ShowMyFriendDetailInfo();
};
int main()
{
	MyFriendDatilInfo m("usaming hoshi", "010-****-2942", "SungBin Park", 17);
	return 1;
}

void MyFriendDatilInfo::ShowMyFriendDetailInfo()
{
	ShowMyFriendInfo();
	cout << "주소: " << addr << endl;
	cout << "전화: " << phone << endl << endl;
}
*/