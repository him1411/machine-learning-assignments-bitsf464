#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define float long double
#define ld long double
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define trace1(x)          cerr<<#x<<": "<<x<<endl
#define trace2(x, y)       cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define INF 10000000000000007ll
#define MOD 1000000007ll
#define PI 3.14159265359
#define rev(A) reverse((A).begin(), (A).end())
#define sorv(A) sort((A).begin(), (A).end())


int32_t main()
{
    IOS;
    vector<vector<float> > zero(58),one(58),result(58);

    for (int i = 0; i < 58; ++i)
    {
    	for (int j = 0; j < 58; ++j)
    	{
    		float temp;
    		cin>>temp;
    		zero[i].push_back(temp);
    	}
    }

    for (int i = 0; i < 58; ++i)
    {
    	for (int j = 0; j < 58; ++j)
    	{
    		float temp;
    		cin>>temp;
    		one[i].push_back(temp);
    	}
    }
    for (int i = 0; i < 58; ++i)
    {
    	for (int j = 0; j < 58; ++j)
    	{
    		float temp;
    		temp = zero[i][j] + one[i][j];
    		result[i].push_back(temp);
    	}
    }


    for (int i = 0; i < 58; ++i)
    {
    	for (int j = 0; j < 58; ++j)
    	{
    		cout<<fixed<<setprecision(12)<<result[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}