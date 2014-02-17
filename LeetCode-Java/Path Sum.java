/**
 * Definition for binary tree
 * public class TreeNode {
 *	 int val;
 *	 TreeNode left;
 *	 TreeNode right;
 *	 TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
	public boolean helper( TreeNode root, int target, int sum ){
		sum += root.val;
		if( root.left != null || root.right != null ){
			if( root.left != null ){
				if( helper( root.left, target, sum ) ){
					return true;
				}
			}
			if( root.right != null ){
				if( helper( root.right, target, sum ) ){
					return true;
				}
			}
		}else{
			if( sum == target ){
				return true;
			}
		}

		return false;
	}

	public boolean hasPathSum(TreeNode root, int sum) {
		if( root == null ){
			if( sum == 0 ){
				return false;
			}else{
				return false;
			}
		}
		int acc = 0;
		boolean res = helper( root, sum, acc );
		return res; 
	}
}



