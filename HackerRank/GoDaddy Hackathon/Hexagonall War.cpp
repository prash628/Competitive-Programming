#include<iostream>
#include<string>
using namespace std;



int N,M;
int res;

int A[1500][1500];
int Romans[1500][1500];
int Persians[1500][1500];

int dpP[1500][1500];
int dpR[1500][1500];

int romanFunc(int row,int col);
int persianFunc(int row,int col);
int main()
{

    int T;
    //cin>>T;
    T=1;

    int temp1,temp2;

    int tryme;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        cin>>M;

        tryme=0;
        for(int p=0; p<N; p++)
        {
            for(int q=0; q<N; q++)
            {
                A[p][q]=0;
                Romans[p][q]=0;
                Persians[p][q]=0;
                dpP[p][q]=-1;
                dpR[p][q]=-1;
            }
        }
        for(int j=0; j<M; j++)
        {
            cin>>temp1;
            cin>>temp2;
            temp1--;
            temp2--;

            if(A[temp1][temp2]==0)
            {
                A[temp1][temp2]=tryme+1;
            }
            tryme=(tryme+1)%2;
        }

        int romanTry=0;
        for(int j=0; j<N; j++)
        {
            if(A[j][0]==1)
            {
                romanTry+=romanFunc(j,0);
            }

        }
        int persianTry=0;
        for(int j=0; j<N; j++)
        {
            if(A[0][j]==2)
            {
                persianTry+=persianFunc(0,j);
            }
        }
        if(romanTry==0&& persianTry==0)
        {
            cout<<"NEITHER\n";
        }
        else
        {
            if(romanTry>0)
            {
                cout<<"ROMANS\n";
            }
            else
            {
                cout<<"PERSIANS\n";
            }
        }

    }
    return(0);
}




int romanFunc(int row,int col)
{

    //Base case
    if(col==N-1)
    {
        return(1);
    }
    if(dpR[row][col]!=-1)
    {
        return(dpR[row][col]);
    }

    //Call all neighbs
    int res=0;
    Romans[row][col]=1;

    if(col-1>=0)
    {
        if(Romans[row][col-1]==0&&A[row][col-1]==1)
        {
            res+=romanFunc(row,col-1);
        }
    }
    if(row+1<N&&col-1>=0)
    {
        if(Romans[row+1][col-1]==0&&A[row+1][col-1]==1)
        {
            res+=romanFunc(row+1,col-1);
        }
    }
    if(row+1<N&&col>=0)
    {

        if(Romans[row+1][col]==0&&A[row+1][col]==1)
        {
            res+=romanFunc(row+1,col);
        }
    }

    if(row<N&&col+1<N)
    {
        if(Romans[row][col+1]==0&&A[row][col+1]==1)
        {
            res+=romanFunc(row,col+1);
        }
    }

    if(row-1>=0&&col+1<N)
    {
        //cout<<"WE IN AT :"<<row<<"and "<<col<<"\n";

        if(Romans[row-1][col+1]==0&&A[row-1][col+1]==1)
        {

            res+=romanFunc(row-1,col+1);
        }
    }
    if(row-1>=0&&col>=0)
    {


        if(Romans[row-1][col]==0&&A[row-1][col]==1)
        {
            {
                res+=romanFunc(row-1,col);
            }
        }
    }
    if(res>=1)
    {
        res=1;
    }
    //cout<<"AT pos:"<<row<<"and col:"<<col<<"the answer is:"<<res<<"\n";
    dpR[row][col]=res;
    return(dpR[row][col]);
}


int persianFunc(int row,int col)
{
    //Base case
    if(row==N-1)
    {
        return(1);
    }
    if(dpP[row][col]!=-1)
    {
        return(dpP[row][col]);
    }

    //Call all neighbs
    int res=0;
    Persians[row][col]=1;

    if(col-1>=0)
    {
        if(Persians[row][col-1]==0&&A[row][col-1]==2)
        {
            res+=persianFunc(row,col-1);
        }
    }
    if(row+1<N&&col-1>=0)
    {
        if(Persians[row+1][col-1]==0&&A[row+1][col-1]==2)
        {
            res+=persianFunc(row+1,col-1);
        }
    }
    if(row+1<N&&col>=0)
    {
        if(Persians[row+1][col]==0&&A[row+1][col]==2)
        {
            res+=persianFunc(row+1,col);
        }
    }
    if(row<N&&col+1<N)
    {
        if(Persians[row][col+1]==0&&A[row][col+1]==2)
        {
            res+=persianFunc(row,col+1);
        }
    }
    if(row-1>=0&&col+1<N)
    {
        if(Persians[row-1][col+1]==0&&A[row-1][col+1]==2)
        {
            res+=persianFunc(row-1,col+1);
        }
    }
    if(row-1>=0&&col>=0)
    {
        if(Persians[row-1][col]==0&&A[row-1][col]==2)
        {
            res+=persianFunc(row-1,col);
        }
    }

    if(res>=1)
    {
        res=1;
    }
    dpP[row][col]=res;
    return(dpP[row][col]);
}
