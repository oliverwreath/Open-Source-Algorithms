#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

int main()
{
 string a ;

 while( cin >> a )
 {
  if( a.length() == 1 && a[0] == '0' )
  {
   break ; 
  }
  int ret = a[0]-48 ;
  if( ret > 4 )
  {
   ret-- ;
  }
  for( int i = 1 ; i < (int)a.length() ; i++ )
  {
   if( a[i] < '4' )
   {
    ret *= 9 ;
    ret += ( a[i]-48 ) ;
   }
   else
   {
    ret *= 9 ;
    ret += ( a[i]-48-1 ) ;
   }
  }
  cout << a << ": " << ret << endl ;
 
 }

 return 0 ;
}

