#include <iostream>
using namespace std;

int main() {
    int month1, day1, month2, day2, month3, day3;

    // Input the dates
    cin >> month1 >> day1 >> month2 >> day2 >> month3 >> day3;

    // Define the days in each month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculate the absolute differences between the dates
    int date1 = day1;
    for (int i = 1; i < month1; i++) {
        date1 += daysInMonth[i];
    }
    // cout << date1 << endl;

    int date2 = day2;
    for (int i = 1; i < month2; i++) {
        date2 += daysInMonth[i];
    }
    // cout << date2 << endl;

    int date3 = day3;
    for (int i = 1; i < month3; i++) {
        date3 += daysInMonth[i];
    }
    // cout << date3 << endl;

    int diff1 = abs(date2 - date1);
    int diff2 = abs(date3 - date2);

    // Output the smaller difference
    if (diff1 < diff2) {
        cout << diff1 - 1 << endl;
    } else {
        cout << diff2 - 1 << endl;
    }

    return 0;
}
