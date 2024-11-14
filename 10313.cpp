#include <iostream>
#include <sstream>

long long ss(long long ***memo, int c, int t, int v)
{
    if (c == 0)
    {
        if (t == 0)
            return 1;
        return 0;
    }
    if (t < 0)
        return 0;

    if (memo[c][t][v] == -1)
    {
        memo[c][t][v] = 0;
        for (int i = v; i <= t / c; i++)
            memo[c][t][v] += ss(memo, c - 1, t - i, i);
    }

    return memo[c][t][v];
}

long long s(long long ***memo, int min, int max, int v)
{
    long long a = 0;
    for (int i = min; i <= max; i++)
    {
        if (i > 300)
            break;
        if (i == 0 && v == 0)
            a += 1;
        else
            a += ss(memo, i, v, 1);
    }
    return a;
}

int split(std::string s, int a[3])
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
    long long ***memo = new long long **[301];
    for (int i = 0; i <= 300; i++)
    {
        memo[i] = new long long *[301];
        for (int j = 0; j <= 300; j++)
        {
            memo[i][j] = new long long[301];
            for (int k = 0; k <= 300; k++)
                memo[i][j][k] = -1;
        }
    }

    std::string line;
    std::getline(std::cin, line);
    int a[3];
    while (!line.empty())
    {
        int c = split(line, a);

        switch (c)
        {
        case 1:
            std::cout << s(memo, 0, a[0], a[0]) << std::endl;
            break;
        case 2:
            std::cout << s(memo, 0, a[1], a[0]) << std::endl;
            break;
        case 3:
            std::cout << s(memo, a[1], a[2], a[0]) << std::endl;
            break;
        }

        std::getline(std::cin, line);
    }

    for (int i = 0; i <= 300; i++)
    {
        for (int j = 0; j <= 300; j++)
            delete[] memo[i][j];
        delete[] memo[i];
    }
    delete[] memo;
}
