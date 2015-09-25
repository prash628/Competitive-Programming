#include<iostream>
#include<string>
using namespace std;


 int a,b,c;


int main()
{

    int T;
    //cin>>T;
    T=1;
    int i;

    int x;
    for(i=0;i<T;i++)
    {
         cin>>a;
         cin>>b;
		 cin>>c;
		 int max=-1;

		 if((a+b)*c>max)
		 {
			 max=(a+b)*c;
		 }
		 if(a*(b+c)>max)
		 {
			 max=a*(b+c);
		 }
		  if(a+b+c>max)
		 {
			 max=a+(b+c);
		 }
		   if(a*b*c>max)
		 {
			 max=a*b*c;
		 }
		    if(a+(b*c)>max)
		 {
			 max=a+(b*c);
		 }
			    if(a*(b+c)>max)
		 {
			 max=a*(b+c);
		 }


             cout<<max<<"\n";




    }
    return(0);
}
