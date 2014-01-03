#define F(i, a, b) for(int i = a; i <= b; i++)
#define F3(i, a, b) for(int i = a; i <= b; i+=3)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MAX3( a, b, c ) a>b?(a>c?a:c):(b>c?b:c)
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <iterator>

/**
 * Definition for binary tree
 * struct TreeNode {
 *	 int val;
 *	 TreeNode *left;
 *	 TreeNode *right;
 *	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//typedef
	typedef TreeNode* iterator;

	//methods
	int pathSumRec( iterator root, int& max ){
		int rootVal = root->val;
		if( root->left == NULL ){
			if( root->right == NULL ){
				//leaf
				max = MAX2( max, rootVal );
				return rootVal;
			}
			else{
				//no left
				int right = pathSumRec( root->right, max );
				if( right > 0 ){ rootVal += right; }
				int localMax = MAX2( right, rootVal );
				max = MAX2( max, localMax );	
				return rootVal;
			}
		}else if( root->right == NULL ){
			//no right
			int left = pathSumRec( root->left, max );
			if( left > 0 ){ rootVal += left; }
			int localMax = MAX2( left, rootVal );
			max = MAX2( max, localMax );		
			return rootVal;
		}else{
			//full
			int left = pathSumRec( root->left, max );
			int right = pathSumRec( root->right, max );
			int sum = rootVal;
			if( left > 0 ){ sum += left; }
			if( right > 0 ){ sum += right; }
			if( left > right ){ 
				if( left > 0 ){
					rootVal += left; 
				}
			}else{
				if( right > 0 ){
					rootVal += right;
				}
			}
			int localMax = MAX3( left, right, sum );
			max = MAX2( max, localMax );
			return rootVal;
		}
	}

	int maxPathSum(TreeNode *root) {
		if( root == NULL ){
			return 0;
		}

		int max = INT_MIN;
		pathSumRec( root, max );
		return max;
	}
};
