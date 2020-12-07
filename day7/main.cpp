/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
char *param[4000];
char s[4000];
int nr,start;
map<string,int> colors;
int ncolor=0;
int fr[4000];
vector < pair<int,int> > L[4000];
string convertToString(char* a)
{
    int i;
    string s = "";
    int l=strlen(a);
    for (i = 0; i < l; i++)
    {
        s = s + a[i];
    }
    return s;
}
void addmuchie(string bag2,string bag,int number)
{

    if(colors[bag2]==0)
        colors[bag2]=++ncolor;

    if(colors[bag]==0)
        colors[bag]=++ncolor;
    if(bag=="shinygold")
    {
        start=colors[bag];
    }
    //cout<<colors[bag]<<" "<<colors[bag2]<<endl;
    L[colors[bag]].push_back({colors[bag2],number});
}
long long dfs(long long nod)
{
    fr[nod]=1;
    long long rez=0;
    for(auto it:L[nod])
    {

            rez+=it.second*dfs(it.first);

    }

    return rez+1;
}
int main()
{
    while(fin.getline(s,300))
    {
        char *tok;
        int k=0;
        for(tok=strtok(s," ,"); tok!=NULL; tok=strtok(NULL," ,"))
        {
            param[++k]=tok;
        }
        string bag=convertToString(param[1]);
        string aux=convertToString(param[2]);
        if(aux!="bag"&&aux!="bags")
            bag+=aux;
        //cout<<bag<<endl;
        for(int i=5; i+3<=k; i+=4)
        {
            int number=atoi(param[i]);
            string bag2=convertToString(param[i+1]);
            string aux=convertToString(param[i+2]);
            if(aux!="bag"&&aux!="bags")
                bag2+=aux;
            //    cout<<bag2<<" ";
           // cout<<bag2<<" "<<bag<<endl;
            addmuchie(bag2,bag,number);
        }
        // cout<<endl;
    }
    /// dfs din start
    cout<<dfs(start)-1;
    for(auto it:colors)
    {
        // cout<<it.first<<" "<<it.second<<endl;
    }
    // cout<<nr-1;
}
