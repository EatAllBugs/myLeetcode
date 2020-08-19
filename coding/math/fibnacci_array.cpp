/*
斐波那契数列的递归和非递归求法
*/
class Solution {
public:
    int fib(int n) {
        if(n == 0){return 0;}
        if(n == 1){return 1;}
        int a = 0 ,b = 1, c = 0;
        int mod = 1e9 + 7;
        while(n >= 2){
            c = a + b;
            c = c % mod;
            a = b;
            b = c;
            n--;
        }
        return c;
    }
};
/*

*/
class Solution{
    int fib(int n) {
        if(n == 0){return 0;}
        if(n == 1){return 1;}
        if(n >= 2){
            return fib(n-1) + fib(n-2);
        }
        return 0;
    }
};

/*
	青蛙跳台阶问题
*/

class Solution {
public:
    int numWays(int n) {
        if(n <= 1 ){return 1;}
        int mod = 1e9 + 7;
        int a = 1;
        int b = 1;
        int c = 0;
        while(n >= 2){
            c = a + b;
            c = c % mod;
            a = b;
            b = c;
            --n;
        }
        return c;
    }
};

