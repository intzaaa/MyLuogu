#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

inline string subtract(string &x, string &y)
{
    stringstream stream;

    for (int i = 0; i < x.length(); i++)
    {
        const int _a = (i < x.length() ? x[i] : '0') - '0',
                  _b = (i < y.length() ? y[i] : '0') - '0';

        const auto number = _a - _b;
        const bool underflow = number < 0;
        if (underflow)
        {
            for (int j = i + 1; j < x.length(); j++)
            {
                if (x[j] == '0')
                    x[j] = '9';
                else
                {
                    x[j]--;
                    break;
                }
            }
        }

        stream << (underflow ? 10 + number : number);
    }

    auto result = stream.str();
    while (result.length() > 1 && result.back() == '0')
        result.pop_back();
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string x, y;
    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    bool is_a_less_than_b = x.length() < y.length();
    if (!is_a_less_than_b && x.length() == y.length())
    {
        for (int i = x.length() - 1; i >= 0; i--)
        {
            if (x[i] < y[i])
            {
                is_a_less_than_b = true;
                break;
            }
        }
    }

    if (is_a_less_than_b)
    {
        swap(x, y);
        cout << '-';
    }

    cout << subtract(x, y) << endl;
}