//Fast io for cppp-rem that itz only for int n char-not for //unsigned long long

#include <cstdio>
#include <iostream>
using std::string;

static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;



int N,C,qtype;

int p,q;
long long int v;

long long int tree1[100002];

long long int tree2[100002];



void updateIt(int type,int x,long long int val)
{
	if(type==1)
	{
		while(x<=N)
		{
			tree1[x]+=val;
			x+=(x & (-1*x));
		}
	}

	if(type==2)
	{
		while(x<=N)
		{
			tree2[x]+=val;
			x+=(x & (-1*x));
		}
	}

}
void updateX(int p,int q,long long int val)
{
	updateIt(1,p,val);
	updateIt(1,q+1,(-1*val));
	updateIt(2,p,((p-1)*val));
	updateIt(2,q+1,(val*q*-1));
}





long long int daquery(int type,int x)
{
	long long int sum=0;
	if(type==1)
	{
		while(x>0)
		{
			sum+=tree1[x];
			x-=(x& (-1*x));
		}
	}
	if(type==2)
	{
		while(x>0)
		{
			sum+=tree2[x];
			x-=(x& (-1*x));
		}
	}
	return(sum);
}
long long int qres(long long int x)
{
	return((x*daquery(1,x))-daquery(2,x));
}
long long int query(int p,int q)
{
	return(qres(q)-qres(p-1));
}



int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		for(int x=0;x<100002;x++)
		{
			tree1[x]=0;
			tree2[x]=0;
		}
		cin>>N;
		cin>>C;

		for(int x=0;x<C;x++)
		{
			cin>>qtype;
			if(qtype==0)
			{
				cin>>p;
				cin>>q;
				cin>>v;
				updateX(p,q,v);
			}
			else
			{
				cin>>p;
				cin>>q;
				cout<<query(p,q)<<"\n";
			}
		}


	}
	return(0);
}
