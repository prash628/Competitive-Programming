#include<iostream>
#include<string>
using namespace std;



int N;
 int res;


int main()
{

	int T;
	//cin>>T;
	T=1;
	long long temp,maxy;maxy=-1;int count1=0;
	res=0;


	for(int i=0;i<T;i++)
	{
		cin>>N;
		for(int j=0;j<N;j++)
        {
            cin>>temp;
            if(temp>=maxy){
                count1++;
                if(count1>res)
            {
                res=count1;
            }
            }
            else{
                count1=1;

            }maxy=temp;

        }

		cout<<res<<"\n";

	}
	return(0);
}
