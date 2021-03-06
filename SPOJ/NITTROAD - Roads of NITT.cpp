    
#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define all(v)  v.begin(),v.end()
#define int     long long

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
const int N=2e4+10;

struct DSU
{
    int connected;
    int par[N], sz[N];

    DSU() {} 

    void init(int n) 
    {
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        connected=n;
    }

    int getPar(int k)
    {
        while(k!=par[k])
        {
            par[k]=par[par[k]];
            k=par[k];
        }
        return k;
    }

    int getSize(int k)
    {
        return sz[getPar(k)];
    }

    void unite(int u, int v)
    {
        int par1=getPar(u), par2=getPar(v);

        if(par1==par2)
            return;

        connected--;

        if(sz[par1]>sz[par2])
            swap(par1, par2);

        sz[par2]+=sz[par1];
        sz[par1]=0;
        par[par1]=par[par2];
    }
};
DSU dsu;
int queries[N];
pii edges[N];
bool mark[N];
int n;
vector<int> v;

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;

    int testcases;cin>>testcases;
    for(int test=1;test<=testcases;test++)
    {

        cin>>n;
        dsu.init(n);
        v.clear();
        for(int i=0;i<=n;i++)
        {
            mark[i]=0;
        }
        for(int i=1;i<=n-1;i++)
        {
            cin>>edges[i].ff>>edges[i].ss;
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            char ch;
            cin>>ch;
            if(ch=='R')
            {
                cin>>queries[i];
                mark[queries[i]]=1;
            }
            else
            {
                queries[i]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=n-1;i++)
        {
            if(!mark[i])
            {
                if(dsu.getPar(edges[i].ff)!=dsu.getPar(edges[i].ss))
                {
                    ans+=dsu.getSize(edges[i].ff)*dsu.getSize(edges[i].ss);
                    dsu.unite(edges[i].ff,edges[i].ss);
                }
            }
        }
        ans=((n*(n-1))/2)-ans;
        for(int i=q-1;i>=0;i--)
        {
            if(queries[i]==0)
            {
                v.pb(ans);
            }
            else
            {
                if(dsu.getPar(edges[queries[i]].ff)!=dsu.getPar(edges[queries[i]].ss))
                {
                    ans-=dsu.getSize(edges[queries[i]].ff)*dsu.getSize(edges[queries[i]].ss);
                    dsu.unite(edges[queries[i]].ff,edges[queries[i]].ss);
                }
            }
        }
        reverse(all(v));
        for(int &x:v)
        {
            cout<<x<<endl;
        }
        
        if(test!=testcases)
        cout<<endl;
    }
    
    return 0;
}
