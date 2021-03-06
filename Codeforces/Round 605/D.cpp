#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define all(v)  v.begin(),v.end()
// #define int     long long
 
using namespace std;
typedef pair<int,int> pii;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;
 
vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
        if(n > 0)
            s << arr[n - 1] ;
        s<< "]";
        return s.str();
    }
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
//const int N=;
 
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
 
    int n;
    cin>>n;
    int pre1[n], pre2[n], suff1[n], suff2[n],arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    pre1[0]=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            pre1[i]=pre1[i-1]+1;
        }
        else
            pre1[i]=1;
    }
    if(pre1[n-1]==n)
    {
        cout<<n;
        return 0;
    }
    suff1[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            suff1[i]=suff1[i+1]+1;
        }
        else
            suff1[i]=1;
    }
    pre2[0]=0;
    for(int i=1;i<n;i++)
    {
        pre2[i]=max(pre2[i-1],pre1[i-1]);
    }
    suff2[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        suff2[i]=max(suff2[i+1],suff1[i+1]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max({ans,pre2[i],suff2[i]});
        if(i!=0 && i!=n-1 && arr[i-1]<arr[i+1])
        {
 
            ans=max(ans, pre1[i-1]+suff1[i+1]);
 
        }
    }
 
    cout<<ans;
    return 0;
}