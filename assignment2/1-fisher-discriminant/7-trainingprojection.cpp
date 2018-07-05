#include <bits/stdc++.h>
#include "Eigen/Dense"
using namespace std;
using namespace Eigen;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define float long double
#define ld long double
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define trace1(x)          cerr<<#x<<": "<<x<<endl
#define trace2(x, y)       cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
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

int32_t main()
{
    IOS;
    float temp;
    vector<vector<float> > m(1),mat1(58);
    for (int i = 0; i < 58; ++i)
    {
        cin>>temp;
        m[0].push_back(temp);
    }
    int rows =13609;
    for (int i = 0; i <rows ; ++i)
    {
        for (int j = 0; j < 58 ; ++j)
        {
            float temp2;         
            cin>>temp2;
            mat1[j].push_back(temp2);
        }        
    }
    vector<vector<float>> mat2 = multiply(m,1,58,mat1,rows);
    float sum =0;
    for (int i = 0; i < mat2.size(); ++i)
    {
        for (int j = 0; j < mat2[0].size(); ++j)
        {
            sum = sum + mat2[i][j];
        }
    }
    sum = sum / rows;
    float variance =0;
    for (int i = 0; i < mat2.size(); ++i)
    {
        for (int j = 0; j < mat2[0].size(); ++j)
        {
            float temp = (mat2[i][j]-sum);
            temp = temp*temp;
            variance += temp;
        }
    }
    variance = variance/rows;
    cout<<fixed<<setprecision(12)<<sum<<endl<<variance;
    return 0;
}