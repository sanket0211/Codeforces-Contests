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
    int n,k;
    cin>>n>>k;
    vector<int> a(k);
    for (int i=0;i<k;i++)
        cin>>a[i];
    stack<int> s;
    int req = 1;
    for (int i=0;i<k;)
    {
      if (s.size()>0 && s.top()==req)
        {
          s.pop();
          req++;
          continue;
        }
      if (a[i]!=req)
        {
          s.push(a[i]); i++; continue;
        }
      else if (a[i]==req)
        {
          req++;i++; continue;
        }
    }

    stack<int> s1=s;
    vector<int> raj;
    while(s1.size()!=0)
      {
        raj.push_back(s1.top());
        s1.pop();
      }
    for (int i=1;i<raj.size();i++)
      if (raj[i]<raj[i-1])
        {
          cout<<-1<<endl;
          return 0;
        }
    
    for (int i=0;i<k;i++)
      cout<<a[i]<<' ';

    while(s.size()>0)
      {
        for (int i=s.top()-1;i>=req;i--)
          cout<<i<<' ';
        req=s.top()+1;
        s.pop();
      }
    for (int i=n;i>=req;i--)
      cout<<i<<' ';
}