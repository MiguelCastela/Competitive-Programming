#include <iostream>
using namespace std;

int main(){
    int easy;
    int medium;
    int hard;
    int num;
    cin >> easy >> medium >> hard >> num;

    if (easy > 0 && medium > 0 && hard > 0 && num >= 3 && num <= easy+medium+hard){
        cout << "YES" << "\n";
    }else {
        cout << "NO" << "\n";
    }
}




