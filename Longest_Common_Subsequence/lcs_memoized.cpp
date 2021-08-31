#include <bits/stdc++.h>
using namespace std;

int dp[5][5];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (x[m - 1] == y[n - 1])
    {
        return dp[m][n] = 1 + lcs(x, y, m - 1, n - 1);
    }
    else
    {
        return dp[m][n] = max(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n));
    }
}

int main()
{
    string x, y;
    int n, m;
    cout << "Enter both the strings";
    cin >> x >> y;
    m = x.length();
    n = y.length();
    memset(dp, -1, sizeof(dp));

    int res = lcs(x, y, m, n);
    /*for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << dp[i][j];
        }
        cout << endl;
    }*/
    cout << res << endl;
    return 0;
}