#include <iostream>

const int INF = 7000001;

int s(int **memo, int c, int d, int **w, int h)
{
    if (c == d)
    {
        if (h == 0)
            return 0;
        return INF;
    }
    if (h < 0 || h > d - c || h > 9)
    {
        return INF;
    }
    if (memo[h][c] == -1)
    {
        memo[h][c] = 60 - w[h][c] + s(memo, c + 1, d, w, h + 1);
        int t = 30 - w[h][c] + s(memo, c + 1, d, w, h);
        memo[h][c] = std::min(memo[h][c], t);
        t = 20 - w[h][c] + s(memo, c + 1, d, w, h - 1);
        memo[h][c] = std::min(memo[h][c], t);
    }

    return memo[h][c];
}

int main()
{
    int n;
    std::cin >> n;

    int **w = new int *[10];
    int **memo = new int *[10];
    for (int z = 0; z < n; z++)
    {
        int d;
        std::cin >> d;
        d /= 100;

        for (int h = 9; h >= 0; h--)
        {
            w[h] = new int[d];
            memo[h] = new int[d];
            for (int i = 0; i < d; i++)
            {
                std::cin >> w[h][i];
                memo[h][i] = -1;
            }
        }
        std::cout << s(memo, 0, d, w, 0) << "\n\n";

        for (int i = 0; i < 10; i++)
        {
            delete[] w[i];
            delete[] memo[i];
        }
    }
    delete[] w;
    delete[] memo;
}