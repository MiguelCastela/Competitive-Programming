#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main(){
    int num;
    cin >> num;
    for(int i = 0; i< num; i++){
    int n;
    cin >> n;
    set<int> a;
    for(int i = 0; i <n ; i++){
        int b;
        cin >> b;
        a.insert(b);
    }
    if(a.size() == n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    }
    return 0;
}
