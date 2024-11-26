#include <iostream>
#include <string>
using namespace std;

int compare(char x, char y)
{
    if (x == y)
        return 0;

    if (x < y)
        return -compare(y, x);

    if (
        (x == '1' && y == '0') ||
        (x == '2' && y == '1') ||
        (x == '3' && y == '2') ||
        (x == '4' && (y == '0' || y == '1')))
        return 1;
    else
        return -1;
}

char access(string str, unsigned int idx)
{
    return str[idx % str.length()];
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    string a_cycle, b_cycle;
    for (int i = 0; i < a + b; i++)
    {
        char c;
        cin >> c;
        if (i < a)
            a_cycle.push_back(c);
        else
            b_cycle.push_back(c);
    }

    unsigned int a_points = 0, b_points = 0;
    for (int i = 0; i < n; i++)
    {
        const int result = compare(access(a_cycle, i), access(b_cycle, i));

        if (result == 0)
            continue;
        else if (result == 1)
            a_points++;
        else
            b_points++;
    }

    cout << a_points << ' ' << b_points << endl;
}