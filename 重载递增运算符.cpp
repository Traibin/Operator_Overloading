#include<iostream>
#include<string>
using namespace std;
//重载递增运算符
// a++ 对a++，返回的还是原来的a
// ++a 对a++，返回的是a++后的结果
//自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& out, MyInteger m);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//返回值不能作为重载函数的条件
	//重载前置++运算符  返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		//先进行++运算符
		m_Num++;
		//再返回自身做返回
		return *this;
	}
	//重载后置++运算符  返回的是值，因为temp是一个局部变量，运行完成就被释放，引用没有作用
	MyInteger operator++(int)  //int代表占位参数，可以用于区分前置和后置递增
	{
		//先 记录当时结果
		MyInteger temp = *this;

		//后 递增
		m_Num++;
		//最后将记录结果做返回
		return temp;
	}
private:
	int m_Num;
};
//重载左移运算符
ostream& operator<<(ostream& out, MyInteger myint)//把原来 MyInteger &myint中的&删除了
{
	out << myint.m_Num << endl;
	return out;
}
void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}