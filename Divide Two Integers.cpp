class Solution {
public:
    int multiply( int a, int b ){
        int ret;
        if( a > b ){
            ret = a;
            for( int i = 1; i <= b-1; i++ ){
                ret += a;
            }
        }
        else{
            ret = b;
            for( int j = 1; j <= a-1; j++ ){
                ret += b;
            }
        }
        return ret;
    }

    int divide( int aa, int bb) {
        if( aa == 0 || bb == 0){
            return 0;
        }
        if( bb == 1 ){
            return aa;
        }
        bool flag = false;
        if( aa < 0 && ( bb > 0 ) || ( aa > 0 && ( bb < 0 ) ) ){
            flag = true;
        }
        long long a = abs((long long)aa);
        long long b = abs((long long)bb);
        if( a < b ){
            return 0;
        }
        long long i = 1;
        long long tmp = b;
        while( a > (tmp=tmp<<1) ){
            i++;
        }
        if( a == tmp ){
            //found! 
            if( flag ){
                return -(1<<i);
            }
            else{
                return (1<<i);
            }
        }else{
            i--;
        }
        
        long long ret = (1<<i);
        //calc
        tmp = tmp>>1;
        i--;
        while( i >= 0 ){
            long long tmpB = b<<i;
            long long tmpR = 1<<i;
            while( a > tmp ){
                tmp += tmpB;
                ret += tmpR;
            }
            if( a < tmp ){
                tmp -= tmpB;
                ret -= tmpR;
                i--;
            }else{
                //found! 
                if( flag ){
                    return -ret;
                }
                else{
                    return ret;
                }
            }
        }
        if( flag ){
            return -ret;
        }
        else{
            return ret;
        }
    }
};
