#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void Knapsack()
{
    int n;
    cout << "Enter the number of items in Knapsack:" << endl;
    cin >> n;
    int wt[n];
    int val[n];
    cout << "Enter the weight array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << "Enter the value array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int cap;
    cout << "Enter the maximum capacity of Knapsack" << endl;
    cin >> cap;
    int dp[n + 1][cap + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << "MAX PROFIT:" << dp[n][cap] << endl;
}

int main()
{
    Knapsack();
    return 0;
}