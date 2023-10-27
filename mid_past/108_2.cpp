// #include <iostream>
// using namespace std;

// void weapen1_kill(int, int*);
// void weapen2_kill(int, int*);

// int main () {
//   int weapen1, weapen2;
//   cin >> weapen1 >> weapen2;
//   int* weapen1_list = nullptr;
//   weapen1_list = new int[weapen1];
//   for (int i = 0; i < weapen1; i++) {
//     cin >> weapen1_list[i];
//   }
//   int* weapen2_list = nullptr;
//   weapen2_list = new int[weapen2];
//   for (int i = 0; i < weapen2; i++) {
//     cin >> weapen2_list[i];
//   }
  
//   int result[49] = {0}; // 0 = delete
//   for(int i = 0; i < 49; i++){
//     result[i] = i + 1;
//   }
  
//   // weapen1
//   for (int i = 0; i < weapen1; i++) {
//     int target = weapen1_list[i];
//     int temp_destroy1[9] = {0};
//     weapen1_kill(target, temp_destroy1);
//     for (int j = 0; j < 9; j++) {
//       if(temp_destroy1[j] <= 49 && temp_destroy1[j] >= 0)
//         if(result[temp_destroy1[j] - 1] != 0)
//           result[temp_destroy1[j] - 1] = 0;
//     }
//   }
//   // weapen2
//   for (int i = 0; i < weapen2; i++) {
//     int target = weapen2_list[i];
//     int temp_destroy2[25] = {0};
//     weapen2_kill(target, temp_destroy2);
//     for (int j = 0; j < 25; j++) {
//       if(temp_destroy2[j] <= 49 && temp_destroy2[j] >= 0)
//         if(result[temp_destroy2[j] - 1] != 0)
//           result[temp_destroy2[j] - 1] = 0;
//     }
//   }

//   for (int i = 0; i < 49; i++) {
//     if(result[i] != 0){
//       if(i > 0)
//         cout << ",";
//       cout << result[i];
//     }
//   }
//   cout << endl;


//   return 0;
// }

// void weapen1_kill(int target, int* temp_destroy1){ 
//   temp_destroy1[0] = target;
//   temp_destroy1[1] = target + 7;
//   temp_destroy1[2] = target - 7;
//   temp_destroy1[3] = target + 1;
//   temp_destroy1[4] = target - 1;
//   temp_destroy1[5] = target + 6;
//   temp_destroy1[6] = target + 8;
//   temp_destroy1[7] = target - 6;
//   temp_destroy1[8] = target - 8;
// }

// void weapen2_kill(int target, int* temp_destroy2){
//   temp_destroy2[0] = target;
//   temp_destroy2[1] = target + 1;
//   temp_destroy2[2] = target + 2;
//   temp_destroy2[3] = target + 3;
//   temp_destroy2[4] = target + 4;
//   temp_destroy2[5] = target + 5;
//   temp_destroy2[6] = target + 6;
//   temp_destroy2[7] = target - 1;
//   temp_destroy2[8] = target - 2;
//   temp_destroy2[9] = target - 3;
//   temp_destroy2[10] = target - 4;
//   temp_destroy2[11] = target - 5;
//   temp_destroy2[12] = target - 6;
//   temp_destroy2[13] = target + 7;
//   temp_destroy2[14] = target + 7*2;
//   temp_destroy2[15] = target + 7*3;
//   temp_destroy2[16] = target + 7*4;
//   temp_destroy2[17] = target + 7*5;
//   temp_destroy2[18] = target + 7*6;
//   temp_destroy2[19] = target - 7;
//   temp_destroy2[20] = target - 7*2;
//   temp_destroy2[21] = target - 7*3;
//   temp_destroy2[22] = target - 7*4;
//   temp_destroy2[23] = target - 7*5;
//   temp_destroy2[24] = target - 7*6;
// }


#include <iostream>
#include <array>
#include <vector>

using namespace std;

void weapen1_kill(int, array<int, 9>&);
void weapen2_kill(int, array<int, 25>&);

int main() {
    int weapen1, weapen2;
    cin >> weapen1 >> weapen2;

    vector<int> weapen1_list(weapen1);
    for (int i = 0; i < weapen1; i++) {
        cin >> weapen1_list[i];
    }

    vector<int> weapen2_list(weapen2);
    for (int i = 0; i < weapen2; i++) {
        cin >> weapen2_list[i];
    }

    array<int, 49> result;
    for (int i = 0; i < 49; i++) {
        result[i] = i + 1;
    }

    // weapen1
    for (int i = 0; i < weapen1; i++) {
        int target = weapen1_list[i];
        array<int, 9> temp_destroy1 = { 0 };
        weapen1_kill(target, temp_destroy1);
        for (int j = 0; j < 9; j++) {
            if (temp_destroy1[j] <= 49 && temp_destroy1[j] >= 1) {
                result[temp_destroy1[j] - 1] = 0;
            }
        }
    }

    // weapen2
    for (int i = 0; i < weapen2; i++) {
        int target = weapen2_list[i];
        array<int, 25> temp_destroy2 = { 0 };
        weapen2_kill(target, temp_destroy2);
        for (int j = 0; j < 25; j++) {
            if (temp_destroy2[j] <= 49 && temp_destroy2[j] >= 1) {
                result[temp_destroy2[j] - 1] = 0;
            }
        }
    }

    bool first_output = true;
    for (int i = 0; i < 49; i++) {
        if (result[i] != 0) {
            if (!first_output) {
                cout << ",";
            }
            cout << result[i];
            first_output = false;
        }
    }
    cout << endl;

    return 0;
}

void weapen1_kill(int target, array<int, 9>& temp_destroy1) {
    temp_destroy1[0] = target;
    temp_destroy1[1] = target + 7;
    temp_destroy1[2] = target - 7;
    temp_destroy1[3] = target + 1;
    temp_destroy1[4] = target - 1;
    temp_destroy1[5] = target + 6;
    temp_destroy1[6] = target + 8;
    temp_destroy1[7] = target - 6;
    temp_destroy1[8] = target - 8;

    // Check and adjust for the edges
    for (int& val : temp_destroy1) {
        if (val % 7 == 0) val = 0;
        if (val < 1) val = 0;
    }
}

void weapen2_kill(int target, array<int, 25>& temp_destroy2) {
    for (int i = 0; i < 25; i++) {
        temp_destroy2[i] = target + i - 12;
    }

    // Check and adjust for the edges
    for (int& val : temp_destroy2) {
        if (val % 7 == 0) val = 0;
        if (val < 1) val = 0;
    }
}