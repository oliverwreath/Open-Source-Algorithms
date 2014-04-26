#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(){
	double t1, t2;
	double threshold = 0.000001;

	cin >> t1 >> t2;
	printf("%.2f\n", t2-t1);
	t1 = t2;

	while( cin >> t2 ){
		if( fabs(t2 - 999.0) < threshold ){
			cout << "End of Output" << endl;
			return 0;
		}else{
			printf("%.2f\n", t2-t1);
			t1 = t2;
		}
	}

	return 0;
}
