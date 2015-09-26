
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;



int N;

int toys[100002];

int toyWt[10002];

int startPos;


int main()
{
	int minPos;

	int T;
	//cin>>T;
	T=1;



	for(int x=0;x<10002;x++)
	{
		toyWt[x]=0;
	}
	int i;
	long long res;
	for(i=0;i<T;i++)
	{
		cin>>N;
		for(int x=0;x<N;x++)
		{
			cin>>toys[x];

			toyWt[toys[x]]+=1;

		}

		res=0;

		int immunity=0;
		for(int x=0;x<10002;x++)
		{
			if(immunity>0)
			{
				immunity--;
			}
			else
			{
				if(toyWt[x]!=0)
				{
					res++;
					immunity=4;
				}
			}
		}

		cout<<res<<"\n";

	}
	return(0);
}

