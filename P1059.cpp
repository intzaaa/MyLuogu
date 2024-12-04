#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int n;
    cin >> n;
    vector<int> numbers = {n};

    for (int i = 1; i < N; i++)
    {
        int n;
        cin >> n;

        for (int j = 0; j <= numbers.size(); j++)
        {
            if (numbers[j] > n || j == numbers.size())
            {
                numbers.insert(numbers.begin() + j, n);
                break;
            }
            else if (numbers[j] == n)
            {
                break;
            }
        }
    }

    cout << numbers.size() << endl;
    for (const auto &n : numbers)
    {
        cout << n << ' ';
    }
}