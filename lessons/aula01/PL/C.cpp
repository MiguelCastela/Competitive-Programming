#include <iostream>
using namespace std;

int main(){
    int nump;
    double qol;
    double numy;
    double prod = 0;
    
    cin >> nump ;
    for (int i = 0; i < nump; i++){
        cin >> qol >> numy;
        prod += qol * numy;
    }
    cout << prod << "\n";
    return 0;  
}
