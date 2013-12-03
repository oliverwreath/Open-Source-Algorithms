class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if( n == 0 ){
            return 0;
        }
        if( n == 1 ){
            if( A[0] == elem ){
                return 0;
            }
            else{
                return 1;
            }
        }
        int len = n;
        int begin = 0;
        int end = n-1;
        while( begin < end ){
            while( A[begin] != elem && (begin < end) ){
                begin++;
            }
            if( begin == end ){
                //meet, break;
                break;
            }
            else{
                //try to swap from back;
                len--;
                while( A[end] == elem && (begin < end) ){
                    end--;
                    len--;
                }
                if( begin == end ){
                    //meet, no swap, break;
                    begin++;
                    break;
                }
                else{
                    //found one, swap
                    int tmp = A[begin];
                    A[begin] = A[end];
                    A[end] = tmp;
                    end--;
                }
                begin++;
            }
        }
        if( begin == end ){
            if( A[begin] == elem ){
                len--;
            }
        }
        return len;
    }
};
