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
	//variables 

	//methods
	public static void preOrderHelper( TreeNode root, ArrayList<Integer> ret ){
		ret.add(root.val);

		if( root.left != null ){
			preOrderHelper(root.left, ret);
		}

		if( root.right != null ){
			preOrderHelper(root.right, ret);
		}

		return ; 
	}

	public ArrayList<Integer> preorderTraversal(TreeNode root) {
		ArrayList<Integer> ret = new ArrayList<Integer>();
		if( root == null ){
			return ret;
		}

		preOrderHelper( root, ret );

		return ret; 
	}
}
