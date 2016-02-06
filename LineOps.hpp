#ifndef LINEOPS
#define LINEOPS

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool LineContains(string line, string word) {
    if (line.find(word) != string::npos) return true;
    else return false;
}

int GetFlag(vector<string> &vec) {
    string word = vec[0];
    if (word == "null") return -1;

    if (isdigit(word[0])) {
        int flag = atoi(word.c_str());
        return flag;
    }
    else return 0;
}

string RemoveSigns(string q) {
    string a = "";
    for (unsigned i = 0; i < q.length(); i++)
    {
        if ((q[i] == ':' && q[i + 1] == 'D') || (q[i] == 'c' && q[i + 1] == ':') || (q[i] == 'D' && q[i - 1] == ':') || (q[i] == '3' && q[i - 1] == ':') || (q[i] == ':' && q[i + 1] == '3') || q[i] == '!' || q[i] == '?' || q[i] == '.' || q[i] == ',' || q[i] == ')' || q[i] == '(' || q[i] == ':' || q[i] == ';' || q[i] == '-')
            a += "";
        else
            a += q[i];
    }
    return a;
}

vector<string> GetWords(string line, char token) {
    vector<string> words;
    string word = "";
    for(size_t i = 0; i != line.length(); ++i) {
        if (line[i] == token) {
            words.push_back(word);
            word = "";
        }
        else word += line[i];
    }
    return words;
}

#endif // LINEOPS
