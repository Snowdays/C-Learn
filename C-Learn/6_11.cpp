#include <iostream>
#include <array>
using namespace std;

void pro_2();
void show_menu();
void pro_4();

const int NUM = 5;
const int strsize = 20;

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

int main()
{
    pro_4();
    return 0;
}

void pro_2()
{
    int i = 0, j = 0;
    unsigned int count = 0;
    const int ArSize = 10;
    array<double, ArSize> donations;
    double total = 0.0, average = 0.0;

    cout << "You may enter up to " << ArSize;
    cout << " donation (q to terminate)." << endl;
    cout << "donation #1: ";
    while (i < ArSize && cin >> donations[i])
    {
        if (++i < ArSize)
        {
            cout << "donation #" << i + 1 << ": ";
        }
    }

    for (j = 0; j < i; j++)
    {
        total += donations[j];
    }
    average = total / i;
    for (j = 0; j < i; j++)
    {
        if (average < donations[j])
        {
            ++count;
        }
    }

    if (0 == i)
    {
        cout << "No donation!" << endl;
    }
    else
    {
        cout << average << " = average of ";
        cout << i << " donations.\n";
        cout << count << " numbers are greater than the average." << endl;
    }
}

void pro_4()
{
    char ch;
    bop people[NUM] =
        {
            {"Wimp Macho", "Teacher", "WMA", 0},
            {"Raki Rhodes", "Junior Programmer", "RHES", 1},
            {"Celia Laiter", "Professor", "MIPS", 2},
            {"Hoppy Hipman", "Analyst Trainee", "HPAN", 1},
            {"Pat Hand", "Animal Keeper", "LOOPY", 2}};

    show_menu();
    cout << "Enter your choice: ";
    while (cin >> ch && ch != 'q')
    {
        switch (ch)
        {
        case 'a':
        {
            for (int i = 0; i < NUM; i++)
            {
                cout << people[i].fullname << endl;
            }
            break;
        }
        case 'b':
        {
            for (int i = 0; i < NUM; i++)
            {
                cout << people[i].title << endl;
            }
            break;
        }
        case 'c':
        {
            for (int i = 0; i < NUM; i++)
            {
                cout << people[i].bopname << endl;
            }
            break;
        }
        case 'd':
        {
            for (int i = 0; i < NUM; i++)
            {
                switch (people[i].preference)
                {
                case 0:
                {
                    cout << people[i].fullname << endl;
                    break;
                }
                case 1:
                {
                    cout << people[i].title << endl;
                    break;
                }
                case 2:
                {
                    cout << people[i].bopname << endl;
                    break;
                }
                }
            }
            break;
        }
        default:
        {
            cout << "Illegal input!" << endl;
            break;
        }
        }
        cout << "Next choice: ";
    }
    cout << "Bye!" << endl;
}
void show_menu()
{
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name     b. display by title" << endl;
    cout << "c. display by bopname  d. display by preference" << endl;
    cout << "q. quit" << endl;
    return;
}