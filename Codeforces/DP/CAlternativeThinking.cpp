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

int n,arr[100005],cache[100005][3];

int dp(int i, int state)
{
	if(i==0)
		return 1;

	if(cache[i][state]!=-1)
		return cache[i][state];

	if(state==0)
	{
		cache[i][state]=dp(i-1,0)+(arr[i]!=arr[i-1]);
		return cache[i][state];
	}

	else if(state==1)
	{
		cache[i][state]= max(dp(i-1,0)+(arr[i]==arr[i-1]),dp(i-1,1)+(arr[i]!=arr[i-1]));
		return cache[i][state];
	}

	cache[i][state]= max(dp(i-1,1)+(arr[i]==arr[i-1]),dp(i-1,2)+(arr[i]!=arr[i-1]));
	return cache[i][state];
}

class CAlternativeThinking {
public:
	void solve(istream& cin, ostream& cout) {
		memset(cache,-1, sizeof(cache));
		cin>>n;
		repi(i,0,n)
		{
			char ch;
			cin>>ch;
			arr[i]=ch-'0';
		}
		cout<<max({dp(n-1,0),dp(n-1,1),dp(n-1,2)});
	}
};
