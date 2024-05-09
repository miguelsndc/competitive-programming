#include <bits/stdc++.h>

using namespace std;

// the idea here is to decide whether the brackets are correctly matched
// for example, ({[]}) is correct matching, but (({[]}) isn't, here we use parentheses,
// curly and square brackets.

// input: a string of length `n` containing the brackets. 1 <= n <= 100
// user should output "1" if it's correctly matching or "0" otherwise.

// { [ ( ( ) ) ] }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string example;
    cin >> example;
    map<char, char> bracket_map = {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'},
    };
    stack<char> pile;

    int matches = 1;
    for (auto ch : example)
    {
        if (bracket_map.count(ch) > 0) // opening
            pile.push(ch);
        else if (bracket_map[pile.top()] == ch) // closing and matches
        {
            pile.pop();
        }
        else // closing and doesn't match
        {
            matches = 0;
            break;
        }
    }

    cout << matches;

    return 0;
}