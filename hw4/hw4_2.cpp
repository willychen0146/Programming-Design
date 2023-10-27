#include<iostream>

using namespace std;

int main(){
int int1, int2, int3, mid = 0;
cin >> int1 >> int2 >> int3;
if(int2 <= int1 && int1 <= int3 || int3 <= int1 && int1 <= int2){
    mid = int1;
}
else if(int3 <= int2 && int2 <= int1 || int1 <= int2 && int2 <= int3){
    mid = int2;
}    
else{
    mid = int3;
}
    cout << mid;
    return 0;
}