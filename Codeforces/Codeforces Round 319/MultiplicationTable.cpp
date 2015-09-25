#include<iostream>
#include<string>
using namespace std;



int N,x;



int main()
{
    long long res=0;
    long long chk;
    int T;
    //cin>>T;
    T=1;

    for(int i=0;i<T;i++)
    {
        cin>>N;
        cin>>x;





    }
    res=0;
    for(int i=1;i<=N;i++)
    {
        if(x%i==0)
        {
            chk=x/i;
            if(chk<=N)
            {
                res++;

            }

        }
    }
    cout<<res<<"\n";
    return(0);
}
