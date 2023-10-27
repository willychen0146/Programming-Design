# include <iostream>

using namespace std;

int main(){
	int hours, moments, seconds, extraTime;
	cin >> hours; 
	cin >> moments;
        cin >> seconds; 
	cin >> extraTime;
	seconds = seconds + extraTime;
	if(seconds >= 60){
		moments = moments + (seconds / 60);
		seconds = seconds % 60;
	}

	if(moments >= 60){
		hours = hours + (moments / 60);
		moments = (moments % 60);
	}
	cout << hours << ":" << moments << ":" << seconds;
	return 0;
}
