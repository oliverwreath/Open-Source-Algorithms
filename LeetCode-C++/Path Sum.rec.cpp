#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

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
    int target;

    bool inOrderTraversal( TreeNode* root, int tmpSum ){
        if( root == NULL ){
            return false;
        }

        tmpSum += root->val;
        if( root->left == NULL && root->right == NULL ){
            if( tmpSum == target ){
                return true;
            }
        }

        if( root->left != NULL ){
            if( inOrderTraversal( root->left, tmpSum ) ){
                return true;
            }
        }

        if( root->right != NULL ){
            if( inOrderTraversal( root->right, tmpSum ) ){
                return true;
            }
        }

        return false;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if( root == NULL ){
            return false;
        }
        int tmpSum = 0;
        target = sum;
        return ( inOrderTraversal( root, tmpSum ) );
    }
};
