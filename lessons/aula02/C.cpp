#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s, const char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<string> words;
  string s;
  string tudo;
  set<string> result;
  while (cin >> s) {
    tudo += s + " ";
  }
  words = split(tudo, ' ');

  for (int i = 0; i < words.size(); i++) {
    for(int j = 0; j < words.size() ; j++){
      if (i == j) continue;
      result.insert(words[i]+ words[j]);
    }
  }

for (const auto &str : result) {
    cout << str << endl;
}
}