

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 

using namespace std;

int t = 0 ;
int pSeq[50];
int wSeq[50];
stack<int> mystack; 
stack<int> mystack2; 

int main() {
	//read t
	cin >> t;

	for(int k = 1; k <= t; k++)
	{
		int length = 0;
		int base = 0;
		//read the pSeq and filled the stack
		cin >> length;
		for( int l = 1; l <= length; l++ )
		{
			cin >> pSeq[l];
			for( int tempI = 1; tempI <= pSeq[l]-base; tempI++ )
			{
				mystack.push(0);
			}
			mystack.push(1);
			base = pSeq[l];
		}


		//get the wSeq
		int cntL = 0;
		int cntR = 0;
		int tempL = length;
		while( !mystack.empty() )
		{
			int t = mystack.top();
			mystack2.push(t);
			mystack.pop();

			if(t == 1)
			{
				cntR++;
			}
			else
			{
				cntL++;
			}

			if( cntL == cntR )
			{
				mystack2.pop();
				wSeq[tempL--] = cntR;
				cntL = 0;
				cntR = 0;
				while( !mystack2.empty() )
				{
					mystack.push(mystack2.top());
					mystack2.pop();
				}
				mystack.pop();
			}
		}


		//output 
		for( int l = 1; l <= length; l++ )
		{
			cout << wSeq[l] << ' ' ;
		}
		cout << endl;
	}
	

	system("pause");
    return 0;
}
