#include <iostream>
#include <vector>

using namespace std;

inline bool is_first_row(const int y)
{
    return y == 0;
}

inline bool is_last_col(const int x, const int w)
{
    return x == (w - 1);
}

int main()
{
    int N;
    cin >> N;
    const auto M = N / 2 + 1;

    vector<vector<unsigned int>> matrix(N, vector<unsigned int>(N, 0));

    int lx = 0, ly = M - 1;
    matrix[lx][ly] = 1;

    for (unsigned int K = 2; K <= N * N; K++)
        if (is_first_row(lx) && is_last_col(ly, N))
            matrix[++lx][ly] = K;
        else if (is_first_row(lx))
            matrix[(lx = N - 1)][++ly] = K;
        else if (is_last_col(ly, N))
            matrix[--lx][ly = 0] = K;
        else if (matrix[lx - 1][ly + 1] == 0)
            matrix[--lx][++ly] = K;
        else
            matrix[++lx][ly] = K;

    for (const auto &r : matrix)
    {
        for (const auto &n : r)
            cout << n << ' ';

        cout << endl;
    }
}