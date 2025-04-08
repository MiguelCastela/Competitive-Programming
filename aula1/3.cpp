#include <iostream>
using namespace std;
template<typename T>
T add(T a, T b){
    return a + b;
}

int main()
{
   int a = add<int>(2,3);
   double d = add<double>(4.5,3.0);
   cout << a << " " << d << "\n";
   return 0;
}

