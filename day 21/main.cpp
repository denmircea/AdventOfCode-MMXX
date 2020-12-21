/// BMDesktop
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
string s;
map<string,set<string> > reteta;
vector<string> aux;
vector<string> alergeni[100];
vector<string> retetaOriginala[100];
int nr;
int main()
{
    while(fin>>s)
    {
        if(s=="(contains")
        {
            bool ok=1;
            nr++;
            retetaOriginala[nr]=aux;
            while(ok&&fin>>s)
            {
                if(s[s.size()-1]==')')
                {
                    ok=0;
                    s.pop_back();
                }
                if(s[s.size()-1]==',')
                {
                    s.pop_back();
                }
                alergeni[nr].push_back(s);
                /// adaug alergenului tot tot
                set<string> m;
                m.insert(aux.begin(),aux.end());
                set<string> nou;
                if(reteta[s].size()!=0){
                for(auto it:m)
                {
                    if(reteta[s].find(it)!=reteta[s].end())
                    {
                        nou.insert(it);
                    }
                }
                reteta[s]=nou;
                }
                else {
                    reteta[s].insert(aux.begin(),aux.end());
                }
            }
            aux.clear();
        }
        else
        {
           // cout<<s<<endl;
            aux.push_back(s);
        }
    }
    int sum=0;
    map<string,int> fr;
    for(auto it:reteta){
        for(auto it2:it.second){
            fr[it2]=1;
        }
    }
    int ok=1;
    while(ok){
        auto cpy=reteta;
        ok=0;
        for(auto it:cpy){
            if(it.second.size()==1){
                for(auto &it2:reteta){
                    if(it2.second.size()!=1){
                    int sz=it2.second.size();
                    it2.second.erase(*(it.second.begin() ));
                    if(it2.second.size()-sz!=0)
                        ok++;
                    }
                }
            }
        }
    }
    for(auto it:reteta){
        for(auto it2:it.second){
            cout<<it2<<",";
        }
    }
}
