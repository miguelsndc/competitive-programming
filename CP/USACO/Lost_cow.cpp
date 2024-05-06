#include <bits/stdc++.h>

using namespace std;

void setIO(string name)
{
    if (name.size() > 0)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("lostcow");
    int x, y;
    cin >> x >> y;

    if (x == y)
    {
        cout << 0;
        return 0;
    }

    int factor = 1;
    int distance_traveled = 0;
    int pos = x, old_pos = x;
    do
    {
        old_pos = pos;
        pos = (x + factor);
        distance_traveled += abs(pos - old_pos);
        factor *= -2;
    } while (!((y >= x && y <= pos) || (y <= x && y >= pos)));
    distance_traveled -= abs(y - pos);
    cout << distance_traveled;
    return 0;
}