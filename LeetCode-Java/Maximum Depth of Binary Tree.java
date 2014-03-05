



public class Solution {
	//variables
	int minDepth; 
	int maxDepth; 

	//methods
	public void helper( TreeNode root, int parentDepth ){
		parentDepth += 1; 
		if( root.left == null && root.right == null ){
			if( parentDepth < minDepth ){
				minDepth = parentDepth; 
			}
			if( parentDepth > maxDepth ){
				maxDepth = parentDepth;
			}

		}else{
			if( root.left != null ){
				helper( root.left, parentDepth );
			}
			if( root.right != null ){
				helper( root.right, parentDepth );
			}
		}
		return ; 
	}

	public int maxDepth(TreeNode root) {
		minDepth = Integer.MAX_VALUE; 
		if( root == null ){
			return 0;
		}

		helper( root, 0 );
		return maxDepth; 
	}
}



