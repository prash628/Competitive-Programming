#include<iostream>
#include<string>
using namespace std;



int N;



int main()
{

	int T;
	//cin>>T;
	T=1;
	int i;
	int sum=0;
	int x;
	for(i=0;i<T;i++)
	{
		cin>>x;
		sum+=x;
		cin>>x;
		sum+=x;
		cin>>x;
		sum+=x;
		cin>>x;
		sum+=x;
		cin>>x;
		sum+=x;
		if(sum%5==0 && sum!=0){cout<<(sum/5)<<"\n";}
		else{cout<<-1<<"\n";}

	}
	return(0);
}
