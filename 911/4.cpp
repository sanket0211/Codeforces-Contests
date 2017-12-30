/*
 * USER: Raj Manvar
 * LANG: C++
 *  */
#include <bits/stdc++.h>
#include <unistd.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define DRT()  int t; cin>>t; while(t--)
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif
using namespace std;
typedef long long int lli;

int main()
{
  int n;
  cin>>n;
  vector<int> a(n);
  for (int i=0;i<n;i++)
    cin>>a[i];

  int c=0;
  for (int i=0;i<n;i++)
    {
      for (int j=i-1;j>=0;j--)
        {
          if (a[i]<a[j])
            c++;
        }
    }
  string pre;
  if (c%2==0)
    pre="even";
  else
    pre="odd";
  int m;
  cin>>m;
  for (int i=0;i<m;i++)
    {
      int l,r;
      cin>>l>>r;
      int c=r-l+1;
      int c1 = ((c)*(c-1))/2;
      if (c1%2==1)
        {
          if (pre=="even")
            pre="odd";
          else
            pre="even";
        }
      cout<<pre<<endl;
    }
}