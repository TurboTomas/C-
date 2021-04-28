#include <iostream>
using namespace std;
#include <string> 
#define MAX 1000

struct Person
{
	string m_Name;//姓名 
	int m_Sex;//年龄：1男，2女 
	int m_Age;//年龄 
	string m_Phone;//电话 
	string m_Address;//地址 
};

struct AddressBook
{
	struct Person personArray[MAX];//保存联系人的数组	
	int m_Size;//通讯录中当前记录人数 
};

void showMenu();
void addPerson(AddressBook* abs);
void showPerson(AddressBook* abs);
int isExist(AddressBook* abs, string name);
void deletePerson(AddressBook* abs);
void findPerson(AddressBook* abs);
void modifyPerson(AddressBook* abs);
void clearPerson(AddressBook* abs);

int main(int argc, char** argv)
{
	//创建通讯录结构体变量
	AddressBook abs;
	//初始化当前人数
	abs.m_Size = 0;

	int select = 0;//用户选择变量 

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);//地址传递修改实参 
			break;
		case 2://显示联系人 
			showPerson(&abs);
			break;
		case 3://删除联系人 
			deletePerson(&abs);
			break;
		case 4://查找联系人 
			findPerson(&abs);
			break;
		case 5://修改联系人 
			modifyPerson(&abs);
			break;
		case 6://清空联系人 
			clearPerson(&abs);
			break;
		case 0://退出 
			cout << "欢迎使用！" << endl;
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

void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1，添加联系人*****" << endl;
	cout << "*****2，显示联系人*****" << endl;
	cout << "*****3，删除联系人*****" << endl;
	cout << "*****4，查找联系人*****" << endl;
	cout << "*****5，修改联系人*****" << endl;
	cout << "*****6，清空联系人*****" << endl;
	cout << "*****0，退出通讯录*****" << endl;
	cout << "***********************" << endl;
}

void addPerson(AddressBook* abs)
{
	//判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	//添加联系人 
	else
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入电话：" << endl;
		string phone = "";
		while (true)
		{
			cin >> phone;
			if (phone.size() == 11)
			{
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入家庭住址：" << endl;
		string address = "";
		while (true)
		{
			cin >> address;
			if (address.size() < 20 && address.size() > 0)
			{
				abs->personArray[abs->m_Size].m_Address = address;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功！" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(AddressBook* abs)
{
	//判断通讯录的人数 
	if (abs->m_Size == 0)
	{
		cout << "记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Address << endl;
		}
	}

	system("pause");
	system("cls");
}

int isExist(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return(i);
		}
	}
	return(-1);
}

void deletePerson(AddressBook* abs)
{
	cout << "请输入删除联系人的名字：" << endl;
	string name = "";
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(AddressBook* abs)
{
	cout << "请输入查找联系人的名字：" << endl;
	string name = "";
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Address << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs)
{
	cout << "请输入要修改的联系人：" << endl;
	string name = "";
	cin >> name;

	cout << "请联系的修改信息：" << endl;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入电话：" << endl;
		string phone = "";
		while (true)
		{
			cin >> phone;
			if (phone.size() == 11)
			{
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入家庭住址：" << endl;
		string address = "";
		while (true)
		{
			cin >> address;
			if (address.size() < 20 && address.size() > 0)
			{
				abs->personArray[ret].m_Address = address;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void clearPerson(AddressBook* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空！" << endl;

	system("pause");
	system("cls");
}