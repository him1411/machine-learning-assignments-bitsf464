#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define float long double
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

// Calculating averages of zero and one matrices
int32_t main()
{
    IOS;
    vector<vector<float> > mat1(58),mat0(58);
    int rows = 27750;
    int temp1;
    float temp2;
    for (int i = 0; i <rows ; ++i)
    {
    	cin>>temp1;
    	trace2(i,temp1);
        
        // Pushing values with t=1 
    	if (temp1==1)
    	{
    		for (int j = 0; j < 58 ; ++j)
    		{
    			cin>>temp2;
    			mat1[j].push_back(temp2);
    		}
    	}
        
        // Pushing values with t=0
    	else if (temp1==0)
    	{
    		for (int j = 0; j < 58 ; ++j)
    		{
    			cin>>temp2;
    			mat0[j].push_back(temp2);
    		}
    	}
    }
    
    // Calculating average of zero matrix
    for (int i = 0; i <58 ; ++i)
    {
    	float avg =0;
    	for (int j = 0; j < mat0[i].size() ; ++j)
    	{
    		avg += mat0[i][j];
    	}
    	avg = avg / mat0[0].size();
    	cout<<avg<<endl;
    }
    cout<<endl<<endl;
    
    // Calculating average of one matrix
    for (int i = 0; i <58 ; ++i)
    {
    	float avg =0;
    	for (int j = 0; j < mat1[i].size() ; ++j)
    	{
    		avg += mat1[i][j];
    	}
    	avg = avg / mat1[0].size();
    	cout<<avg<<endl;
    }
    return 0;
}

