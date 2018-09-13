#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int a[45]={0},i,n;
	while(cin>>n)
	{
		a[0]=1;a[1]=1;
		for(i=2;i<n;i++)
		{
			a[i]=a[i-1]+a[i-2];
		}
		cout<<a[n-1]<<endl;
	}
	 
	
	return 0;
}

