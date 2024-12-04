#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

inline string subtract(string &x, string &y)
{
    bool is_a_less_than_b = x.length() < y.length();
    if (!is_a_less_than_b && x.length() == y.length())
        for (int i = x.length() - 1; i >= 0; i--)
            if (x[i] < y[i])
            {
                is_a_less_than_b = true;
                break;
            }

    if (is_a_less_than_b)
        swap(x, y);

    stringstream stream;

    int zero_buffer = 0;
    for (int i = 0; i < x.length(); i++)
    {
        const int _a = (i < x.length() ? x[i] : '0') - '0',
                  _b = (i < y.length() ? y[i] : '0') - '0';

        const auto number = _a - _b;

        if (number == 0)
        {
            zero_buffer++;

            continue;
        }

        while (zero_buffer-- > 0)
            stream << 0;

        zero_buffer = 0;

        const bool underflow = number < 0;

        if (underflow)
            for (int j = i + 1; j < x.length(); j++)
                if (x[j] == '0')
                    x[j] = '9';
                else
                {
                    x[j]--;
                    break;
                }

        stream << (underflow ? 10 + number : number);
    }

    if (is_a_less_than_b)
        stream << '-';

    const auto result = stream.str();

    return result.length() == 0 ? "0" : result;
}

int main()
{
    string x, y;
    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    auto result = subtract(x, y);
    reverse(result.begin(), result.end());

    cout << result << endl;
}
