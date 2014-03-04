/**
 * Definition for binary tree
 * public class TreeNode {
 *	 int val;
 *	 TreeNode left;
 *	 TreeNode right;
 *	 TreeNode(int x) { val = x; }
 * }
 */

import java.lang.Math; 

public class Solution {
	boolean ret;
	public Integer helper( TreeNode root, int parentDepth ){
		parentDepth++;
		if( root.left == null && root.right == null ){
			return parentDepth; 
		}else{
			int leftDepth = parentDepth;
			int rightDepth = parentDepth;
			if( root.left != null ){
				leftDepth = helper(root.left, parentDepth);
			} 
			if( root.right != null ){
				rightDepth = helper(root.right, parentDepth); 
			}
			if( Math.abs(rightDepth - leftDepth) > 1 ){
				ret = false; 
				return parentDepth;
			}
			return Math.max(leftDepth, rightDepth); 
		}


	}

	public boolean isBalanced(TreeNode root){
		ret = true; 
		if( root == null ){
			return true; 
		}

		helper( root, -1 );
		return ret; 
	}
}



