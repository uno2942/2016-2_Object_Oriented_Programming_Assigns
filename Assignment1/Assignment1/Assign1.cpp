#include"List.h"

int main()
{
	List* list[3];
	list[0] = new FacultyList;
	list[1] = new StaffList;
	list[2] = new StudentList;
	int num;
	while (1)
	{
		cout << "0. ������ ���� �ε�"<<endl;
		cout << "1. ��ü ������ ��ȸ"<<endl;
		cout << "2. �а�(�μ�)������ ��ȸ" << endl;
		cout << "3. �̸����� �˻�" << endl;
		cout << "4. ID�� �˻�" << endl;
		cout << "5. ������ �߰�" << endl;
		cout << "6. ������ ���� ����" << endl;
		cout << "7. ������ ���� ����" << endl;
		cout << "8. ������ ��� ����" << endl;
		cout << "9. ���α׷� ����" << endl;
		cout << ">>";
		cin >> num;
		if (num == 9)
			break;
		switch (num)
		{
	//	case 0:
		case 1:{
			for (int i = 0; i < 3; i++)
				list[i]->InquireAll();
		} break;
		case 2:{
			string s;
				cout << "�а�(�μ�) �Է�: ";
				cin >> s;
				for (int i = 0; i < 3; i++)
					list[i]->InquireByDept(s.c_str());
		}break;
		case 3:
		{
			string name;
			cout << "�̸� �Է�: ";
			cin >> name;
			for (int i = 0; i < 3; i++)
				list[i]->InquireByName(name.c_str());
		}break;
		case 4:
		{
			int ID;
			cout << "ID �Է�";
			cin >> ID;
			for (int i = 0; i < 3; i++)
			{
				list[i]->InquireByID(ID);
			}
		}
		case 5:
		{
			List* temp;
			int ID;
			string s1, s2, s3, s4;
			cout << "������ �Ҽ� ���� (1. ���� 2. ���� 3. �л�): ";
			cin >> ID;
			temp = list[ID - 1];
			cout << "ID �Է�";
			cin >> ID;
			cout << "�̸� �Է�: ";
			cin >> s1;
			cout << "�а�(�μ�) �Է�: ";
			cin >> s2;
			cout << "���� �Է�: ";
			cin >> s3;
			cout << "���� �Է�";
			cin >> s4;
			temp->Add(s1.c_str(), ID, s2.c_str(), s3.c_str(), s4.c_str());
		}break;
		case 6:
		{
			int ID;
			cout << "ID �Է�";
			cin >> ID;
			for (int i = 0; i < 3; i++)
			{
				list[i]->Modify(ID);
			}
		}break;
		case 7:
		{
			int ID;
			cout << "ID �Է�";
			cin >> ID;
			for (int i = 0; i < 3; i++)
				list[i]->Delete(ID);
		}
	//	case 8:
		default: "�ٽ� �Է����ּ���.";
		}
	}
}