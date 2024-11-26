#include <iostream>
#include <vector>

using namespace std;

int win(const unsigned long long a, const unsigned long long b, const unsigned int max)
{
    if (a < b)
        return -win(b, a, max);

    if (a < max || a - b < 2)
        return 0;

    return a - b;
}

void print(const vector<char> &scores, const unsigned int max)
{
    long long i = 0, a = 0, b = 0;

    for (const auto &s : scores)
    {
        if (s == 'W')
            a++;
        else
            b++;

        if (win(a, b, max) != 0)
        {
            cout << a << ':' << b << endl;

            a = 0;
            b = 0;
        }
    }

    cout << a << ':' << b << endl;
}

int main()
{
    vector<char> scores;
    while (true)
    {
        char c;
        cin >> c;

        if (c == 'E')
            break;
        else
            scores.push_back(c);
    }

    print(scores, 11);

    cout << endl;

    print(scores, 21);

    return 0;
}