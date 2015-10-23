#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

string A,B;
int lenA,lenB;
int onemis,zeromis;
int myfunc();
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout<<myfunc();
    return (0);
}
int myfunc()
    {
    cin>>A;
    onemis=0;
    zeromis=0;
    cin>>B;
    if(A==B)
{return(0);}
    lenA=A.length();
    lenB=B.length();
    if(lenA!=lenB)
        {
        return(-1);
    }

    for(int i=0;i<lenA;i++)
        {
        if(B[i]!=A[i])
            {
            if(B[i]=='1')
                {
                onemis++;
            }
            else
                {
                zeromis++;
            }
        }

    }

    if(onemis!=zeromis)
        {return(-1);}
    else
        {return(onemis);}
}
