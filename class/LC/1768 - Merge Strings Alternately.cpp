#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    string c = "";

    string min = word1.size() < word2.size() ? word1 : word2;
    string max = word1.size() > word2.size() ? word1 : word2;
    for (int i = 0; i < min.size(); i++)
    {
        c.push_back(word1[i]);
        c.push_back(word2[i]);
    }

    c += max.substr(min.size(), max.size() - min.size());
    return c;
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    cout << mergeAlternately(s, t) << '\n';
    return 0;
}