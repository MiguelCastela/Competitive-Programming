#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(){
    int snooze;
    cin >> snooze;
    int hour;
    int counter = 0;
    int minute;
    cin >> hour >> minute;

    while(hour != 7 && hour != 17 && minute != 7 && minute != 17 && minute != 27 && minute != 37 && minute != 47 && minute != 57){
            if (minute - snooze < 0){
                minute = 60 + (minute - snooze);
                if (hour == 0){
                    hour = 23;
                }else{hour--;}
                counter++;
            }else{
                minute = minute - snooze;
                counter++;
            }
        }
    cout << counter << endl;
}