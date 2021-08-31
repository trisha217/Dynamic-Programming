#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of items:" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the value array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cout << "Enter the maximum sum required" << endl;
    cin >> sum;
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout<<"MUMBER OF SUBSETS ARE "<<dp[n][sum];
    return 0;
}