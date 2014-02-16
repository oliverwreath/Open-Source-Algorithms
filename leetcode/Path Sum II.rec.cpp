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

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if( root == NULL ){
            return (vector<vector<int> >()) ;
        }

        vector<int> path; 
        vector<vector<int>> ret; 
        target = sum; 

        inOrderTraversal( root, 0, path, ret ); 

        return ret;
    }   
};
