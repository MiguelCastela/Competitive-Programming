#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    int temp = 0;
    int b;
    cin >> b;
    vector<int> a;
    for(int i = 0; i < b; i++){
        int c;
        cin >> c;
        temp += c;
       
    }
    cout << temp << endl;
    }
    return 0;


}