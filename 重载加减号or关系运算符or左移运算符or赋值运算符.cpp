#include<iostream>
#include<string>
using namespace std;
//�Ӻ�/������������أ����غ���������Ա�������غ�ȫ�ֺ�������
//����==��ϵ�����
//����<<���������
//���� = ��ֵ�����
class Person
{
public:
	int m_A;
	int m_B;
	string m_Name;
	int m_Age;
	int* m_Age1;
	//1����Ա��������+��
	/*Person operator+(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}*/

	//2����Ա��������-��
	/*Person operator-(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A - p.m_A;
		temp.m_B = this->m_B - p.m_B;
		return temp;
	}*/

	//3������==��ϵ�����
	Person()//Ĭ�Ϲ��캯��
	{

	}
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	bool operator!=(Person& p)
	{
		if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
		{
			return true;
		}
		return false;
	}

	//4���������������<<
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
	//ֻ������ȫ�ֺ����������������
	friend ostream& operator<<(ostream& out, Person& p);
	//���ó�Ա��������  ���������   p.operator<<(cout)  �򻯰汾 p<<cout
	//�������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
	/*void operator<<(cout)
	{}*/

	//5����ֵ�����=
	Person(int age)
	{
		m_Age1 = new int(age);
	}
	//���� ��ֵ�����
	Person& operator=(Person& p)
	{
		//���������ṩǳ����
		//m_Age1 = p.m_Age1;

		//Ӧ���ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		if (m_Age1 != NULL)
		{
			delete m_Age1;
			m_Age1 = NULL;
		}
		//���
		m_Age1 = new int(*p.m_Age1);
		return *this;
	}
};
//2��ȫ�ֺ�������+��  ����˳�����Ҫ
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
Person operator-(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A - p2.m_A;
	temp.m_B = p1.m_B - p2.m_B;
	return temp;
}
Person operator+(Person& p, int num)
{
	Person temp;
	temp.m_A = p.m_A + num;
	temp.m_B = p.m_B + num;
	return temp;
}
Person operator-(Person& p, int num)
{
	Person temp;
	temp.m_A = p.m_A - num;
	temp.m_B = p.m_B - num;
	return temp;
}
//ֻ������ȫ�ֺ����������������
ostream& operator<<(ostream& out, Person& p)//����  operator<<��cout��p���� cout<<p
{
	//outΪ���ñ���
	out << "m_A=" << p.m_A << "   " << "m_B=" << p.m_B;
	return out;
}
void test01()
{
	cout << "----------------------------------------------" << endl;
	cout << "�Ӻ������+" << endl;
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//��Ա��������+���ʵ���
	/*Person p3 = p1.operator+(p2);*/

	//ȫ�ֺ�������+���ʵ���
	/*Person p3 = operator+(p1, p2);*/
	Person p3 = p1 + p2;

	//���������Ҳ���Է�����������
	Person p4 = p1 + 1000;
	cout << "p4.m_A=" << p4.m_A << endl;
	cout << "p4.m_B=" << p4.m_B << endl;

	cout << "p3.m_A=" << p3.m_A << endl;
	cout << "p3.m_B=" << p3.m_B << endl;
}
void test02()
{
	cout << "----------------------------------------------" << endl;
	cout << "���������-" << endl;
	Person p3;
	p3.m_A = 100;
	p3.m_B = 10;
	Person p4;
	p4.m_A = 300;
	p4.m_B = 10;
	Person p5 = p4 - p3;
	cout << "p5.m_A=" << p5.m_A << endl;
	cout << "p5.m_B=" << p5.m_B << endl;
}
void test03()
{
	cout << "----------------------------------------------" << endl;
	cout << "��ϵ�����==" << endl;
	Person p1("Tom", 18);
	Person p2("Tom", 18);
	if (p1 != p2)
	{
		cout << "p1��p2�ǲ���ȵģ�" << endl;
	}
	else
	{
		cout << "p1��p2����ȵģ�" << endl;
	}
}
void test04()
{
	cout << "----------------------------------------------" << endl;
	cout << "���������<<" << endl;
	Person p(10, 10);
	//p.m_A=10;
	//p.m_B=10;
	cout << p << endl;
}
void test05()
{
	cout << "----------------------------------------------" << endl;
	cout << "��ֵ�����=" << endl;
	Person p1(19);
	Person p2(20);
	Person p3(30);
	p3 = p2 = p1;//��ֵ��������
	cout << "p1������Ϊ��" << *p1.m_Age1 << endl;
	cout << "p2������Ϊ��" << *p2.m_Age1 << endl;
	cout << "p3������Ϊ��" << *p3.m_Age1 << endl;
}
int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	system("pause");
	return 0;
}