#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
//Shorthands
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<=k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) for (int i=0 ; i<=j ; i+=1)
#define RREP(i, j)for (int i=j ; i>=0 ; i-=1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (typeof(l.begin()) it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
// typedefs
using namespace std;
//Generic fast inputs
template <class T>
inline T read()
{
    T n=0;
    bool sign=0;
    char p=gc();
    if(p=='-')
        sign=1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-')
        p=gc();
    if(p=='-')
        sign=1,p=gc();
    while(p>='0'&&p<='9') {
        n = (n<< 3) + (n<< 1) + (p - '0');
        p=gc();
    }
    if(sign)
        return -n;
    return n;
}
inline void readStr(char *str)
{
    register char c=0;
    register int i = 0;
    while (c < 33)
        c = gc();
    while (c > 65)
    {
        str[i] = c;
        c = gc();
        i = i + 1;
    }
 
    str[i] = '\0';
}
//Generic fast output function
template <class T> inline void write(T x)
{
    register int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';
 
    do
    {
        buf[--i] = x % 10 + '0';
        x/= 10;
    }while(x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}
 
//prime generating sieve
int isprime[32001]={0};
int prime[3432];
int* sieve(int *isprime,int n)
{
    int j=0;
    FOR(i,2,32000,1)
    {
        if(isprime[i]==0)
            prime[j++]=i;
        FOR(k,i,32000,i)
        {
            isprime[k]=1;
        }
 
    }
return prime;
}
bool primeCheck(int* prime,long long int n)
{   int i=0;
    while(prime[i]*prime[i]<=n)
    {
        if(n%prime[i]==0)
        {
    //        printf("returned 0 with %d\n",n);
            return 0;
        }
 
        ++i;
    }
    //printf("returned 1 with %d\n",n);
    return 1;
 
 
}
int main()
{
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    sieve(isprime,32000);
    //FOR(i,0,3431,1)
    //printf("%d ",prime[i]);
    int t=read<int>();
    long int n,m;
    FOR(i,0,t-1,1)
    {
      m=read<int>();
      n=read<int>();
      FOR(j,m,n,1)
      {    if(j==1)
                continue;
          if(primeCheck(prime,j))
          {
              printf("%ld\n",j);
          }
      }
      printf("\n");
    }
 
    return 0;
 
    }
 