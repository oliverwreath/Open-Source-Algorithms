class Solution:

    def climbStairs(self, n):
        ary = [1] * (n+1);

        for i in xrange(2, n+1):
            ary[i] = ary[i-1] + ary[i-2];

        return ary[n];
