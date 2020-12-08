/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
map<int,int> fr;
string s[1000],s2[1000],v[1000],v2[1000];
int i,acc;

void ACC(string x)
{
    int val=stoi(x);
    acc+=val;
}
void JMP(string x)
{
    int val=stoi(x);
    i+=val-1;
}
void NOP(string x)
{
    return;
}
void MUL(string x)
{
    int val=stoi(x);
    acc*=val
}
void citire()
{
    k=1;
    while(fin>>v[k]>>v2[k])
        k++;
    k--;
}
void init()
{
    acc=0;
    for(int j=1; j<=k; j++)
    {
        s[j]=v[j];
        s2[j]=v2[j];
    }
}
int solve()
{
    fr.clear();
    for(i=1; i<=k; i++)
    {
        if(fr[i]==1)
        {
            return 0;
        }
        fr[i]++;
        ant=i;
        if(s[i]=="acc")
            ACC(s2[i]);
        else if(s[i]=="jmp")
            JMP(s2[i]);
    }
    return 1;
}
int main()
{
    citire();
    int iter=1;
    while(1)
    {
        init();  /// acc=0 si s=v,s2=v2
        if(solve()==1)
        {
            cout<<acc;
            return 0;
        }
        iter++;
    }


}
