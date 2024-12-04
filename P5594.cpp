#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int>> days(k, set<int>());

    for (int p = 0; p < n; p++)
    {
        for (int t = 0; t < m; t++)
        {
            int d;
            cin >> d;

            days[d - 1].insert(t);
        }
    }

    for (const auto &d : days)
    {
        cout << d.size() << ' ';
    }

    cout << endl;
}
