#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <queue>

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
    //typedef 
    typedef TreeNode* iterator;

    //methods
    void helper( iterator root, vector<int>& ret ){
        if( root->left != NULL ){
            helper(root->left, ret);
        }

        ret.push_back(root->val);

        if( root->right != NULL ){
            helper(root->right, ret);
        }

        return ;
    }

    vector<int > inorderTraversal(iterator root){
        vector<int> ret = vector<int>();

        if( root == NULL ){
            return ret;
        }

        helper( root, ret ); 

        return ret;
    }
};
