#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;
int64_t gcd(int64_t a, int64_t b) {
return b == 0 ? a : gcd(b, a%b);}
int64_t lcm(int64_t a, int64_t b) {
return a / gcd(a, b) * b;
}

int main(){
    int num;
    cin >> num;
    int num_output;
    int year =0;
    int cicada1 =0;
    int cicada2 = 0;
    int smallest_year = INT_MAX;
    for(int i = 0; i<num ; i++){
        cin >> year >> cicada1 >> cicada2;
        //cout << year << " " << cicada1 << " " << cicada2 << " ";
        year += lcm(cicada1,cicada2);
        if (year < smallest_year){
            smallest_year = year;
        } 
    }
    if (year < smallest_year){
            smallest_year = year;
        } 
    cout << smallest_year << endl;
    return 0;
}