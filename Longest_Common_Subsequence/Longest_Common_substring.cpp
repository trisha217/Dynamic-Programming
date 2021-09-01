#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(string x, string y, int m, int n)
{
    int result = 0;
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

int main()
{
    string x, y;
    int n, m;
    cout << "Enter both the strings";
    cin >> x >> y;
    m = x.length();
    n = y.length();
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