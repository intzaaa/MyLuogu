#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    stringstream ss;
    bool overflow = false;
    for (int i = 0; i < max(a.length(), b.length()) + overflow; i++)
    {
        const int _a = (i < a.length() ? a[i] : '0') - '0',
                  _b = (i < b.length() ? b[i] : '0') - '0';

        const auto number = _a + _b + overflow;
        overflow = number >= 10;

        ss << (number % 10);
    }

    auto str = ss.str();
    reverse(str.begin(), str.end());

    cout << str << endl;
}