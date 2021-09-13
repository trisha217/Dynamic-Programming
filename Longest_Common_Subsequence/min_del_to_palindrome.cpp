#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(string x, string y, int m, int n)
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
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string x;
    string y="";
    int n, m;
    cout << "Enter the string \n";
    cin >> x;
    m = x.length();
    for(int i=(m-1);i>=0;i--){
        y.push_back(x[i]);
    }
    n = m;
    int res = lcs(x, y, m, n);
    cout<<(n-res)<<endl;
    return 0;
}