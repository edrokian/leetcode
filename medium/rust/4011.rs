// https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/description/

impl Solution {
    pub fn count_ratio_subarrays(nums: Vec<i32>, a: i32, b: i32) -> i32 {
        let n = nums.len();
        let mut res = 0;

        for left in 0..n {
            let mut x = 0;
            let mut y = 0;

            for right in left..n {
                if nums[right] % 2 == 0 {
                    x += 1;
                } else {
                    y += 1;
                }

                if y > 0 && x * b <= a * y {
                    res += 1;
                }
            }
        }

        res
    }
}