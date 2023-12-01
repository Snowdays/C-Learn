#include <iostream>
#include <cstring>

using namespace std;

void pro_3()
{
    const unsigned k_nameMaxLen = 64;

    char szFirstname[k_nameMaxLen];
    cout << "Enter your first name: ";
    cin.get(szFirstname, k_nameMaxLen).get();

    char szLastname[k_nameMaxLen];
    cout << "Enter your last name: ";
    //可避免读入换行符
    cin.get(szLastname, k_nameMaxLen).get();

    char *const psz = new char[strlen(szFirstname) + strlen(szLastname) + 1];
    strcpy(psz, szLastname);
    strcat(psz, ", ");
    strcat(psz, szFirstname);
    cout << "Here's the information in a single string: " << psz;
    delete[] psz;

    cout << endl;
}

struct Pizza
{
    string name;
    double diameter;
    double weight;
};
void pizza()
{
    Pizza *p_pizza = new Pizza;
    cout << "please input your pizza diameter: ";
    cin >> p_pizza->diameter;

    cout << "please input your pizza name: ";
    //避免读入换行符
    cin.get();
    getline(cin, p_pizza->name);

    cout << "please input your pizza weight: ";
    cin >> p_pizza->weight;

    cout << "pizza name: " << p_pizza->name << " pizza diameter: " << p_pizza->diameter << " pizza weight: " << p_pizza->weight << endl;

    delete p_pizza;
    p_pizza = NULL;
}

struct getinfo
{
    /* data */
    char first_name[20];
    char last_name[20];
    int age;
    char letter_grade;
};

int main()
{
    getinfo *ge = new getinfo;
    cout << "What is your first name?";
    cin.get(ge->first_name, 20).get();
    cout << "What is your last name?";
    cin.get(ge->last_name, 20).get();
    cout << "What letter grade do you deserve?";
    cin >> (*ge).letter_grade;
    cout << "What is your age?";
    cin >> ge->age;
    cout << "Name: " << (*ge).last_name << "," << (*ge).first_name << endl;
    cout << "Age: " << ge->age << endl;
    cout << "Grade: " << char(ge->letter_grade + 1);
    delete ge;
    pro_3();
    pizza();
    return 0;
}
