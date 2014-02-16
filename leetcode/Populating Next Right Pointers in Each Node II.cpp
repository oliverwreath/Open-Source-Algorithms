/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#include <queue>

class Solution {
public:
	//typedef
	typedef TreeLinkNode* iterator; 

	//methods
	void connect(TreeLinkNode* root) {
		if( root == NULL ){
			return ;
		}
		queue<iterator> que;
		que.push( root );
		que.push( NULL );

		iterator sl;
		iterator fst;

		fst = que.front();
		que.pop();
		while( !que.empty() ){
			sl = fst;
			fst = que.front();
			que.pop();
			if( sl == NULL ){
				if( fst != NULL ){
					sl = fst;
					fst = que.front();
					que.pop();
				}else{
					break;
				}
			}

			if( fst == NULL ){
				if( sl->left != NULL ){
					que.push( sl->left );
				}
				if( sl->right != NULL ){
					que.push( sl->right );
				}
				que.push( NULL );
			}else{
				sl->next = fst;
				if( sl->left != NULL ){
					que.push( sl->left );
				}
				if( sl->right != NULL ){
					que.push( sl->right );
				}
			}
		}
		return ;
	}
};
