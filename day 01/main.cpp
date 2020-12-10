/// BMDesktop
#include <iostream>
#include <fstream>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
ofstream fout(nameProb+".out");
long long v[1000],n;

int main()
{
    while(fin>>v[++n]);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            for(int k=j+1; k<=n; k++)
                if(v[i]+v[j]+v[k]==2020)
                {
                    cout<<v[i]*v[j]*v[k];
                    return 0;
                }


}
