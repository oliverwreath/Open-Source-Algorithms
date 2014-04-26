#include <iostream>
#include <string>

using namespace std; 

int main(){
	double t1, t2; 
	cin >> t1 >> t2;
	cout << t2 - t1 << endl;
	t1 = t2;

	while( cin >> t2 ){
		if( t2 == (double)999 ){
			cout << "End of Output" << endl;
			return 0;
		}else{
			cout << t2 - t1 << endl;
			t1 = t2;
		}
	}

	return 0;
}