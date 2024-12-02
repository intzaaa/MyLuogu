#include <iostream>
#include <vector>

using namespace std;

string solve(const vector<pair<bool, string>> &people, vector<pair<bool, unsigned long long>> &commands, const unsigned long long step, const unsigned long long index)
{
    if (step == commands.size())
        return people[index].second;

    const auto next_index = ((people[index].first == commands[step].first ? index - commands[step].second : index + commands[step].second) + people.size()) % people.size();
    const auto next_step = step + 1;

    return solve(people, commands, next_step, next_index);
}

int main()
{
    int n, m;
    cin >> n >> m;

    // 0 <- | 1 ->
    vector<pair<bool, string>> people(n);
    vector<pair<bool, unsigned long long>> commands(m);

    for (unsigned long long i = 0; i < n; i++)
        cin >> people[i].first >> people[i].second;

    for (unsigned long long i = 0; i < m; i++)
        cin >> commands[i].first >> commands[i].second;

    cout << solve(people, commands, 0, 0) << endl;

    return 0;
}
