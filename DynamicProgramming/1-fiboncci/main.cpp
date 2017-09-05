#include <iostream>

using namespace std;
//find the nth fibonacci number
int fib[100005];
int fibonacci(int n){
    if(n<=2)
    return fib[n];
    else
    fib[n]=fibonacci(n-1)+fibonacci(n-2);
    return fib[n];
}
//fib2 is faster
int fibonacci2(int n)
{
  for (int i = 3; i <= n; i++)
      fib[i] = fib[i-1] + fib[i-2];

  return fib[n];
}
int main()
{
    while(1){
    int n;cin>>n;
    fib[1]=0;fib[2]=1;
    int f=fibonacci2(n);
    cout<<f<<endl;
    }
}
