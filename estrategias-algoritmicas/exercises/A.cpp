#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> numbers;
    int num;
    while(cin >> num){
        if(num != 0){
            //cout << num << endl;
            for(int i=0; i<num; i++){
                int n;
                cin >> n;
                numbers.push_back(n);
            }
            bool rigged = true;
            for(int i=0; i<numbers.size(); i++){
                int number1 = numbers[i];   
                for(int l=i+1; l<numbers.size(); l++){
                    int number2 = numbers[l];
                        for(int s=l+1; s<numbers.size(); s++){
                            int number3 = numbers[s];
                            if(number1 < 0 && number2 <0){
                                if(number3 > 0){
                                    if((-number2) + (-number1) == number3){
                                    rigged = false;
                                    break;
                                    }
                                }
                            }else if(number1> 0 && number2>0){
                                if(number3 < 0){
                                    if(number2 + number1 == -number3){
                                        rigged = false;
                                        break;
                                    }
                                }
                            }else{
                                if(number1 > 0 && number2<0){
                                    if(number3>0){
                                        if(number3 + number1 == -number2){
                                            rigged = false;
                                            break;
                                        }
                                    }else{
                                        if(-number3 + (-number2) == number1){
                                            rigged = false;
                                            break;
                                        }
                                    }
                                }else{
                                    if(number3>0){
                                        if(number3 + number2 == -number1){
                                            rigged = false;
                                            break;
                                        }
                                    }else{
                                        if(-number3 + (-number1) == number2)
                                            rigged = false;
                                            break;
                                    }
                                }
                            }
                        }
                    }
                }
            if(rigged){
                cout << "Rigged" << endl;
            }else{
                cout << "Fair" << endl;
            }
            numbers.clear();
        }
    }
}