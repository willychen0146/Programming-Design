#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> months(n);
    vector<int> days(n);
    
    for (int i = 0; i < n; i++) {
        cin >> months[i] >> days[i];
    }
    
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int minDifference = INT_MAX;
    
    for (int i = 1; i < n; i++) {
        int difference = 0;

        if (months[i] == months[i - 1]) {
            // Same month, calculate the absolute difference in days
            difference = abs(days[i] - days[i - 1]);
        } else if (months[i] > months[i - 1]) {
            // Different months, calculate days remaining in the current month plus days in the next months
            difference = daysInMonth[months[i - 1]] - days[i - 1] + days[i];
            for (int j = months[i - 1] + 1; j < months[i]; j++) {
                difference += daysInMonth[j];
            }
        } else {
            // The current month is after the previous month, so swap the months and days
            difference = daysInMonth[months[i] - 1] - days[i] + days[i - 1];
            for (int j = months[i] + 1; j < months[i - 1]; j++) {
                difference += daysInMonth[j];
            }
        }

        // Update the minimum difference
        if (difference < minDifference) {
            minDifference = difference;
        }
    }
    
    cout << minDifference - 1 << endl;

    return 0;
}
