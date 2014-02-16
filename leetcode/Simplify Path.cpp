/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#include <vector>

class Solution {
public:
	//typedef
	typedef TreeLinkNode* iterator; 

	//methods
	string simplifyPath(string path){
		vector<string> vt;
		int len = path.size();
		bool slash = false;
		int i = 0;
		
		while( i < len ){
			if( path[i] == '/' ){
				i++;
				if( i >= len ){
					break; 
				}
				string tmp = ""; 
				while( i < len && path[i] == '/' ){
					i++;
				}
				while( i < len && path[i] != '/' ){
					tmp += path[i];
					i++;
				}
				
				if( tmp == "" ){
				}else if( tmp == "." ){
				}else if( tmp == ".." ){
					if( !vt.empty() ){
						vt.pop_back();
					}
				}else{
					vt.push_back( tmp );
				}
			}
		}

		if( vt.empty() ){
			return "/";
		}else{
			string ret = "";
			while( !vt.empty() ){
				ret += "/";
				ret += vt.front();
				vt.erase( vt.begin() );
			}
			return ret;
		}
	}
};
