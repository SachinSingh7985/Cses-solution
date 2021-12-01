        #pragma GCC optimize("Ofast")
        #pragma GCC optimize("unroll-loops")
        #pragma GCC target("sse2")
     
        #include <bits/stdc++.h>
        #include <vector> 
        #include <ext/pb_ds/assoc_container.hpp>
        #include <ext/pb_ds/tree_policy.hpp>
        using namespace std;
     
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
        #define rep(i,a,b)  for(int i=a;i<b;i++)
         int hell=1000000007;
         ll mod=998244353;
 
 
 
         
        int solve(){ 
 
          
         int n;
         cin >> n;
         vi a(n);
         int dp[n];
         for(int i=0;i<n;i++){
          cin >> a[i];
          dp[a[i]-1]=i;
        }
 
         int ans = 0;
          int i=0;
          while(i<n){
            ans++;
            while(i<n&&dp[i+1]>dp[i]){
              i++;
            }
            i++;            
           }
          cout << ans ;
 
 
        
         return 0;
            
            }
 
 
 
        signed main()
        {      
    
 
          // #ifndef ONLINE_JUDGE
          // freopen("input.txt", "r" , stdin);
          // freopen("output.txt", "w", stdout);                                  
          // #endif  
      
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0); 
     
        int t=1,k=1;                                                                                                                  
          // cin>>t;
 
       
       
        while(t--)
        {
         
         // cout<<"Case #"<<k++<<": ";
         solve();
         //cout<<endl;
        }
        return 0;
        } 
