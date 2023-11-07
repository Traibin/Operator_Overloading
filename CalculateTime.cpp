#include<iostream>
using namespace std;
/*ʵ��ʱ����ӵĹؼ����
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;*/
class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    const Time Sum(const Time& t) const;
    void Show() const;
    Time operator+(const Time& t) const;
};
/*���ⶨ���Ա�����﷨��
�������� ���������������ƣ������б�*/
Time::Time()//���캯�������޸�ֵ���г�ʼ��
{
    hours = minutes = 0;
}

Time::Time(int h, int m)//��Time��ֵ�Ĺ��캯��
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)//�����ӽ��мӷ�
{
    minutes += m;//�ȼ��Ϸ���m��������ܳ���60������Ϊ70�������˼Ϊ����m��һ��ֻ�á�+����Ҫ����������������+=����Ҫ����
    hours += minutes / 60;//�������ֻ����һ����Ӧ���������ͣ�hours����������Ϊ���ͣ���m=70Ϊ�������ʵ��hours+1����Ϊdouble�����򷵻ظ������ͣ�
    minutes %= 60;//�������ȡ�ࣨ��m=70Ϊ����70%60=1��10���������minutes=10��
}

void Time::AddHr(int h)//��Сʱ���мӷ�
{
    hours += h;
}

void Time::Reset(int h, int m)//��������ʱ��
{
    hours = h;
    minutes = m;
}
//�ú���Ϊ��ͨ����ʵ��ʱ�����
const Time Time::Sum(const Time& t) const//��������Ϊ���ã�����Ϊ���������ٶȸ��죬ʹ�õ��ڴ潫����
{
    //����ʱ����󣬼���Ҫ���ϵ�ʱ��
    Time sum;//����һ��ʱ�����
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
    /*�����봴�����󸱱������ú�������ʹ�����������ص������ã���ΪsumΪ�ֲ���������������ʱ�ͱ�ɾ���ˣ�������ָ��һ�������ڵĶ���
      ʹ�÷�������Ϊtime��ζ�ų�����ɾ��֮ǰ���������Ŀ��������ú����õ����Ŀ���*/
    //�ؼ�����Ҫ����ָ��ֲ���������ʱ��������ã�����ִ����Ϻ����Ƕ�����ʧ�����ý�ָ�򲻴��ڵ�����
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}
/*�������
  �������ͣ��������ͣ� ���� �������ؼ��֣�operator (�����б�)*/
Time Time::operator+(const Time& t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
/*��Ϊt4=t1+t2+t3�ᱻת��Ϊ�������
  t4=t1.operator(t2+t3)
  t4=t1.operator(t2.operator(t3))
  ��������t2.operator(t3)����һ��Time����Ȼ����t1��ӵõ�t4*/
int main()
{
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    // function notation
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
 
    system("pause");
    return 0;
}
