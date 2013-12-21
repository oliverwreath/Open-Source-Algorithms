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

    void maximumDepthInOrderRec( TreeNode* root, int depth, int& max ){
        depth++;
        if( root->left == NULL && root->right == NULL ){
            max = MAX2( depth, max );
            return ;
        }

        if( root->left != NULL ){
            maximumDepthInOrderRec( root->left, depth, max );
        }

        if( root->right != NULL ){
            maximumDepthInOrderRec( root->right, depth, max );
        }

        return ;
    }

    bool preOrderTravTwoTree( TreeNode* p, TreeNode* q ){
        if( p->val != q->val ){
            return false;
        }

        if( p->left != NULL ){
            if( q->left == NULL ){
                return false;
            }
            if( !preOrderTravTwoTree( p->left, q->left ) ){
                return false;
            }
        }

        if( p->right != NULL ){
            if( q->right == NULL ){
                return false;
            }
            if( !preOrderTravTwoTree( p->right, q->right ) ){
                return false;
            }
        }

        return true; 
    }

    bool isValidBSTHelper( TreeNode* root, int min, int max ){
        if( root->val > min && root->val < max ){
        }else{
            return false;
        }

        if( root->left != NULL ){
            if( !isValidBSTHelper( root->left, min, root->val ) ){
                return false;
            }
        }

        if( root->right != NULL ){
            if( !isValidBSTHelper( root->right, root->val, max ) ){
                return false;
            }
        }

        return true; 
    }

    bool isValidBST(TreeNode *root) {
        if( root == NULL ){
            return true;
        }

        return isValidBSTHelper( root, INT_MIN, INT_MAX );
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if( p == NULL || q == NULL ){
            if( p != q ){
                return false; 
            }else{
                return true;
            }
        }

        return preOrderTravTwoTree( p, q );
    }

    int maxDepth(TreeNode *root) {
        if( root == NULL ){
            return 0;
        }

        int max = INT_MIN;
        maximumDepthInOrderRec( root, 0, max );
        return max;
    }
};
