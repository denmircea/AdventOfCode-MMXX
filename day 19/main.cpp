/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
ofstream fout("all.txt");
char *param[20];
int k=0;
char s[200];
int lg;
int a,b;
vector < vector<int> > L[200];
map<int,set<string> >m;
int calc[1000];
bool solve2(string s,string s2,int ok,int nra,int nrb)
{
    if(s==s2&&nrb!=0)
    {
        if(nra>=nrb+1)
            return 1;
        return 0;
    }
    if(s.size()<=s2.size())
        return 0;
    if(ok==0)
    {
        for(auto it:m[42])
        {
            if(s.rfind(s2+it,0)==0)
            {
                if(solve2(s,s2+it,ok,nra+1,nrb))
                    return 1;
            }
        }
    }
    if(1)
    {
        ok=1;
        for(auto it:m[31])
        {
            if(s.rfind(s2+it,0)==0)
            {
                if(solve2(s,s2+it,ok,nra,nrb+1))
                    return 1;
            }
            /// trebuie sa incep sa adaug 32
        }
    }
    return 0;
}
void solve(int rule)
{
    if(calc[rule]==1)
        return;
    calc[rule]=1;
    for(auto v:L[rule])
    {
        for(auto it:v)
            if(calc[it]==0)
            {
                calc[rule]=0;
                return;
            }
    }
    for(auto v:L[rule])
    {
        if(v.size()<2)
        {
            // cout<<rule<<endl;
            m[rule].insert(m[v[0]].begin(),m[v[0]].end());
            continue;
        }
        /// v[0] si v[1]
        for(auto it:m[v[0]])
            for(auto it2:m[v[1]])
            {
                m[rule].insert(it+it2);
            }
    }
}

int main()
{
    while(fin.getline(s,100))
    {
        if(strlen(s)<2)
            break;
        char *tok;
        k=0;
        for(tok=strtok(s," "); tok!=NULL; tok=strtok(NULL," "))
        {
            param[++k]=tok;
        }
        int regula= atoi(param[1]);
        vector<int> aux;
        for(int i=2; i<=k; i++)
        {
            if(strcmp(param[i],"|")==0)
            {
                L[regula].push_back(aux);
                aux.clear();
                continue;
            }
            else if(param[i][0]=='"')
            {
                if(param[i][1]=='a')
                    a=regula;
                else
                    b=regula;
                continue;
            }
            aux.push_back(atoi(param[i]));
        }
        if(aux.size()!=0)
            L[regula].push_back(aux);
    }

    int nr=0;
    m[a].insert("a");
    m[b].insert("b");
    calc[a]=1;
    calc[b]=1;
    while(1)
    {
        bool ok=0;
        for(int rule=1; rule<=199; rule++)
        {
            solve(rule);
            if(calc[rule]==0)
                ok=1;
        }
        if(ok==0)
            break;
    }
    string ss;
//    for(auto it:m[42])
//        cout<<it<<endl;
//    cout<<endl;
//    for(auto it:m[31])
//        cout<<it<<endl;
    while(fin>>ss)
    {
        /// incerc sa potrivesc starile de 42 si cele de 31
        if(solve2(ss,"",0,0,0))
        {
            nr++;
            //fout<<ss<<endl;
        }


    }
    cout<<nr;
}

