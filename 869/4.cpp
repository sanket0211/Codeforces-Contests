#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353
ll ar[5003],inv[5003];

ll po(ll x,ll y) 
{
        if(x==0) return 1;
        ll z = po(x/2,y);
        z = (z*z)%mod;
        if(x&1) z = (z*y)%mod;
        return z;
}

ll fun(ll a,ll b) {
        ll i,j,k,l,fi=0;
        for(i=1;i<=min(a,b);i++) {
                k = ar[a];
                l = ar[b];
                        k = (k*inv[i])%mod;
                        l = (l*inv[i])%mod;
                k = (k*inv[a-i])%mod;
                l = (l*inv[b-i])%mod;
                k = (k*ar[i])%mod;
                fi = (fi+(k*l)%mod)%mod;
        }
        return fi;
}

int main() 
{
        ll i,j,k,l,n,m,a,b,c,a1,a2,a3;
        cin>>a>>b>>c;
        ar[0] = 1;
        inv[0] = 1;
        for(i=1;i<=5003;i++)
                ar[i] = (ar[i-1]*i)%mod;
        for(i=1;i<=5003;i++)
                inv[i] = (po(mod-2,i)*inv[i-1])%mod;
        ll fi = 0,se= 0,th=0;
        fi = fun(a,b);
        se = fun(b,c);
        th = fun(a,c);
        fi = (fi+1)%mod;
        se = (se+1)%mod;
        th = (th+1)%mod;
        cout<<((fi*se)%mod*th)%mod<<endl;
        return 0;
}