#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int> &nums, int start, int end)
{
    vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
    if (start == 0)
        dp[0][1] = nums[0];
    if (start == 1)
        dp[1][1] = nums[1];
    for (int i = start + 1; i <= end; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = nums[i] + (i - 2 >= 0 ? max(dp[i - 2][0], dp[i - 2][1]) : 0);
    }
    return max(dp[end][0], dp[end][1]);
}
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    return max(getAns(nums, 0, nums.size() - 2), getAns(nums, 1, nums.size() - 1));
}

int rob_optimize(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return n ? nums[0] : 0;
    return max(robber_optimize(nums, 0, n - 2), robber_optimize(nums, 1, n - 1));
}
int robber_optimize(vector<int> &nums, int l, int r)
{
    int pre = 0, cur = 0;
    for (int i = l; i <= r; i++)
    {
        int temp = max(pre + nums[i], cur);
        pre = cur;
        cur = temp;
    }
    return cur;
}

int main()
{
    return 0;
}
