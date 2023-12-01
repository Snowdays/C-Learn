#include <iostream>

using namespace std;

void pro_4(void);
void pro_7(void);

struct car
{
    /* data */
    int year;
    string name;
};

int main()
{
    pro_7();
    return 0;
}

void pro_4()
{
    int n = 0;
    double daphne_money = 100;
    double cleo_money = 100;

    while (cleo_money <= daphne_money)
    {
        cout << "Year " << ++n << ':' << endl;
        daphne_money += 10;
        cleo_money += cleo_money * 0.05;
        cout << "Cleo's money = " << cleo_money;
        cout << ", Daphne's money = " << daphne_money << endl;
    }
    cout << "After " << n << " years, ";
    cout << "Cleo's money";
    cout << " > Daphne's money." << endl;
}

void pro_7()
{
    int num;

    cout << "How many cars do you wish to catalog? ";
    (cin >> num).get();
    //创建对应数量的动态数组
    car *many_cars = new car[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i + 1 << ':' << endl;
        cout << "Please enter the make: ";
        getline(cin, many_cars[i].name);
        cout << "Please enter the year made: ";
        (cin >> many_cars[i].year).get();
    }

    cout << "Here is your collection:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << many_cars[i].year;
        cout << ' ' << many_cars[i].name << endl;
    }
    delete[] many_cars;
}