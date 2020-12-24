/// BMDesktop
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
string nameProb="test";
ifstream fin(nameProb+".in");
map< pair<int,int>,int> m,cpy;
map < string, pair<int,int> > dir;
string s;
int dx[]= {-1,0,1,1,0,-1};
int dy[]= {0, 1,1,0,-1,-1};
void prelucrare(string s)
{
    pair <int,int> poz(0,0);
    string cuv;
    for(auto it:s)
    {
        cuv+=it;
        if(it=='n'||it=='s')
            continue;
        poz.first+=dir[cuv].first;
        poz.second+=dir[cuv].second;
        cuv="";
    }
    if(m[poz]==0)
        m[poz]=1;
    else
        m.erase(m.find(poz));

}
int vecini(int i,int j){
    int nr=0;
    for(int d=0;d<6;d++){
        int ni=i+dx[d];
        int nj=j+dy[d];
        if(m.find({ni,nj})!=m.end())
            nr++;
    }
    return nr;
}
int main()
{
    dir["e"]= {0,1};
    dir["w"]= {0,-1};
    dir["nw"]= {-1,-1};
    dir["ne"]= {-1,0};
    dir["sw"]= {1,0};
    dir["se"]= {1,1};
    while(fin>>s)
    {
        prelucrare(s);
    }

    int st=-20;
    int dr=20;
    for(int day=1; day<=100; day++)
    {
        cout<<day<<endl;
        cpy.clear();
        st--;
        dr++;
        for(int i=st; i<=dr; i++)
        {
            for(int j=st; j<=dr; j++)
            {
                int v=vecini(i,j);
                if(m.find({i,j})!=m.end())
                {
                    /// neagra
                    if(v==0||v>2)
                    {

                    }
                    else
                        cpy[ {i,j}]=1;
                }
                else {
                    if(v==2)
                    cpy[{i,j}]=1;
                }
            }
        }
        m=cpy;
    }
    int nr=0;
    for(auto it:m)
    {
        if(it.second==1)
        {
            nr++;
        }
    }
    cout<<nr;
}
