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

	//variables
	
	//methods
	iterator flattenRec( iterator root ){
		if( root->left == NULL && root->right == NULL ){
			return root;
		}

		stack<iterator> st;
		while( root->left != NULL ){
			if( root->right != NULL ){
				st.push( root->right );
			}

			root->right = root->left;
			root->left = NULL;
			root = root->right;
		}
		if( root->right != NULL ){
			st.push( root->right );
		}

		while( !st.empty() ){
			root->right = st.top();
			root = flattenRec( root->right );
			st.pop();
		}

		return root;
	}

	void flatten(TreeNode *root) {
		if( root == NULL ){
			return;
		}

		flattenRec( root );
		return ;
	}
};
