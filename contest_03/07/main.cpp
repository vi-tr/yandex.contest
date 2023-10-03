#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

bool sort_by_2nd(tuple<string, int> x, tuple<string, int> y) {
    return (get<1>(x) == get<1>(y) ? 
            get<0>(x) <  get<0>(y) :
            get<1>(x) >  get<1>(y)
           );
}

int main() {
    ifstream file("data.txt");
    string word, prevword;
    map<string, map<string,int>> lookup;
    prevword = "stopword"; // sentinel value
    file >> word;
    while (word != "stopword") {
        if (lookup[prevword].find(word) == lookup[prevword].end()) {
            lookup[prevword][word] = 1;
        } else {
            lookup[prevword][word] += 1;
        }
        prevword = word;
        file >> word;
    }

    map<string, vector<string>> wrangled_lookup;
    for (auto& [prevword, word] : lookup) {
        vector<tuple<string, int>> temp;
        for (auto& [k, v] : word) {
            temp.push_back(make_tuple(k, v));
        }
        sort(temp.begin(), temp.end(), sort_by_2nd);
        for (auto& x : temp) {
            wrangled_lookup[prevword].push_back(get<0>(x));
        }
    }

    string target;
    cin >> target;
    if (wrangled_lookup.find(target) == wrangled_lookup.end()) {
        cout << "-";
        return 0;
    }
    for (int i = 0; (i<3) && (i<wrangled_lookup[target].size()); i++) {
        cout << wrangled_lookup[target][i] << " ";
    }
    return 0;
}
