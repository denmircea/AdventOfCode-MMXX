/// BMDesktop
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <deque>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
unordered_map<int,pair<int,int> > m;
int k,ant;
int v[10];
int main()
{
    while(fin>>v[++k]);
    k--;
    for(int i=1; i<=k; i++)
        m[v[i]].second=i;
    ant=v[k];
    for(int i=k+1; i<=30000000; i++)
    {
        if(i%1000000==0)
            cout<<1<<"\n";
        if(m[ant].first!=0)
        {
            auto &it=m[ant];
            int x=ant;
            ant=it.second-it.first;
            if(ant==x)
            {
                it.first=it.second;
                it.second=i;
            }
            else
            {
                    m[ant].first=m[ant].second;
                    m[ant].second=i;

            }
        }
        else
        {
            ant=0;
            m[0].first=m[0].second;
            m[0].second=i;
        }
    }
    cout<<ant;
}
