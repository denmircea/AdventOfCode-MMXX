/// BMDesktop
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
string as,bs,cs,ds,s;
int lin;
vector < pair <pair<int,int>, pair<int,int> > > v;
vector <int> my;
set <int> L[30];
int pos[100];
int a,b,c,d;
int fr[100];
int mat[1000][30];
bool valid2(int a)
{
    for(auto x:v)
    {
        if(a>=x.first.first&&a<=x.first.second)
            return 1;
        if(a>=x.second.first&&a<=x.second.second)
            return 1;
    }
    return 0;
}
bool valid(int a, pair <pair<int,int>, pair<int,int> > x)
{
    if(a>=x.first.first&&a<=x.first.second)
        return 1;
    if(a>=x.second.first&&a<=x.second.second)
        return 1;
    return 0;
}
void verif(int val)
{
    int i;
    int cnt=0;
    for(int j=0; j<20; j++,cnt=0)
    {
        for(i=1; i<=lin; i++)
        {
            if(mat[i][j]>0&&valid(mat[i][j],v[val])==0)
            {
                cnt++;
            }
        }
        if(cnt==0)
            L[val].insert(j);
    }
}
int main()
{
    while(fin>>s)
    {
        if(s=="your")
        {
            break;
        }
        if(s==":")
        {
            /// citesc proprietati
            fin>>as>>bs>>s>>cs>>ds;
            a=stoi(as);
            b=stoi(bs);
            c=stoi(cs);
            d=stoi(ds);
            v.push_back({{a,b},{c,d}});
        }
    }
    /// your
    fin>>s; /// ticket
    fin>>s; /// :
    while(fin>>s)
    {
        if(s=="nearby")
        {
            break;
        }
        a=stoi(s);
        my.push_back(a);
    }
    /// nearby
    fin>>s;
    fin>>s;
    int nr=0;
    lin=1;
    int cnt=0;
    while(fin>>s)
    {

        a=stoi(s);
        if(valid2(a)==0)
            a=-1;
        mat[lin][cnt%20]=a;
        cnt++;
        if(cnt%20==0)
        {
            lin++;
        }
    }
    for(int i=0; i<20; i++)
    {
        mat[lin][i]=my[i];
    }
    for(int j=0; j<20; j++)
    {
        verif(j);
    }
    for(int i=0; i<20; i++)
    {
        cout<<i<<": ";
        for(auto it:L[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    while(1)
    {
        bool ok=0;
        for(int i=0; i<20; i++)
        {
            /// il caut pe i
            for(int j=0; j<20; j++)
            {
                /// verific daca in apare o singura data i
                if(L[i].size()==0)
                    continue;
                if(L[i].size()==1&&*(L[i].begin())==j)
                {
                    pos[i]=j;
                    cout<<i<<" "<<j<<endl;
                    ok=1;
                    for(int k=0; k<20; k++)
                    {
                        L[k].erase(j);
                    }
                }
            }
        }
        if(ok==0)
            break;
    }

    long long p=1;
    for(int i=0; i<6; i++)
    {
        p*=my[pos[i]];
    }
    cout<<p;

}
