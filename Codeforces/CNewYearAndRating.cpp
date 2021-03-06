#include <bits/stdc++.h>
#define mod 1000000007ll
#define mod2 100000009ll
#define mod3 998244353
#define pb push_back
#define fastIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define readi(x) scanf("%d",&x)
#define reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define PI 3.141592653589793238462643383
#define repi(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>b;i--)
#define mp make_pair
#define ll long long
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define fi first
#define se second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
int oo = 0x3f3f3f3f;
class CNewYearAndRating {
    int n;
    vector<int> rating,div;
public:
	void solve(istream& cin, ostream& cout) {
	    rating.clear();div.clear();
		cin>>n;
        rating.pb(0);div.pb(0);

        repi(i,0,n){
            int x;cin>>x;
            rating.pb(rating[i]+x);
            cin>>x;
            div.pb(x);
        }

        int maxdiv2rating=-1*oo,mindiv1rating=oo;
        repi(i,1,n+1)
        {
            if(div[i]==2)
                maxdiv2rating=max(maxdiv2rating,rating[i-1]);
            else if(div[i]==1)
                mindiv1rating=min(mindiv1rating,rating[i-1]);
        }
        if(maxdiv2rating>=mindiv1rating)
        {
            cout<<"Impossible";return;
        }
        if(maxdiv2rating==(-1*oo))
        {
            cout<<"Infinity";return;
        }

        cout<<((1899-maxdiv2rating)+rating[n]);


	}
};
