// https://leetcode.com/problems/maximum-valid-pair-sum/description/

use std::cmp;

impl Solution {
    pub fn max_valid_pair_sum(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut mv = 0;
        let mut res = 0;

        let k_usize = k as usize;

        for i in k_usize..=n-1 {
            mv = cmp::max(mv, nums[i - k_usize]);
            res = cmp::max(res, nums[i] + mv);
        }

        res
    }
}