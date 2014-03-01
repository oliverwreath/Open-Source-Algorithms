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
	int ret = 0;
	int pathSum = 0;
	public void helper(TreeNode root){
		pathSum *= 10;
		pathSum += root.val;
		if( root.left == null && root.right == null ){
			ret += pathSum; 
		}else{
			if( root.left != null ){
				helper( root.left );
			}
			if( root.right != null ){
				helper( root.right );
			}
		}
		pathSum /= 10; 
	}

	public int sumNumbers(TreeNode root) {
		if( root == null ){
			return 0;
		}
		ret = 0;
		pathSum = 0;

		helper(root);

		return ret; 
	}
}

