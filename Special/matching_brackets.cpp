#include <bits/stdc++.h>

using namespace std;

// the idea here is to decide whether the brackets are correctly matched
// for example, ({[]}) is correctly matched, but (({[]}) isn't,
// here we use parentheses, curly and square brackets.

// input: a string of length `n` containing the brackets. 1 <= n <= 100
// user should output "1" if it's correctly matching or "0" otherwise.

// { [ ( ( ) ) ] }

// can i output a corrected string ?

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
    queue<pair<int, int>> positions;

    int index = -1;
    for (int i = 0; i < example.size(); i++)
    {
        char ch = example[i];
        if (bracket_map.count(ch) > 0) // opening
            pile.push(ch);
        else if (bracket_map[pile.top()] == ch) // closing and matches
        {
            pile.pop();
        }
        else // closing and doesn't match
        {
            index = i;
            positions.push(make_pair(ch, i)); // save character and position for later correction
        }
    }

    if (positions.size() == 0 && pile.size() == 0) // string is ok, output -1 and quit.
    {
        cout << -1;
        return 0;
    }

    // characters left on stack: opens but never closes ->
    // two options:
    // - append immediately after
    // - append at the end
    // characters on position[]: closes without opening
    // let's just prepend the opening bracket.

    int new_size = example.size() + positions.size() + pile.size();
    // input: {{)]
    // output: {{()[]}}
    string corrected(new_size, ' ');

    int popped = 0;
    for (int i = 0; i < (example.size() + positions.size()); i++)
    {
        if ((positions.front().second) == i) // we're in the oposition immediately before the closing char
        {
            char closing = positions.front().first;
            char open;
            for (auto const &[opening, val] : bracket_map) // find corresponding key (can i use two-way mapping?)
            {
                if (val == closing)
                {
                    open = opening;
                    break;
                }
            }
            corrected[i] = open;
            popped++;
            positions.pop();
        }
        else
        {
            corrected[i] = example[i - popped];
        }
    }

    return 0;
}