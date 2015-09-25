#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;



long long N,M;


 int cats[100000];

 int visit[100000];


vector< vector<int> > A;

struct mystruct2
{
    long long conseccats;
    int pos;
    long long maxcats;
};

stack<struct mystruct2> mystack;
long long res;

int main()
{

    int T;
    //cin>>T;
    T=1;
    res=0;

    for(int i=0;i<T;i++)
    {
        cin>>N;
        cin>>M;
        for(int j=0;j<N;j++)
        {
            cin>>cats[j];
            visit[j]=0;
        }

        for(int j=0;j<N;j++)
        {
            A.push_back(vector<int>());
        }

        int temp1,temp2;
        for(int j=0;j<(N-1);j++)
        {
            cin>>temp1;cin>>temp2;
            temp1--;
            temp2--;
            A[temp1].push_back(temp2);
            A[temp2].push_back(temp1);
        }

        struct mystruct2 node;
        node.conseccats=cats[0];
        node.pos=0;
        node.maxcats=cats[0];
        mystack.push(node);
        visit[0]=1;
        while(mystack.empty()==false)
        {

            struct mystruct2 lookinat;
            lookinat=mystack.top();
            mystack.pop();



            vector<int> neighbs=A[lookinat.pos];
            int sz=neighbs.size();
            for(int j=0;j<sz;j++)
            {
                int tempn=neighbs[j];
                if(visit[tempn]==0)
                {
                    visit[tempn]=1;
                    struct mystruct2 topush;
                    if(cats[tempn]==0)
                    {
                        topush.conseccats=0;
                        topush.maxcats=lookinat.maxcats;

                    }
                    else
                    {
                        topush.conseccats=lookinat.conseccats+1;

                        if(topush.conseccats>lookinat.maxcats)
                        {
                            topush.maxcats=topush.conseccats;
                        }
                        else
                        {
                            topush.maxcats=lookinat.maxcats;
                        }

                    }
                    topush.pos=tempn;

                    mystack.push(topush);
                }
            }
            if(sz<=1&&lookinat.pos!=0)
            {
                if(lookinat.maxcats<=M)
                {
                    res++;
                }
            }

        }

        cout<<res<<"\n";


    }
    return(0);
}
