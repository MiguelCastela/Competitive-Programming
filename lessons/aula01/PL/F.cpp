#include <iostream>
#include <string>
using namespace std;

int main(){
    string game;
    string word;
    int num;
    int flag = 0;
    int flag2 = 0;
    cin >> game;
    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> word;
        for (int j = 0; j < word.size(); j++){
            if (word[j] == game[0]){
                flag = 1;
            }
            flag2 = 0; 
            for(int k = 0; k < game.size(); k++){
                if (word[j] == game[k]){
                    flag2 = 1;
                    break; 
                }
            }
            if (flag2 == 0){
                break;
            }
        }
    if (flag2 == 1 && flag == 1 && word.size() >= 4)
        cout << word << "\n";
    flag = 0;
    flag2 = 0;
    }
    return 0;
}



/*

aaabb
map<char, bool> mp;

for(i -> game){
    mp[game[i]]++;
}
a - 2
b - 2

ab
for(i -> word){
    if(mp[word[i]]){
        mp[word[i]]--;
    }
    else{
        break;
    }
}


*/