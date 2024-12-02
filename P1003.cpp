#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<pair<int, int>, pair<int, int>>> carpets(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        carpets[i].first.first = a;
        carpets[i].first.second = b;
        carpets[i].second.first = a + c;
        carpets[i].second.second = b + d;
    }

    pair<int, int> location;
    cin >> location.first;
    cin >> location.second;

    for (int i = n - 1; i >= 0; i--)
    {
        if (location.first >= carpets[i].first.first &&
            location.first <= carpets[i].second.first &&
            location.second >= carpets[i].first.second &&
            location.second <= carpets[i].second.second)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
