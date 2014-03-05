public class Solution {
	//variables
	int minDepth; 
	int maxDepth; 

	boolean isSame; 

	public void isSameTreeHelper( TreeNode p, TreeNode q ){
		if( p == null ){
			if( q != null ){
				isSame = false; 
				return ; 
			}
		}else{
			if( q == null || p.val != q.val ){
				isSame = false; 
				return ; 
			}

			//sbutrees
			isSameTreeHelper( p.left, q.left );
			isSameTreeHelper( p.right, q.right );
		}
		return ; 
	}

	public boolean isSameTree( TreeNode p, TreeNode q ) {
		isSame = true; 
		isSameTreeHelper(p, q);

		return isSame;
	}
}
