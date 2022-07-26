#include <iostream>
int main()
{
    using namespace std;
    int carrots;
    cout << "How mang carots do you have?" << endl;
    // cin将通过键盘输入的一系列字符转换为接收信息的变量能接受的形式
    cin >> carrots; // C++ input
    carrots += 2;
    // cout能够识别类型的功能表示，并且可拓展
    // cout的输出紧跟在前一条cout语句的输出后面
    cout << "Now you have " << carrots << " carrots." << endl;
    return 0;
    int ab;
}