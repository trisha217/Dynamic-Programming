#include <bits/stdc++.h>
using namespace std;

int subset_sum(int arr[], int sum, int n)
{

    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int diff = INT_MAX;
    vector<int> v;
    for (int j = 0; j <= sum / 2; j++)
    {
        if (dp[n][j] == true) //for last row
        {
            v.push_back(j);
        }
    }
    /*
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    */
    for (int i = 0; i < v.size(); i++)
    {
        diff = std::min(diff, sum - 2 * v[i]);
    }
    return diff;
}

int main()
{
    int n;
    cout << "Enter the number of items:" << endl;
    cin >> n;
    int arr[n];
    int sum = 0;
    cout << "Enter the value array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int ans = subset_sum(arr, sum, n);
    cout << "MINIMUM SUBSET SUM DIFFERENCE IS " << ans << endl;
    return 0;
}