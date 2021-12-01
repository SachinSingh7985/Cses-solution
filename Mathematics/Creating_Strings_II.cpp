#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define int         long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define mp          make_pair
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
//#define hell          1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
// mp::cpp_int
 
const int hell=1e9+7;
 
 
 
const int M=1000006;
int f[M],inv[M];
int expo(int base,int exponent,int mod=hell){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
  f[0]=1;
  rep(i,1,M){
    f[i]=(1LL*i*f[i-1])%hell;
  }
  inv[M-1]=expo(f[M-1],hell-2,hell);
  for(int i=M-2;i>=0;i--){
    inv[i]=(1LL*(i+1)*inv[i+1])%hell;
  }
}
int C(int n,int r){
  return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
 
int solve()
{  
compute();
 
  string s;
  cin>>s;
  int n=s.size();
  mi m;
  rep(i,0,n)m[s[i]]++;
   int ans=1;
   for(auto x:m)
   {
    ans*=f[x.SS];
    ans%=hell;
   }
  int ans1=f[n]*expo(ans,hell-2);
  ans1%=hell;
  cout<<ans1;
 
 
return 0;
}
 
signed main()
{  int t=1;
 
 ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
  
   cin.exceptions(cin.failbit);                                                                    
     
 /*  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);                                   
    #endif                                   
 */ 
 
  clock_t time_req;
                                                                                                                   
 //cin>>t;
 
    int k=1;
     
   while(t--)
     {
      solve();
     }
        exit(0);
 
 
         time_req = clock() - time_req;
    cout <<endl<< "Processor time taken is "
      << (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;
 
    return 0;
 
}
