#include<iostream>
using namespace std;
#include <string> 
#define MAX 1000 

// ������ϵ�˽ṹ��  
struct Person
{
	string m_Name; //�洢����  
	int m_Sex; // 1�������ԣ�2����Ů��
	int m_Age; // �洢����
	string m_Phone; //�洢�绰���� 
	string m_Addr; //�洢��ͥסַ
};

// ����ͨѶ¼�ṹ��  
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size; //��¼��ǰ�洢����ϵ������
};

// �˵���ʾ
void showmenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

// ���
void addPerson(Addressbooks* abs)
{
	// �ж��Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		// ����
		string name;
		cout << "������������" << endl;
		cin >> name;  
		abs->personArray[abs->m_Size].m_Name = name;

		// �Ա�
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl; 
		}

		// ����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age; 
		abs->personArray[abs->m_Size].m_Age = age;

		// ��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;  // ����绰���洢
		abs->personArray[abs->m_Size].m_Phone = phone;  // �洢�绰

		// ��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;  // �����ַ���洢
		abs->personArray[abs->m_Size].m_Addr = address;  // �洢��ַ

		// ����ͨѶ¼����
		abs->m_Size++;  
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls"); // ����

	}
}

// ��ʾ
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			// ���ÿ����ϵ�˵�����
			cout << "������" << abs->personArray[i].m_Name << "\t";
			// ����Ա�ʹ����Ԫ������ж��Ա�
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << "\t";
			cout << endl;
		}
	}

	system("pause");
	system("cls");
}


int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		// ��鵱ǰ��ϵ�˵������Ƿ����ѯ������ƥ��
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;  // ���δ�ҵ������� -1
}

// ɾ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name; 

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		// ���ҵ�������λ�ÿ�ʼ�����ν��������ϵ��ǰ��
		for (int i = ret; i < abs->m_Size - 1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];  // ǰ����ϵ��
		}
		abs->m_Size--;  // ����
		cout << "ɾ���ɹ�" << endl;
	}
	else  // ret == -1
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

// ����
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

// �޸�
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		// ����
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		// �Ա�
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		// ����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		// ��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		// ��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

// ���
void cleanPerson(Addressbooks* abs)
{
	char choice;
	cout << "��ȷ��Ҫ���ͨѶ¼��(Y/N): ";
	cin >> choice; 

	if (choice == 'Y' || choice == 'y') 
	{
		abs->m_Size = 0;  // ��ͨѶ¼����ϵ����������Ϊ 0
		cout << "ͨѶ¼�����" << endl;
	}
	else 
	{
		cout << "ȡ����ղ���" << endl;
	}

	system("pause");
	system("cls"); 
}


int main()
{
	int select = 0;

	// ����ͨѶ¼�ṹ�����
	Addressbooks abs;
	// ��ʼ��ǰ��Ա����
	abs.m_Size = 0;

	while (true)
	{
		showmenu();

		cin >> select;

		switch (select)
		{
		case 1: // ���
			addPerson(&abs);
			break;
		case 2: // ��ʾ
			showPerson(&abs);
			break;
		case 3: // ɾ��
			deletePerson(&abs);
			break;
		case 4: // ����
			findPerson(&abs);
			break;
		case 5: // �޸�
			modifyPerson(&abs);
			break;
		case 6: // ���
			cleanPerson(&abs);
			break;
		case 0: // �˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}