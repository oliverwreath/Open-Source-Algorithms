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

    void inOrderTraversal( TreeNode* root, int sum, vector<int> path, vector<vector<int>>& ret ){
        sum += root->val;
        path.push_back( root->val );

        if( root->left == NULL & root->right == NULL ){
            if( sum == target ){
                ret.push_back( path );
            }
            return ;
        }

        if( root->left != NULL ){
            inOrderTraversal( root->left, sum, path, ret );
        }

        if( root->right != NULL ){
            inOrderTraversal( root->right, sum, path, ret );
        }

        return ;
    }

    void minimumDepthInOrderRec( TreeNode* root, int depth, int& min ){
        depth++;
        if( root->left == NULL && root->right == NULL ){
            min = MIN2( depth, min );
            return ;
        }

        if( root->left != NULL ){
            minimumDepthInOrderRec( root->left, depth, min );
        }

        if( root->right != NULL ){
            minimumDepthInOrderRec( root->right, depth, min );
        }

        return ;
    }

    int minDepth(TreeNode *root) {
        if( root == NULL ){
            return 0;
        }

        int min = INT_MAX;
        minimumDepthInOrderRec( root, 0, min );
        return min;
    }
};
