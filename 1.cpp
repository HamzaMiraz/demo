#include<bits/stdc++.h>
using namespace std;

//For Debugging
#define debug(a...)          {cout<<__LINE__<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>using iset=tree<T,null_type,less<T>,///descending_order=greater<T>,multi_iset=less_equal<T>
rb_tree_tag,tree_order_statistics_node_update> ;///exmp= iset<double>st
///who is k'th position= *(set.find_by_order(k)),index of v = set.order_of_key(v);

typedef long long ll;/// 1e18;
//typedef __int128_t LL;/// 1e32;
template <typename T>
T BIGMOD(T base,T power,T Mod=1e9+7){T ans = 1;
while(power){if(power & 1)ans = (ans * base) % Mod;
base = (base * base) % Mod;power = power >> 1;}return ans;}

template <typename T>
T INV(T base,T mod=1e9+7){//defult mod=1e9+7
    return BIGMOD(base%mod,mod-2,mod)%mod;///base^-1
}

template <typename T>
T nCr(T n, T r){T res=1;for (T i=0;i<r;i++){
res *= (n-i);res /= (i+1);}return res;}/// NCR

template <typename T>
T fact(T n){if(n<=1)return 1;return n*fact(n-1);}

template <typename T>
T nPr(T n, T r){return fact(n)/fact(n-r);}///NPR


#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define all(x) x.begin(), x.end()
#define loop(IV,INIT,NV) for(int IV=INIT;IV<=NV;IV++)
#define lbv(vec,x) lower_bound(all(vec),x)-vec.begin()//retrun index
#define ubv(vec,x) upper_bound(all(vec),x)-vec.begin()
#define lba(ar,n,x) lower_bound(ar,ar+n,x)-&ar[0];//return index
#define uba(ar,n,x) upper_bound(ar,ar+n,x)-&ar[0];
#define lb(mp,x) mp.lower_bound(x);///for set,map
#define ub(st,x) st.upper_bound(x);///return pointer address
#define GCD(a,b)  __gcd(a,b)
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sqr(a)    ((a)*(a))
#define deg(n)  n*PI/180 /// redian to degree
#define sp(n,d)  fixed << setprecision(d) <<n
#define pb emplace_back
#define F  first
#define S  second
#define ss " "
#define nn printf("\n");
#define el cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e9+10;
const ll MOD = 1e9 +7;// Prime

void kadanes(){
    ll ar[n+6];
    ll mx=-9999999999;
    ll sum=0;
    ll l=0,r=0;

    for(int i=1;i<=n;i++){

        if(sum+ar[i]>)
        sum=max(ar[i],sum+ar[i]);
        mx=max(mx,sum);
    }
    cout<<mx<<"\n";
}

void solve(){
    ll n,k;
    cin>>n>>k;
    ll ar[n+2];
    string s;
    cin>>s;
    s='&'+s;
    for(ll i=1;i<=n;i++)cin>>ar[i];

    ll mx=-1e18;
    ll sum=0;
    ll r=1;
    for(ll i=1;i<=n;i++){
        sum+=ar[i];
        if(sum>=mx){
            mx=sum;
            r=i;
        }
    }
    ll l=n;
    mx=-1e18;
    sum=0;
    for(ll i=n;i>=1;i--){
        sum+=ar[i];
        if(sum>=mx){
            mx=sum;
            l=i;
        }
    }
    if(sum==k){
        yes
        for(ll i=1;i<=n;i++){
            cout<<ar[i]<<" ";
        }
        el
        return;
    }
    if(sum>k){
        vector<ll>idx;
        for(ll i=l;i<=r;i++){
            if(s[i]=='0')idx.push_back(i);
        }
        if(idx.size()==0){
            no
            return;
        }
        ll df=sum-k;
        ll z=idx.size();
        ll ispart=df/z;
        df%=z;
        for(auto i : idx){
            ar[i]=-ispart;
            if(df){
                ar[i]--;
                df--;
            }
        }
        yes
        for(ll i=1;i<=n;i++){
            cout<<ar[i]<<" ";
        }
        el
        return;
    }
    for(ll i=l;i<=r;i++){
        if(s[i]=='0'){
            ar[i]=k-sum;
            yes
            for(ll i=1;i<=n;i++){
                cout<<ar[i]<<" ";
            }
            el
            return;
        }
    }
    
    for(ll i=1;i<=l;i++){
        if(s[i]=='0'){
            ll sum1=0;;
            for(ll j=i;j<=l-1;j++){
                sum1+=ar[i];
            }
            ar[i]=k-(sum+sum1);
            yes
            for(ll i=1;i<=n;i++){
                cout<<ar[i]<<" ";
            }
            el
            return;
        }
    }
    for(ll i=n;i>=r;i--){
        if(s[i]=='0'){
            ll sum1=0;;
            for(ll j=i;j>r;j--){
                sum1+=ar[i];
            }
            ar[i]=k-(sum+sum1);
            yes
            for(ll i=1;i<=n;i++){
                cout<<ar[i]<<" ";
            }
            el
            return;
        }
    }
    no
}

signed main()
{
#ifndef ONLINE_JUDGE
     freopen("inputf.in", "r", stdin);  ///To read from a file.
//    freopen("outputf.in", "w", stdout);  ///To write  a file.
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int tks=1;
    cin>>tks;
    for(int ks=1;ks<=tks;ks++){
        //cout<<"Case "<<ks<<": ";
        solve();
    }
    //cerr<<"\nTime:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
///invisible =  