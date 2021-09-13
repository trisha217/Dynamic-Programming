#include <bits/stdc++.h>
using namespace std;


int max(int a, int b)
{
    return (a > b) ? a : b;
}

void lcs(string x, string y, int m, int n)
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
    string s = "";
    int i=m;
    int j=n;
    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(s.begin(), s.end());
    cout<<s<<endl;
}

int main()
{
    string x, y;
    int n, m;
    cout << "Enter both the strings \n";
    cin >> x >> y;
    cout<<endl;
    m = x.length();
    n = y.length();
    lcs(x, y, m, n);
    return 0;
}