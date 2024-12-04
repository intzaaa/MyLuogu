#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    vector<int> prefix_sums(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix_sums[i] = (prefix_sums[i - 1] + numbers[i - 1]) % 7;

    unordered_map<int, int> mod_position;
    int max_length = 0;

    for (int i = 0; i <= n; i++)
        if (mod_position.find(prefix_sums[i]) == mod_position.end())
            mod_position[prefix_sums[i]] = i;
        else
        {
            int length = i - mod_position[prefix_sums[i]];
            if (length > max_length)
                max_length = length;
        }

    cout << max_length << endl;

    return 0;
}