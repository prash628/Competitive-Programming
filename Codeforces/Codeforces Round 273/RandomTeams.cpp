
#include<iostream>
#include<string>
using namespace std;



unsigned long long N,M;


unsigned long long perm(unsigned long long d)
{
	unsigned long long x=(d*(d-1));
	return(x/2);
}
int main()
{

	int T;
	//cin>>T;
	T=1;
	int i;

	int x;
	for(i=0;i<T;i++)
	{
		 cin>>N;
		 cin>>M;
		 if(N==M)
		 {
			 cout<<1<<" "<<1<<"\n";
		 }
		 else
		 //TO find min
		 {
			 unsigned long long extra=(N%M);
			 unsigned long long into=N/M;
			 unsigned long long min=(perm(into)*M)+((extra*into));
			 cout<<min<<" ";

			 //To find max
				  extra=N-M+1;
				  unsigned long long max=perm(extra);
				  cout<<max<<"\n";


		 }


	}
	return(0);
}

