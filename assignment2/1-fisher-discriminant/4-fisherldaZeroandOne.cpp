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

vector<vector<ld>> multiply(vector<vector<ld>> &mat1,int mat1row,int mat1col, vector<vector<ld>> &mat2, int mat2col)
{
    vector<vector<ld>> result(mat1row);
    for(int i=0;i<mat1row;i++)
    {	
    	
    	for(int j=0;j<mat2col;j++)
    	{
    		ld x=0;
    		for(int k=0;k<mat1col;k++)
    		{
    			x+=mat1[i][k]*mat2[k][j];
    		}
    		result[i].push_back(x);
    	}
    }
    return result;
}


vector<vector<float>> transpose(vector< vector<float> > vect)
{
    vector< vector<float> > result(vect[0].size());
    for(int i=0;i<vect.size();i++)
    {   
        for(int j=0;j<vect[0].size();j++)
        {
            float x=vect[i][j];
            result[j].push_back(x);  
        }
    }
    return result;
}

int32_t main()
{
    IOS;
    vector<float> avg;
   	vector<vector<float>> trans(58);
   	for (int i = 0; i < 58; ++i)
   	{
   		for (int j = 0; j < 58; ++j)
   		{
   			trans[i].push_back(0);
   		}
   	}
    int row =14140;float temp;
    for (int i = 0; i < 58; ++i)
    {
    	cin>>temp;
    	avg.push_back(temp);
    }
    for (int i = 0; i < row; ++i)
    {
    	vector<vector<float> > zero(1);
    	for (int j = 0; j < 58; ++j)
    	{
    		cin>>temp;
    		zero[0].push_back(temp);
    	}
    	for (int j = 0; j < 58; ++j)
    	{
    		zero[0][j] -= avg[j];
    	}
	    vector<vector<float>> zerot = transpose(zero);
		vector<vector<float>> temp2 = multiply(zerot,58,1,zero,58);
		for (int i = 0; i < 58; ++i)
	   	{
	   		for (int j = 0; j < 58; ++j)
	   		{
	   			trans[i][j] += temp2[i][j];
	   		}
	   	}
	   	zero.clear();
	   	zerot.clear();
	   	temp2.clear();
	}

	
	for (int i = 0; i < 58; ++i)
   	{
   		for (int j = 0; j < 58; ++j)
   		{
   			cout<<fixed<<setprecision(12)<<trans[i][j]<<" ";
   		}
   		cout<<endl;
   	}
    return 0;
}

