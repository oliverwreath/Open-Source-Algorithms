#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    typedef TreeNode* iterator;

    bool helper(iterator p, iterator q ){
        if( p->val != q->val ){
            return false;
        }

        if( p->left == NULL && q->right != NULL ){
            return false;
        }

        if( p->left != NULL && q->right == NULL ){
            return false;
        }

        if( p->left != NULL && q->right != NULL ){
            if( !helper(p->left, q->right) ){
                return false;
            }
        }

        if( p->right == NULL && q->left != NULL ){
            return false;
        }

        if( p->right != NULL && q->left == NULL ){
            return false;
        }

        if( p->right != NULL && q->left != NULL ){
            if( !helper(p->right, q->left) ){
                return false;
            }
        }

        return true;
    }

    bool isSymmetric(TreeNode *root){
        if( root == NULL ){
            return true;
        }

        if( root->left == NULL && root->right == NULL ){
            return true;
        }

        if( root->left == NULL && root->right != NULL ){
            return false;
        }

        if( root->left != NULL && root->right == NULL ){
            return false;
        }

        return ( helper(root->left, root->right) );
    }
};
