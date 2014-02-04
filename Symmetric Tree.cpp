#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

        stack<iterator> st1;
        stack<iterator> st2;

        st1.push( root->left );
        st2.push( root->right );
        
        while( !st1.empty() || !st2.empty() ){
            iterator p = st1.top();
            iterator q = st2.top();
            st1.pop();
            st2.pop();

            if( p->val != q->val ){
                return false;
            }

            if( p->left != NULL && q->right == NULL ){
                return false;
            }

            if( p->left == NULL && q->right != NULL ){
                return false;
            }

            if( p->left != NULL && q->right != NULL ){
                st1.push(p->left);
                st2.push(q->right);
            }


            if( p->right != NULL && q->left == NULL ){
                return false;
            }

            if( p->right == NULL && q->left != NULL ){
                return false;
            }

            if( p->right != NULL && q->left != NULL ){
                st1.push(p->right);
                st2.push(q->left);
            }
        }

        return true;
    }
};

