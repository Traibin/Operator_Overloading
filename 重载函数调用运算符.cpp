#include<iostream>
#include<string>
using namespace std;
//�����������������
class MyPrint
{
public:
	//���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};
void MyPrint02(string test)
{
	cout << test << endl;
}
void test01()
{
	MyPrint myprint;
	myprint("Hello world");//����ʹ�������ǳ������ں������ã���˳�Ϊ�º���
	MyPrint02("hello world");
}
//�º����ǳ���û�й̶���д��
class MyAdd
{
public:

	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
void test02()
{
	MyAdd myadd;
	int ret = myadd(100, 1000);
	cout << "ret=" << ret << endl;
	//������������
	cout << MyAdd()(100, 100) << endl;//MyAdd()����������������Ͷ�����
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}