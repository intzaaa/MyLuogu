#include <iostream>
#include <vector>

using namespace std;

#define _ vector<bool>
#define __ vector<_>

bool checkH(__ &matrix)
{
    for (const auto &row : matrix)
    {
        bool visited = false;
        for (const auto &n : row)
        {
            if (n == true)
            {
                visited = true;
                break;
            }
        }

        if (!visited)
        {
            return false;
        }
    }

    return true;
}

bool checkV(__ &matrix)
{
    for (int i = 0; i < matrix[0].size(); i++)
    {
        bool visited = false;
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[j][i] == true)
            {
                visited = true;
                break;
            }
        }

        if (!visited)
        {
            return false;
        }
    }

    return true;
}

bool checkO(__ &matrix)
{
    for (int i = 1; i < matrix[0].size(); i++)
    {
        bool visited = false;
        for (int j = 0; j < matrix.size() - i; j++)
        {
            if (matrix[j][i + j] == true)
            {
                visited = true;
                break;
            }
        }

        if (!visited)
        {
            return false;
        }
    }

    for (int i = -; i < matrix[0].size(); i++)
    {
        bool visited = false;
        for (int j = 0; j < matrix.size() - i; j++)
        {
            if (matrix[j][i + j] == true)
            {
                visited = true;
                break;
            }
        }

        if (!visited)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int N;
    cin >> N;
}