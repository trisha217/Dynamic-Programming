#include <bits/stdc++.h>
using namespace std;

bool spm(string x, string y, int m, int n)
{
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
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    if(dp[m][n] == m )
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string x, y;
    int n, m;
    cout << "Enter both the strings \n";
    cin >> x >> y;
    m = x.length();
    n = y.length();
    cout<<spm(x, y, m, n)<<endl;
    return 0;
}