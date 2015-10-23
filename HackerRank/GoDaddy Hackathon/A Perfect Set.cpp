#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    int D;
    cin>>N;
    cin>>D;
    int res=N/2;
    if(N%2==1){res++;}
    res+=D;
    cout<<res<<"\n";
    return 0;
}
