#include <algorithm>
#include <istream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class CSVState {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

// State machine
vector<string> readCSVRow(const string &row) {
    CSVState state = CSVState::UnquotedField;
    vector<string> fields {""};
    size_t i = 0; // index of the current field
    for (char c : row) {
        switch (state) {
            case CSVState::UnquotedField:
                switch (c) {
                    case ',': // end of field
                              fields.push_back(""); i++;
                              break;
                    case '"': state = CSVState::QuotedField;
                              break;
                    default:  fields[i].push_back(c);
                              break; }
                break;
            case CSVState::QuotedField:
                switch (c) {
                    case '"': state = CSVState::QuotedQuote;
                              break;
                    default:  fields[i].push_back(c);
                              break; }
                break;
            case CSVState::QuotedQuote:
                switch (c) {
                    case ',': // , after closing quote
                              fields.push_back(""); i++;
                              state = CSVState::UnquotedField;
                              break;
                    case '"': // "" -> "
                              fields[i].push_back('"');
                              state = CSVState::QuotedField;
                              break;
                    default:  // end of quote
                              state = CSVState::UnquotedField;
                              break; }
                break;
        }
    }
    return fields;
}

vector<vector<string>> readCSV(istream &in) {
    vector<vector<string>> table;
    string row;
    while (!in.eof()) {
        getline(in, row, '\r');
        if (in.bad() || in.fail()) {
            break;
        }
        auto fields = readCSVRow(row);
        table.push_back(fields);
    }
    return table;
}

int main() {
    filebuf fb;
    vector<vector<string>> r;
    if (fb.open("train.csv", ios::in)) {
        istream is(&fb);
        if (is)
            r = readCSV(is);
        fb.close();
    }

    string pclass;
    int age;
    cin >> pclass >> age;
    
    vector<vector<string>> ans (r.size());
    auto it = copy_if(r.begin(), r.end(), ans.begin(), [pclass, age](vector<string> v){
        int fa;
        try {
            fa = stoi(v[5]);
        } catch (...) {
            fa = 0;
        }
        return (v[2] == pclass && v[4] == "female" && fa > age);
    });
    ans.resize(distance(ans.begin(),it));
    sort(ans.begin(), ans.end(), [](vector<string> a, vector<string> b){
        if (a[5] == b[5]) return a[3] < b[3];
        int fa;
        try {
            fa = stoi(a[5]);
        } catch (...) {
            fa = 0;
        }
        int fb;
        try {
            fb = stoi(b[5]);
        } catch (...) {
            fb = 0;
        }
        return fa < fb;
    });

    for (const auto& v : ans) {
        cout << v[3] << endl;
    }

    return 0;
}
