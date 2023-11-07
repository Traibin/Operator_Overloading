#include<iostream>
#include<string>
using namespace std;
//加号/减号运算符重载，重载函数包括成员函数重载和全局函数重载
//重载==关系运算符
//重载<<左移运算符
//重载 = 赋值运算符
class Person
{
public:
	int m_A;
	int m_B;
	string m_Name;
	int m_Age;
	int* m_Age1;
	//1、成员函数重载+号
	/*Person operator+(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}*/

	//2、成员函数重载-号
	/*Person operator-(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A - p.m_A;
		temp.m_B = this->m_B - p.m_B;
		return temp;
	}*/

	//3、重载==关系运算符
	Person()//默认构造函数
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

	//4、重载左移运算符<<
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
	//只能利用全局函数重载左移运算符
	friend ostream& operator<<(ostream& out, Person& p);
	//利用成员函数重载  左移运算符   p.operator<<(cout)  简化版本 p<<cout
	//不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	/*void operator<<(cout)
	{}*/

	//5、赋值运算符=
	Person(int age)
	{
		m_Age1 = new int(age);
	}
	//重载 赋值运算符
	Person& operator=(Person& p)
	{
		//编译器是提供浅拷贝
		//m_Age1 = p.m_Age1;

		//应该判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if (m_Age1 != NULL)
		{
			delete m_Age1;
			m_Age1 = NULL;
		}
		//深拷贝
		m_Age1 = new int(*p.m_Age1);
		return *this;
	}
};
//2、全局函数重载+号  代码顺序很重要
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
//只能利用全局函数重载左移运算符
ostream& operator<<(ostream& out, Person& p)//本质  operator<<（cout，p）简化 cout<<p
{
	//out为引用别名
	out << "m_A=" << p.m_A << "   " << "m_B=" << p.m_B;
	return out;
}
void test01()
{
	cout << "----------------------------------------------" << endl;
	cout << "加号运算符+" << endl;
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//成员函数重载+本质调用
	/*Person p3 = p1.operator+(p2);*/

	//全局函数重载+本质调用
	/*Person p3 = operator+(p1, p2);*/
	Person p3 = p1 + p2;

	//运算符重载也可以发生函数重载
	Person p4 = p1 + 1000;
	cout << "p4.m_A=" << p4.m_A << endl;
	cout << "p4.m_B=" << p4.m_B << endl;

	cout << "p3.m_A=" << p3.m_A << endl;
	cout << "p3.m_B=" << p3.m_B << endl;
}
void test02()
{
	cout << "----------------------------------------------" << endl;
	cout << "减号运算符-" << endl;
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
	cout << "关系运算符==" << endl;
	Person p1("Tom", 18);
	Person p2("Tom", 18);
	if (p1 != p2)
	{
		cout << "p1和p2是不相等的！" << endl;
	}
	else
	{
		cout << "p1和p2是相等的！" << endl;
	}
}
void test04()
{
	cout << "----------------------------------------------" << endl;
	cout << "左移运算符<<" << endl;
	Person p(10, 10);
	//p.m_A=10;
	//p.m_B=10;
	cout << p << endl;
}
void test05()
{
	cout << "----------------------------------------------" << endl;
	cout << "赋值运算符=" << endl;
	Person p1(19);
	Person p2(20);
	Person p3(30);
	p3 = p2 = p1;//赋值运算重载
	cout << "p1的年龄为：" << *p1.m_Age1 << endl;
	cout << "p2的年龄为：" << *p2.m_Age1 << endl;
	cout << "p3的年龄为：" << *p3.m_Age1 << endl;
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