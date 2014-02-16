#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper( TreeNode* node, int tmp, int& sum ){
        tmp *= 10;
        tmp += node->val;

        if( node->left == NULL && node->right == NULL ){
            sum += tmp;
            return ;
        }

        if( node->left != NULL ){
            helper( node->left, tmp, sum );
        }

        if( node->right != NULL ){
            helper( node->right, tmp, sum );
        }

        return ;
    }

    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if( root == NULL ){
            return sum;
        }

        helper( root, 0, sum );
        return sum;
    }
};
