// https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/description/

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn count_dominant_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 0;
        Self::dfs(&root, &mut ans);
        ans        
    }

    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, ans: &mut i32) -> i32 {
        match node {
            None => i32::MIN,
            Some(rc) => {
                let n = rc.borrow();

                let left_max  = Self::dfs(&n.left,  ans);
                let right_max = Self::dfs(&n.right, ans);

                let subtree_max = left_max.max(right_max).max(n.val);

                if subtree_max == n.val {
                    *ans += 1;
                }

                subtree_max
            }
        }
    }
}