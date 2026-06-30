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

vector<vector<int> > matrix;
vector<int> weights;
vector<int> prices;
vector<int> max_weight;

int ksbu(vector<int> &weight, vector<int> &prices, int num_objects, int max_weight_index) {
    matrix.assign(num_objects + 1, vector<int>(31, 0));
    for (int i = 0; i <= max_weight_index; i++) {
        matrix[0][i] = 0;
    }
    for (int i = 1; i <= num_objects; i++) {
        for (int j = 0; j <= max_weight_index; j++) {
            if (weight[i - 1] > j) {
                matrix[i][j] = matrix[i - 1][j];
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - weight[i - 1]] + prices[i - 1]);
            }
        }
    }
    return matrix[num_objects][max_weight_index];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int times;
    cin >> times;

    while (times--) {
        int num_objects;
        cin >> num_objects;

        weights.assign(num_objects, 0);
        prices.assign(num_objects, 0);

        for (int i = 0; i < num_objects; i++) {
            cin >> prices[i] >> weights[i];
        }

        int num_people;
        cin >> num_people;

        max_weight.assign(num_people, 0);
        for (int i = 0; i < num_people; i++) {
            cin >> max_weight[i];
        }


        int total_value = 0;
        for (int i = 0; i < num_people; i++) {
            total_value += ksbu(weights,prices, num_objects, max_weight[i]);
        }

        cout << total_value << endl;
    }

    return 0;
}