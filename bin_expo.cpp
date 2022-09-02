#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll bin_expo(ll a,ll p)
{
    if(p==0)
    return 1;
    ll res = bin_expo(a, p/2);
    if(p%2==0)
    return res*res;
    else return res*res*a;
}

int main()
{
    ll n,i,j;
    ll a,p;
    cin>>a>>p;
    ll result= bin_expo(a,p);
    cout<<result<<endl;
    return 0;

}