#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){

    int num;
    while(cin >> num){
        if(num != 0){
            unordered_set<int> numSet;
            vector<int> numbers;
            //cout << num << endl;
            for(int i=0; i<num; i++){
                int n;
                cin >> n;
                numbers.push_back(n);
                numSet.insert(n);
            }
            bool rigged = true;
            for(int i=0; i<numbers.size(); i++){
                int number1 = numbers[i];   
                for(int l=i+1; l<numbers.size(); l++){
                    int number2 = numbers[l];
                            if(number1 < 0 && number2 <0){
                                int required = abs(number1) + abs(number2);
                                if(numSet.find(required) != numSet.end()){
                                    rigged = false;
                                    break;
                                }
                            }else if(number1> 0 && number2>0){
                                int required = number1 + number2;
                                if(numSet.find(-required) != numSet.end()){
                                    rigged = false;
                                    break;
                                }
                            }else{
                                    if(number1 > 0 && number2<0){
                                        int required;
                                        required > 0;
                                        required + number1 == -number2;
                                        if(numSet.find(required) != numSet.end()){
                                            rigged = false;
                                            break;
                                        }
                                    }else if (number1 < 0 && number2 > 0){
                                        int required;
                                        required < 0;
                                        abs(required) + abs(number1) == number2;
                                        if(numSet.find(required) != numSet.end()){
                                            rigged = false;
                                            break;
                                        }
                                }
                            }
                        }
                        if(!rigged) break;
                    }
            
            if(rigged){
                cout << "Rigged" << endl;
            }else{
                cout << "Fair" << endl;
            }
            numbers.clear();
            numSet.clear();
        }
    }

}
