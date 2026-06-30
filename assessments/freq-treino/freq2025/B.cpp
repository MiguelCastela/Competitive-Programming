#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 1;
    vector<int> a;
    a.push_back(n);
    while(n != 1){
        if(n %2 == 0){
            n = n/2;
            count ++;
            a.push_back(n);

        }else{
            n = 3*n + 1;
            count ++;
            a.push_back(n);
        }
    }
    cout << count << endl;
    for(int i = 0; i < a.size(); i++){
        if(i == a.size() - 1){
            cout << a[i];
            break;
        }
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}