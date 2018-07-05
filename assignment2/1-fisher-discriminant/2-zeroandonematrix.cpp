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

int32_t main()
{
    IOS;
    vector<vector<float> > mat1(30000),mat0(30000);
    int rows = 27750,temp1,mat0size=0,mat1size=0;
    float temp2;
    for (int i = 0; i <rows ; ++i)
    {
        cin>>temp1;
        trace2(i,temp1);
        if (temp1==1)
        {
            for (int j = 0; j < 58 ; ++j)
            {         
                cin>>temp2;
                mat1[mat1size].push_back(temp2);
            }
            mat1size++;
            
        }
        if (temp1==0)
        {   
            for (int j = 0; j < 58 ; ++j)
            {
                cin>>temp2;
                mat0[mat0size].push_back(temp2);
            }
            mat0size++;
        }
    }
    for (int i = 0; i < mat0size; ++i)
    {
        for (int j = 0; j < 58; ++j)
        {
            cout<<fixed<<setprecision(12)<<mat0[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for (int i = 0; i < mat1size; ++i)
    {
        for (int j = 0; j < 58; ++j)
        {
            cout<<fixed<<setprecision(12)<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}