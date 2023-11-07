#include<iostream>
using namespace std;
/*实现时间相加的关键语句
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
/*类外定义成员函数语法：
数据类型 类名：：函数名称（参数列表）*/
Time::Time()//构造函数，若无赋值进行初始化
{
    hours = minutes = 0;
}

Time::Time(int h, int m)//给Time赋值的构造函数
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)//给分钟进行加法
{
    minutes += m;//先加上分钟m，结果可能超过60。假设为70，语句意思为加上m。一般只用“+”需要三个操作数，而“+=”需要两个
    hours += minutes / 60;//除法最后只返回一个对应的数据类型（hours的数据类型为整型，以m=70为例，最后实现hours+1，若为double浮点则返回浮点类型）
    minutes %= 60;//分钟最后取余（以m=70为例，70%60=1余10，所以最后minutes=10）
}

void Time::AddHr(int h)//给小时进行加法
{
    hours += h;
}

void Time::Reset(int h, int m)//重新设置时间
{
    hours = h;
    minutes = m;
}
//该函数为普通函数实现时间相加
const Time Time::Sum(const Time& t) const//参数传递为引用，是因为传递引用速度更快，使用的内存将更少
{
    //引入时间对象，即将要加上的时间
    Time sum;//创建一个时间对象
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
    /*本代码创建对象副本，调用函数可以使用它。若返回的是引用，因为sum为局部变量，函数结束时就被删除了，那它将指向一个不存在的对象。
      使用返回类型为time意味着程序在删除之前将构造它的拷贝，调用函数得到它的拷贝*/
    //关键：不要返回指向局部变量或临时对象的引用，函数执行完毕后，它们都将消失，引用将指向不存在的数据
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}
/*重载语句
  数据类型（返回类型） 类名 ：：（关键字）operator (参数列表)*/
Time Time::operator+(const Time& t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
/*若为t4=t1+t2+t3会被转换为下列语句
  t4=t1.operator(t2+t3)
  t4=t1.operator(t2.operator(t3))
  函数调用t2.operator(t3)返回一个Time对象，然后与t1相加得到t4*/
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
