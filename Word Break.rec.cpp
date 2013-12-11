#define F(i, a, b) for(int i = a; i <= b; i++)

class Solution {
public:
    //bool 

    bool wordBreak(string &s, unordered_set<string> &dict) {
        int len = s.size();

        F(i, 1, len){
            if( dict.find( s.substr(0,i) ) != dict.end() ){
				if( i == len ){
					return true;
				}
				string tmp = s.substr(i);
                if( wordBreak( tmp, dict ) ){
                    return true;
                }
            }
        }

        return false;
    }
};
