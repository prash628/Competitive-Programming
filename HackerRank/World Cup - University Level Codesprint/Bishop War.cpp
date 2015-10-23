#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int A[10][10];//Obstacles
long rowBit[10];
long dp[2000000][10];


long long func(int level,long bitVector);
int possible(int i,int j,long bitV);
long placeBish(int i,int j,long bitV);
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>N;
    cin>>M;
    char temp;

    for(int i=0; i<2000000; i++)
    {
        for(int j=0; j<10; j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>temp;
            if(temp=='.')
            {
                A[i][j]=0;
            }
            else
            {
                A[i][j]=1;
            }
        }
    }
    long bit;
    //Precompute row Bit
    for(int i=0; i<N; i++)
    {
        bit=0;
        for(int j=0; j<M; j++)
        {
            if(A[i][j]==1)
            {
                //Rightstrike-  j-i+(N-1)
                //Left  i+j+(2*(N-1))
                bit=bit|((long)1<<(j-i+(N-1)));
                bit=bit|((long)1<<(i+j+(2*(N-1))));

            }
        }
        bit=~bit;
        rowBit[i]=bit;
        //cout<<bit<<"\n";
    }



    int res=func(0,0);
    cout<<res;


    return 0;
}
long long func(int level,long bitvector)
{
    if(level==N)
    {
        return(0);
    }
    if(bitvector<2000000 && bitvector>=0)
    {
        if(dp[bitvector][level]!=-1)
        {
            return(dp[bitvector][level]);
        }
    }

    long long maxChoice=0;
    long long temp;
    long sendBit;
    for(int i=0; i<M; i++)
    {
        if(A[level][i]!=1)
        {
            if(possible(level,i,bitvector))
            {

                sendBit=placeBish(level,i,bitvector);
                sendBit=sendBit&rowBit[level];
                if(level==(N-1))
                {
                    maxChoice+=1;
                }
                else
                {
                    maxChoice+=func(level+1,sendBit);

                }




            }


        }

    }
    //cout<<"MAX FOR LEVEL:"<<level<<"is:"<<maxChoice<<"\n";
    if(bitvector<2000000 && bitvector>=0)
    {
        dp[bitvector][level]=maxChoice;
    }


    return(maxChoice);
}


int possible(int i,int j,long bitV)
{
    long rightExtract,leftExtract;
    //Rightstrike-  j-i+(N-1)
    //Left  i+j+(2*(N-1))
    rightExtract=((long)1<<(j-i+(N-1)))&bitV;
    leftExtract=((long)1<<(i+j+(2*(N-1))))&bitV;
    if(rightExtract==0 && leftExtract==0)
    {
        return(1);
    }
    return(0);



}
long placeBish(int i,int j,long bitV)
{
    //Rightstrike-  j-i+(N-1)
    //Left  i+j+(2*(N-1))
    bitV=bitV|((long)1<<(j-i+(N-1)));
    bitV=bitV|((long)1<<(i+j+(2*(N-1))));
    return(bitV);
}
