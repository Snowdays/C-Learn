#include <iostream>
#include <windows.h> //使用window库中带有的SetConsoleOutputCP,打印中文不乱码

void onesing();
void twosing();
int countage(int age);
void counttem();

int main()
{
    using namespace std;
    SetConsoleOutputCP(65001);
    string name = "胡炜";
    string address = "翻斗大街翻斗花园二号楼1001室";
    int age;
    int distance;
    cout << "Hello,Welcome to the interview,My name is " << name << " and i live in " << address << endl;
    cout << "my home is ";
    cin >> distance;
    cout << distance * 220 << " yards from work" << endl;
    cout << "Let us sing you song:";
    onesing();
    onesing();
    twosing();
    twosing();
    cout << "please put your age:";
    cin >> age;
    cout << "month: " << countage(age) << endl;
    counttem();
}

void onesing()
{
    using std::cout;
    using std::endl;
    cout << " three blind mice" << endl;
}

void twosing()
{
    using std::cout;
    using std::endl;
    cout << " See how they run" << endl;
}

int countage(int age)
{
    int month = age * 12;
    return month;
}
void counttem()
{
    using std::cin;
    using std::cout;
    using std::endl;
    int cel;
    cout << "Please enter a Celsius value:";
    cin >> cel;
    cout << cel << " degrees celsius is " << 1.8 * cel + 32.0 << " degrees Fahrenheit.";
}