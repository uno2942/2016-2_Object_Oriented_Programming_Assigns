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
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
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
	cout << "�ּ�: " << addr << endl;
	cout << "��ȭ: " << phone << endl << endl;
}
*/