#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int N;

int A[100000];
int where[100000];
double res;
int visit[100000];
vector<int> startPts;
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    res=0.00;
    double newOne;
    int next;
    int first;
    for(int i=0; i<100000; i++)
    {
        visit[i]=0;
    }
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>A[i];
        A[i]--;
        cin>>where[i];
    }
    for(int i=0; i<N; i++)
    {
        first=1;
        if(visit[i]==0)
        {
            next=i;
            while(1)
            {

                if(visit[next]==1)
                {
                    startPts.push_back(next);

                    break;
                }
                else
                {
                    if(first==1)
                    {
                        newOne=((double)where[next])/100.0;
                        first=0;
                    }
                    else
                    {
                        newOne=(double)newOne*(where[next]/100.0);
                    }


                }
                // cout<<"UP IN THIS :"<<next<<"\n";
                visit[next]=1;
                next=A[next];
            }
        }
        // cout<<"what"<<i<<":"<<newOne<<"\n";
        //  res+=newOne;

    }




    for(int i=0; i<100000; i++)
    {
        visit[i]=0;
    }

    int len=startPts.size();
    for(int i=0; i<len; i++)
    {
        newOne=0.0;
        first=1;

        if(visit[startPts[i]]==0)
        {
            next=startPts[i];
            while(1)
            {

                if(visit[next]==1)
                {

                    break;
                }
                else
                {
                    if(first==1)
                    {
                        newOne=((double)where[next])/100.0;
                        first=0;
                    }
                    else
                    {
                        newOne=(double)newOne*(where[next]/100.0);
                    }


                }
                visit[next]=1;
                next=A[next];
            }
        }
        res+=newOne;
    }
    cout << setprecision(2) << fixed <<  res << '\n';


    return 0;
}
