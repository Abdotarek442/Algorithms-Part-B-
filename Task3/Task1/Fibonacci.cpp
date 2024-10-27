#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fib_rec(int n){
    if(n<=0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fib_rec(n-1) + fib_rec(n-2);
    }
}

void multiplcation(int f[2][2], int t[2][2]) {
    int a = f[0][0] * t[0][0] + f[0][1] * t[1][0];
    int b = f[0][0] * t[0][1] + f[0][1] * t[1][1];
    int c = f[1][0] * t[0][0] + f[1][1] * t[1][0];
    int d = f[1][0] * t[0][1] + f[1][1] * t[1][1];

    f[0][0] = a;
    f[0][1] = b;
    f[1][0] = c;
    f[1][1] = d;
}

void power(int f[2][2], int n) {
    if (n == 0||n==1)
        return;

    int t[2][2] = {{1, 1}, {1, 0}};

    power(f, n / 2);
    multiplcation(f, f);

    if (n%2!= 0)
        multiplcation(f, t);
}

int fib_matrix(int n) {
    if (n == 0)
        return 0;

    int f[2][2] = {{1, 1}, {1, 0}};
    power(f, n - 1);
    return f[0][0];
}

int fib_DP_iterative(int n){
    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    if(n<=0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    for(int i=2;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
};

vector<int> dp(100000,-1);

int fib_DP_recursive(int n ){
    if ( n == 0 )
        return 0;
    if ( n == 1)
        return 1;
    int &ret = dp[n];
    if (~ret)
        return ret;
    return fib_DP_recursive(n-1)+ fib_DP_recursive(n-2); 
}


int main() {
    int n;
    dp[0] = 0;
    dp[1] = 1;
    cout<<"enter the number: ";
    cin>>n;

    cout<<"the value of the fibonacci number (recursive) is: "<<fib_rec(n)<<endl;
    cout << "Fibonacci (Matrix Multiplication) of  is: " << fib_matrix(n) << endl;
    cout<<"the value of the fibonacci number (dynamic programming iterative) is: "<<fib_DP_iterative(n) << endl;
    cout<<"the value of the fibonacci number (dynamic programming recursion) is: "<<fib_DP_recursive(n);
}