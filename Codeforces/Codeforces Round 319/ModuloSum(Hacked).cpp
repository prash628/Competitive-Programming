#include<iostream>
#include<string>
using namespace std;



int mines;


int N,M;
int A[1000000];
int modDp[1000];
int thisUp[1000];
int main()
{
    std::ios::sync_with_stdio(false);

    //cin>>T;
    int T=1;
    for(int i=0; i<1000; i++)
    {
        modDp[i]=0;
    }

    for(int i=0; i<T; i++)
    {
        cin>>N;
        cin>>M;
        for(int j=0; j<N; j++)
        {
            cin>>A[j];

        }
    }
    int temp;
    long long newOne;
    for(int i=N-1; i>=0; i--)
    {
        for(int j=0; j<M; j++)
        {
            thisUp[j]=modDp[j];
        }
        temp=A[i];
        temp=temp%M;
        modDp[temp]=1;
        for(int j=0; j<M; j++)
        {
            if(thisUp[j]==1)
            {
                newOne=j+(long long)temp;
                newOne=newOne%M;
                modDp[newOne]=1;
            }
        }
    }

    if(modDp[0]==1)
    {
        cout<<"YES"<<"\n";
    }
    else
    {
        cout<<"NO"<<"\n";
    }

    return(0);
}
