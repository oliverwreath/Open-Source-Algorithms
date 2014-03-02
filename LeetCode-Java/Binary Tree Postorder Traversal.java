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
	public static void postOrderHelper( TreeNode root, ArrayList<Integer> ret ){
		if( root.left != null ){
			postOrderHelper(root.left, ret);
		}

		if( root.right != null ){
			postOrderHelper(root.right, ret);
		}
		
		ret.add(root.val);

		return ; 
	}

	public ArrayList<Integer> postorderTraversal(TreeNode root) {
		ArrayList<Integer> ret = new ArrayList<Integer>();
		if( root == null ){
			return ret;
		}

		postOrderHelper( root, ret );

		return ret; 
	}
}
