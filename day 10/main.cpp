/// BMDesktop
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
int v[100000],n,nr,nr3;
long long d[100000];
int main()
{
    while(fin>>v[++n]);
    sort(v+1,v+n+1);
    for(int i=2; i<=n; i++)
    {
        if(v[i]-v[i-1]==1)
        {
            nr++;
        }
        else if(v[i]-v[i-1]==3)
            nr3++;
    }
    v[n+1]=v[n]+3;
    nr3++;
    cout<<nr*nr3<<" part1\n";
    d[n+1]=1;
    for(int i=n; i>=0; i--)
    {
        for(int j=i+1; j<=n+1; j++)
        {
            if(v[j]-v[i]>3)
                break;
            else
                d[i]+=d[j];
        }
    }
    cout<<d[1]<<" part2";
}
