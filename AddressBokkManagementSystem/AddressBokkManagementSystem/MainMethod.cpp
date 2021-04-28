#include <iostream>
using namespace std;
#include <string> 
#define MAX 1000

struct Person
{
	string m_Name;//���� 
	int m_Sex;//���䣺1�У�2Ů 
	int m_Age;//���� 
	string m_Phone;//�绰 
	string m_Address;//��ַ 
};

struct AddressBook
{
	struct Person personArray[MAX];//������ϵ�˵�����	
	int m_Size;//ͨѶ¼�е�ǰ��¼���� 
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
	//����ͨѶ¼�ṹ�����
	AddressBook abs;
	//��ʼ����ǰ����
	abs.m_Size = 0;

	int select = 0;//�û�ѡ����� 

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);//��ַ�����޸�ʵ�� 
			break;
		case 2://��ʾ��ϵ�� 
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ�� 
			deletePerson(&abs);
			break;
		case 4://������ϵ�� 
			findPerson(&abs);
			break;
		case 5://�޸���ϵ�� 
			modifyPerson(&abs);
			break;
		case 6://�����ϵ�� 
			clearPerson(&abs);
			break;
		case 0://�˳� 
			cout << "��ӭʹ�ã�" << endl;
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
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}

void addPerson(AddressBook* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	//�����ϵ�� 
	else
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "������绰��" << endl;
		string phone = "";
		while (true)
		{
			cin >> phone;
			if (phone.size() == 11)
			{
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "�������ͥסַ��" << endl;
		string address = "";
		while (true)
		{
			cin >> address;
			if (address.size() < 20 && address.size() > 0)
			{
				abs->personArray[abs->m_Size].m_Address = address;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ���" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(AddressBook* abs)
{
	//�ж�ͨѶ¼������ 
	if (abs->m_Size == 0)
	{
		cout << "��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Address << endl;
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
	cout << "������ɾ����ϵ�˵����֣�" << endl;
	string name = "";
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(AddressBook* abs)
{
	cout << "�����������ϵ�˵����֣�" << endl;
	string name = "";
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Address << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name = "";
	cin >> name;

	cout << "����ϵ���޸���Ϣ��" << endl;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "������绰��" << endl;
		string phone = "";
		while (true)
		{
			cin >> phone;
			if (phone.size() == 11)
			{
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "�������ͥסַ��" << endl;
		string address = "";
		while (true)
		{
			cin >> address;
			if (address.size() < 20 && address.size() > 0)
			{
				abs->personArray[ret].m_Address = address;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void clearPerson(AddressBook* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����գ�" << endl;

	system("pause");
	system("cls");
}