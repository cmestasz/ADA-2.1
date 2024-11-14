#include <iostream>
#include <sstream>

int s(int **memo, int **m, int i, int j)
{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0 || m[i][j] == 1)
        return 0;

    if (memo[i][j] == -1)
        memo[i][j] = s(memo, m, i, j - 1) + s(memo, m, i - 1, j);

    return memo[i][j];
}

int split(std::string s, int a[])
{
    int idx = 0;
    std::stringstream ss(s);
    std::string t;

    while (std::getline(ss, t, ' '))
    {
        a[idx] = std::stoi(t);
        idx++;
    }
    return idx;
}

int main()
{
    int n, ew, ns;
    std::string l;
    std::cin >> n;
    for (int c = 0; c < n; c++)
    {
        std::cin >> ew >> ns;
        std::getline(std::cin, l);
        int **m = new int *[ew];
        int **memo = new int *[ew];
        int t[ns];
        for (int r = 0; r < ew; r++)
        {
            m[r] = new int[ns];
            memo[r] = new int[ns];
            for (int i = 0; i < ns; i++)
            {
                m[r][i] = 0;
                memo[r][i] = -1;
            }

            std::getline(std::cin, l);
            int z = split(l, t);
            for (int i = 1; i < z; i++)
                m[r][t[i] - 1] = 1;
        }
        std::cout << s(memo, m, ew - 1, ns - 1) << "\n";
        if (c < n - 1)
            std::cout << "\n";

        for (int i = 0; i < ew; i++)
        {
            delete[] m[i];
            delete[] memo[i];
        }
        delete[] m;
        delete[] memo;
    }
}