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
#include <stack>

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
	int isBalancedRec( iterator root, bool& ret ){
		if( ret ){
			if( root->left == NULL && root->right == NULL ){
				return 0;
			}

			int left = 0;
			int right = 0;
			if( root->left != NULL ){
				left = isBalancedRec(root->left, ret) + 1;
			}
			if( root->right != NULL ){
				right = isBalancedRec(root->right, ret) + 1;
			}
			
			if( left - right > 1 || (left - right < -1) ){
				ret = false;
				return 0;
			}
			else{
				return MAX2( left, right );
			}
		}
	}

	bool isBalanced(TreeNode *root) {
		if( root == NULL ){
			return true;
		}

		bool ret = true;
		isBalancedRec( root, ret );
		return ret;
	}
};
