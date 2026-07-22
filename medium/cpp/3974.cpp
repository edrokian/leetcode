// https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/description/

class Solution
{
public:
    long long maxSum(std::vector<int>& nums, int k, int mul)
    {
        std::ranges::sort(nums, std::greater<int>{});
        long long res = 0LL;

        for (int i = 0; i < k; i++)
        {
            if (mul > 0)
            {
                res += 1LL * nums[i] * mul--;
            }
            else
            {
                res += nums[i];
            }
        }

        return res;
    }
};