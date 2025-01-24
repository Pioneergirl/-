#include<iostream>
using namespace std;
#include <string> 
#define MAX 1000 

// 定义联系人结构体  
struct Person
{
	string m_Name; //存储姓名  
	int m_Sex; // 1代表男性，2代表女性
	int m_Age; // 存储年龄
	string m_Phone; //存储电话号码 
	string m_Addr; //存储家庭住址
};

// 定义通讯录结构体  
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size; //记录当前存储的联系人数量
};

// 菜单显示
void showmenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

// 添加
void addPerson(Addressbooks* abs)
{
	// 判断是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		// 姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;  
		abs->personArray[abs->m_Size].m_Name = name;

		// 性别
		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl; 
		}

		// 年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age; 
		abs->personArray[abs->m_Size].m_Age = age;

		// 联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;  // 输入电话并存储
		abs->personArray[abs->m_Size].m_Phone = phone;  // 存储电话

		// 家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;  // 输入地址并存储
		abs->personArray[abs->m_Size].m_Addr = address;  // 存储地址

		// 更新通讯录人数
		abs->m_Size++;  
		cout << "添加成功" << endl;

		system("pause");
		system("cls"); // 清屏

	}
}

// 显示
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			// 输出每个联系人的姓名
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			// 输出性别，使用三元运算符判断性别
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << "\t";
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
		// 检查当前联系人的姓名是否与查询的姓名匹配
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;  // 如果未找到，返回 -1
}

// 删除
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name; 

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		// 从找到的索引位置开始，依次将后面的联系人前移
		for (int i = ret; i < abs->m_Size - 1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];  // 前移联系人
		}
		abs->m_Size--;  // 更新
		cout << "删除成功" << endl;
	}
	else  // ret == -1
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

// 查找
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

// 修改
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		// 姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		// 性别
		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		// 年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		// 联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		// 家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

// 清空
void cleanPerson(Addressbooks* abs)
{
	char choice;
	cout << "您确定要清空通讯录吗？(Y/N): ";
	cin >> choice; 

	if (choice == 'Y' || choice == 'y') 
	{
		abs->m_Size = 0;  // 将通讯录的联系人数量重置为 0
		cout << "通讯录已清空" << endl;
	}
	else 
	{
		cout << "取消清空操作" << endl;
	}

	system("pause");
	system("cls"); 
}


int main()
{
	int select = 0;

	// 创建通讯录结构体变量
	Addressbooks abs;
	// 初始当前人员个数
	abs.m_Size = 0;

	while (true)
	{
		showmenu();

		cin >> select;

		switch (select)
		{
		case 1: // 添加
			addPerson(&abs);
			break;
		case 2: // 显示
			showPerson(&abs);
			break;
		case 3: // 删除
			deletePerson(&abs);
			break;
		case 4: // 查找
			findPerson(&abs);
			break;
		case 5: // 修改
			modifyPerson(&abs);
			break;
		case 6: // 清空
			cleanPerson(&abs);
			break;
		case 0: // 退出
			cout << "欢迎下次使用" << endl;
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