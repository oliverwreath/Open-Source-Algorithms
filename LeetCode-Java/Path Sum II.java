

public class Solution {
	int target;
	ArrayList<ArrayList<Integer>> ret;
	ArrayList<Integer> path;
	int sum;
	public void helper( TreeNode root ){
		path.add(root.val);
		sum += root.val;
		if( root.left == null && root.right == null ){
			if( sum == target ){
				ret.add( (ArrayList<Integer>)path.clone() );
			}
		}else{
			if( root.left != null ){
				helper( root.left );
			}
			if( root.right != null ){
				helper( root.right );
			}
		}
		path.remove(path.size()-1); 
		sum -= root.val; 
	}

	public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int targetSum) {
		target = targetSum;
		ret = new ArrayList<ArrayList<Integer>>();
		path = new ArrayList<Integer>();
		sum = 0;
		if( root == null ){
			return ret; 
		}
		
		helper( root ); 

		return ret; 
	}
}

