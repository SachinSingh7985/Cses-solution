
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
 
     
         mi m;
         int ans = 0;
         int cnt = 0;
         int val = 0;
         int n,k; 
         cin >> n >> k;
         int j=0;
         vi a;
 
         for(int i=0;i<n;i++){
           int x;
           cin >> x;
           a.pb(x);
           if(m.count(x))
           {
            if(m[x]==0)
            {
              m[x]=1;
              val++;
              while(val>k)
              {
                ans += cnt;
                m[a[j]]--;
                if(m[a[j]]==0)val--;
                j++;
                cnt--;
              }
              cnt++;
            }
            else
            {
              cnt++;
              m[x]++;
            }
           }
           else {
            m[x]=1;
            val++;
            while(val>k)
              {
                ans += cnt;
                m[a[j]]--;
                if(m[a[j]]==0)val--;
                j++;
                cnt--;
              }
              cnt++;
           }
           // cout << i << " " << ans << endl;
         }
         ans += (cnt * (cnt+1) )/2 ;
         cout << ans << endl;
 
 
 
 
        
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
         // cout<<endl;
        }
        return 0;
        }
