#include <iostream>
using namespace std;
void inc_print(int const& n){
    //int aux = n + 1;
    n = n+1;
    cout << n << "\n";
}
int main()
{
    int n = 1;
    inc_print(n);
    std::cout << n << "\n";
    return 0;
}
