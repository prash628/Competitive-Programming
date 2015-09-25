
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;



long long N,D,sz;
int res;

long long m,s;
unordered_map<long long,long long> hashmap;



struct mystruct1
{
    long long m;
    long long s;
} A[100000];

bool mybool(const struct mystruct1 &left,const struct mystruct1 &right)
{
    return(left.m<right.m);
}

int main()
{

    int T;
    //cin>>T;
    T=1;

    for(int i=0; i<T; i++)
    {
        cin>>N;
        cin>>D;
        for(int j=0; j<N; j++)
        {
            cin>>m;
            cin>>s;
            unordered_map<long long,long long>::const_iterator it=hashmap.find(m);
            if(it==hashmap.end())
            {
                hashmap[m]=s;
            }
            else
            {
                hashmap[m]+=s;
            }
        }
        int j=0;
        for(unordered_map<long long,long long>::iterator it=hashmap.begin(); it!=hashmap.end(); it++)
        {
            A[j].m=it->first;
            A[j].s=it->second;
            j++;
        }
        sz=j;
        sort(&A[0],&A[sz],mybool);

        long long miny=A[0].m;
        long long leftpos=0;
        long long maxcount=A[0].s;
        long long count1=A[0].s;

        for(int j=1; j<sz; j++)
        {
            long long temp=A[j].m;
            if((temp-A[leftpos].m)<D)
            {
                count1+=A[j].s;
                if(count1>maxcount)
                {
                    maxcount=count1;
                }
            }
            else
            {
                int startpos;
                for( startpos=leftpos; startpos<j; startpos++)
                {
                    if((temp-A[startpos].m)>=D)
                    {
                        count1-=A[startpos].s;
                    }
                    else
                    {
                        break;
                    }
                }
                leftpos=startpos;
                count1+=A[j].s;
                if(count1>maxcount)
                {
                    maxcount=count1;
                }

            }
        }


        cout<<maxcount<<"\n";

    }
    return(0);
}#include<iostream>
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
