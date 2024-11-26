#include <iostream>

using namespace std;

unsigned int count_two(const unsigned long long x)
{
    if (x == 0)
        return 0;

    return ((x % 10) == 2) + count_two(x / 10);
}

int main()
{
    unsigned long long L, R;
    cin >> L >> R;

    unsigned long long count = 0;
    while (L <= R)
        count += count_two(L++);

    cout << count << endl;
}