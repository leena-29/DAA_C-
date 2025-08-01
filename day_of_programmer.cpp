#include <iostream>
using namespace std;

string dayOfProgrammer(int year) {
    if (year == 1918) {
        // Transition year from Julian to Gregorian
        return "26.09.1918";
    } else if ((year < 1918 && year % 4 == 0) || 
               (year > 1918 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))) {
        // Leap year (Julian or Gregorian)
        return "12.09." + to_string(year);
    } else {
        // Non-leap year
        return "13.09." + to_string(year);
    }
}

int main() {
    int year;
    cin >> year;
    cout << dayOfProgrammer(year) << endl;
    return 0;
}
