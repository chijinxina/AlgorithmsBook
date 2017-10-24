#include <iostream>
using namespace std;

int s1_fib(int n)
{
	int s,a,i;
	if(n==0) return 1;
	else if(n==1) return 1;
	else
	{
		a=1;
		for(i=2;i<=n;i++)
		{
			a=2*a;
		}
		return a;
	}
}

int s2_fib(int n)
{
	int s;
	if(n==0) return 1;
	else if(n==1) return 1;
	else	return 2*s2_fib(n-1);
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<"变态跳台阶迭代"<<s1_fib(n)<<endl;
		cout<<"变态跳台阶递归"<<s2_fib(n)<<endl;
	}
	return 0;
}
