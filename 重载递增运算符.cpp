#include<iostream>
#include<string>
using namespace std;
//���ص��������
// a++ ��a++�����صĻ���ԭ����a
// ++a ��a++�����ص���a++��Ľ��
//�Զ�������
class MyInteger
{
	friend ostream& operator<<(ostream& out, MyInteger m);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����ֵ������Ϊ���غ���������
	//����ǰ��++�����  ��������Ϊ��һֱ��һ�����ݽ��е�������
	MyInteger& operator++()
	{
		//�Ƚ���++�����
		m_Num++;
		//�ٷ�������������
		return *this;
	}
	//���غ���++�����  ���ص���ֵ����Ϊtemp��һ���ֲ�������������ɾͱ��ͷţ�����û������
	MyInteger operator++(int)  //int����ռλ������������������ǰ�úͺ��õ���
	{
		//�� ��¼��ʱ���
		MyInteger temp = *this;

		//�� ����
		m_Num++;
		//��󽫼�¼���������
		return temp;
	}
private:
	int m_Num;
};
//�������������
ostream& operator<<(ostream& out, MyInteger myint)//��ԭ�� MyInteger &myint�е�&ɾ����
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