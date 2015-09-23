#include<iostream>
#include<string>
using namespace std;



int N;
long long num1,num2;
long long res;



long long rev(long long x)
{
	long long dares=0;
	while(x>0)
	{
		dares=dares*10+(x%10);
		x=x/10;
	}
	return(dares);
}


long long findres()
{
	long long x=rev(num1);
	long long y=rev(num2);
	long long z=x+y;
	long long a=rev(z);
	return(a);
}

int main()
{

	int T;
	cin>>T;
	int i;
	long long res;
	for(i=0;i<T;i++)
	{
		cin>>num1;
		cin>>num2;
		res=findres();
		cout<<res<<"\n";

	}
	return(0);
}
