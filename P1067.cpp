// P1067

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool first = true;
    for (int i = n; i >= 0; i--)
    {
        int number;
        cin >> number;
        if (number == 0)
            continue;

        const string middle = to_string(abs(number));
        const string suffix = i == 1 ? "x" : "x^" + to_string(i);

        if (middle + suffix != "")
        {
            const string prefix = number < 0 ? "-" : "+";

            if (!(first && number > 0))
                cout << prefix;

            if (middle != "1" || i == 0)
                cout << middle;

            if (i != 0)
                cout << suffix;

            first = false;
        }
    }

    cout << endl;
}