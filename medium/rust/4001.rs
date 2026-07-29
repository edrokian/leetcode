// https://leetcode.com/problems/aggregate-two-time-series/description/

impl Solution {
    pub fn aggregate_time_series(series1: Vec<Vec<i32>>, series2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = series1.len();
        let m = series2.len();

        let mut res: Vec<Vec<i32>> = Vec::with_capacity(n + m);

        let mut i = 0;
        let mut j = 0;

        while i < n && j < m {
            if series1[i][0] < series2[j][0] {
                res.push(vec![series1[i][0], series1[i][1] + series2[j][1]]);
                i += 1;
            } else if series2[j][0] < series1[i][0] {
                res.push(vec![series2[j][0], series1[i][1] + series2[j][1]]);
                j += 1;
            } else {
                res.push(vec![series1[i][0], series1[i][1] + series2[j][1]]);
                i += 1;
                j += 1;
            }
        }

        while i < n {
            res.push(vec![series1[i][0], series1[i][1]]);
            i += 1;
        }

        while j < m {
            res.push(vec![series2[j][0], series2[j][1]]);
            j += 1;
        }

        res
    }
}