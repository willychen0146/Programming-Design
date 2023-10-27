#include <iostream>
using namespace std;

const int GRADE_CNT_MAX = 50; 

int highGradeCnt(int, int, const int []);

int main()
{
    int gradeCnt = 0, threshold = 0;
    int grades[GRADE_CNT_MAX] = {0};
    
    cin >> gradeCnt >> threshold;
    for(int i = 0; i < gradeCnt; i++)
        cin >> grades[i];
        
    cout << highGradeCnt(threshold, gradeCnt, grades);

    return 0;
}

int highGradeCnt(int threshold, int gradeCnt, const int grades[])
{
    int hgc = 0;
    for(int i = 0; i < gradeCnt; i++)
    {
        if(grades[i] >= threshold)
            hgc++;
    }
    return hgc;
}
