#include <bits/stdc++.h>
#include "Eigen/Dense"
using namespace std;
using namespace Eigen;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define float long double
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define trace1(x)          cerr<<#x<<": "<<x<<endl
#define trace2(x, y)       cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define rev(A) reverse((A).begin(), (A).end())
#define sorv(A) sort((A).begin(), (A).end())
// Program to calculate inverse of LDA  
int32_t main()
{
    IOS;
	Matrix<float, 58, 58> m;
	Matrix<float, 58, 1> m2;
	for (int i = 0; i < 58; ++i)
	{
		for (int j = 0; j < 58; ++j)
		{
			float temp;
			cin>>temp;
			m(i,j) = temp;
		}
	}
	m = m.inverse();
	vector<float> v1,v2;
	// Pushing average of one matrix into v1 
	for (int i = 0; i < 58; ++i)
	{
		float temp;
		cin>>temp;
		v1.push_back(temp);
	}
	// Pushing average of zero matrix into v2
	for (int i = 0; i < 58; ++i)
	{
		float temp;
		cin>>temp;
		v2.push_back(temp);
	}
	// Difference of v1 and v2
	for (int i = 0; i <58 ; ++i)
	{
		m2(i,0) = v1[i] - v2[i];
	}

	Matrix<float, 58, 1> m3 = m * m2;
	// Creating arbitrary vector in direction of Sw inverse* (m2 - m1)
	m3 = 10000*m3;
	Matrix<float, 1, 58> m4 = m3.transpose();
	cout<<fixed<<setprecision(12)<<m4;
	return 0;
}
