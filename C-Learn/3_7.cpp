#include <iostream>

using namespace std;

void latitude();

int main()
{
    latitude();
}

void latitude()
{
    double degree;
    double minute;
    double second;
    double latude;
    cout << "Enter a latude in degrees, minutes, and secends:" << endl;
    cout << "First, enter the degrees:";
    cin >> degree;
    cout << "Next, enter the minutes of arc:";
    cin >> minute;
    cout << "Finally, enter the seconds of arc:";
    cin >> second;
    latude = degree + minute / 60 + second / 3600;
    cout << degree << " degrees," << minute << " minutes," << second << " seconds = " << latude << " degrees";
}