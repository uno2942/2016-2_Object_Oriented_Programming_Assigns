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
		cout << "0. 구성원 파일 로드"<<endl;
		cout << "1. 전체 구성원 조회"<<endl;
		cout << "2. 학과(부서)구성원 조회" << endl;
		cout << "3. 이름으로 검색" << endl;
		cout << "4. ID로 검색" << endl;
		cout << "5. 구성원 추가" << endl;
		cout << "6. 구성원 정보 수정" << endl;
		cout << "7. 구성원 정보 삭제" << endl;
		cout << "8. 구성원 목록 저장" << endl;
		cout << "9. 프로그램 종료" << endl;
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
				cout << "학과(부서) 입력: ";
				cin >> s;
				for (int i = 0; i < 3; i++)
					list[i]->InquireByDept(s.c_str());
		}break;
		case 3:
		{
			string name;
			cout << "이름 입력: ";
			cin >> name;
			for (int i = 0; i < 3; i++)
				list[i]->InquireByName(name.c_str());
		}break;
		case 4:
		{
			int ID;
			cout << "ID 입력";
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
			cout << "구성원 소속 선택 (1. 교수 2. 직원 3. 학생): ";
			cin >> ID;
			temp = list[ID - 1];
			cout << "ID 입력";
			cin >> ID;
			cout << "이름 입력: ";
			cin >> s1;
			cout << "학과(부서) 입력: ";
			cin >> s2;
			cout << "직급 입력: ";
			cin >> s3;
			cout << "메일 입력";
			cin >> s4;
			temp->Add(s1.c_str(), ID, s2.c_str(), s3.c_str(), s4.c_str());
		}break;
		case 6:
		{
			int ID;
			cout << "ID 입력";
			cin >> ID;
			for (int i = 0; i < 3; i++)
			{
				list[i]->Modify(ID);
			}
		}break;
		case 7:
		{
			int ID;
			cout << "ID 입력";
			cin >> ID;
			for (int i = 0; i < 3; i++)
				list[i]->Delete(ID);
		}
	//	case 8:
		default: "다시 입력해주세요.";
		}
	}
}