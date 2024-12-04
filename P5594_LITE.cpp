#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    // 动态分配二维布尔数组
    bool **days = new bool *[k];
    for (int i = 0; i < k; i++)
    {
        days[i] = new bool[m];
        // 初始化为 false
        for (int j = 0; j < m; j++)
        {
            days[i][j] = false;
        }
    }

    for (int p = 0; p < n; p++)
    {
        for (int t = 0; t < m; t++)
        {
            int d;
            cin >> d;
            days[d - 1][t] = true;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (days[i][j])
                count++;
        }
        cout << count << ' ';
    }
    cout << endl;

    // 释放动态分配的内存
    for (int i = 0; i < k; i++)
    {
        delete[] days[i];
    }
    delete[] days;

    return 0;
}