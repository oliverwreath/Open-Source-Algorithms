

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#include <math.h>
#define F(i, a, b) for(int i = a; i <= b; i++)
#define MAX3(a, b, c) (a>b?a:b)>c?(a>b?a:b):c

using namespace std;

int n = 0;
string s;
int a = 0;
int b = 0;
int c = 0;
int d = 0;

int conv(string ss)
{
	int ret = 0;
	F(i, 0, ss.size()-1)
	{
		ret += (ss.at(i)-'0') * (int)(pow(2.0, (int)(ss.size()-1-i)));
	}
	return ret;
}

int main() {
	//while( scanf("%d",&cash)!=EOF )

	//read stuff
	scanf("%d", &n);

	F(m, 1, n)
	{
		cin >> s;
		a = conv(s.substr(0,8));
		b = conv(s.substr(8,8));
		c = conv(s.substr(16,8));
		d = conv(s.substr(24,8));
		cout << a << '.' << b << '.' << c << '.' << d << endl;
	}

	

	system("pause");
    return 0;
}
