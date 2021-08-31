#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of coins availble:" << endl;
    cin >> n;
    int coin[n];
    cout << "Enter the coin array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    int sum;
    cout << "Enter the maximum sum required" << endl;
    cin >> sum;
    int dp[n + 1][sum + 1];
    //initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            else if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            else if (j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < sum + 1; j++)
    {
        int i = 1;
        if (j % coin[0] == 0)
        {
            dp[i][j] = j / coin[0];
        }
        else
        {
            dp[i][j] = INT_MAX - 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coin[i - 1]] + 1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << "Minimum number of coins required are: " << dp[n][sum]<<endl;
    return 0;
}