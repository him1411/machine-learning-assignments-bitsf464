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

// Function to formulate gaurssian probability distribution
vector<float> gaussian(float mu,float sigmasq,vector<float> test1d)
{
	for (int i = 0; i < test1d.size(); ++i)
	{
		test1d[i] = test1d[i] - mu;
		test1d[i] = test1d[i]*test1d[i];
		test1d[i] = test1d[i] / ( 2*sigmasq);
		test1d[i] = -1*test1d[i];
		test1d[i] = exp(test1d[i]);
		test1d[i] = 0.39894678 * test1d[i];
		test1d[i] = test1d[i] / sqrt(sigmasq); 
	}

	return test1d;
}

// Program to calculate precision,recall and accuracy
int32_t main()
{
    IOS;
    float mu0 = -0.734813608126;
    float sigma0 = 0.057660014683;
    float mu1 = -0.917773065212;
    float sigma1 = 0.073896710032;
    vector<float> v;
    // Pushing predicted values
    for (int i = 0; i < 11895; ++i)
    {
    	float temp;
    	cin>>temp;
    	v.push_back(temp);
    }
    vector<int> trueval;
    // Pushing true values
    for (int i = 0; i < 11895; ++i)
    {
    	int temp;
    	cin>>temp;
    	trueval.push_back(temp);
    }
    
   
    vector<float> ans0 =  gaussian(mu0,sigma0,v);
    vector<float> ans1 = gaussian(mu1,sigma1,v);
    vector<float> final(11895,0);
    // Calculating difference in gaussian outputs
    for (int i = 0; i < 11895; ++i)
    {
    	final[i] = ans1[i]-ans0[i];
    }
    float tp=0,tn=0,fp=0,fn=0;
    // tp -> true and positive
    // fp -> false and positive
    // fn -> false and negative
    // tn -> true and negative
    for (int i = 0; i < 11895; ++i)
    {
    	if (final[i]>0  && trueval[i] ==1)
    		tp++;
    	else if (final[i]>0  && trueval[i] ==0)
    		fp++;
    	else if (final[i]<0  && trueval[i] ==0)
    		tn++;
    	else if (final[i]<0  && trueval[i] ==1)
    		fn++;
    }
    cout<<tp<<" "<<tn<<" "<<fn<<" "<<fp<<endl;
    float precision = tp / (tp + fp);				// Calculating precision
    float recall = tp / ( tp + fn);				// Calculating recall
    float accuracy = ( tp + tn ) / ( tp+ tn + fp + fn);		// Calculating accuracy
    cout<<"precision "<<precision<<endl;
    cout<<"recall "<<recall<<endl;
    cout<<"accuracy % "<<accuracy*100<<endl;
    return 0;
}
