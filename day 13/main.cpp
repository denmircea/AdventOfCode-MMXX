/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
#include "InfInt.h"
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
InfInt t;
char s[40];
int k,k2;
InfInt H[100];
InfInt v[100];
InfInt pos[100],rem[100];

InfInt pow(InfInt a,InfInt b,InfInt mod)
{
    /// de calculat a la puterea b
    if(b==0)
        return 1;

    if(b%2==0)
    {
        return pow(a*a%mod,b/2,mod);
    }
    else
    {
        return a*pow(a,b-1,mod)%mod;
    }
}
InfInt findMinX(InfInt num[],
                InfInt rem[],
                int k)
{
    InfInt p=1;
    for(int i=1; i<=k; i++)
        p=p*rem[i];
    InfInt total=0;
    total=0;
    for(int i=1; i<=k; i++)
    {
        InfInt b=p/rem[i];
        total+=num[i]*b*pow(b,rem[i]-2,rem[i]);
    }
    return total%p;
}

int main()
{
    int i=-1;
    fin>>t;
    while(fin>>s)
    {
        i++;
        if(s[0]=='x')
            continue;
        else
        {
            v[++k]= atoi(s);
            pos[k]=i;
        }
    }

    for(int i=1; i<=k; i++)
    {
        rem[i]=(v[i]-pos[i]);
    }
    for(int i=1; i<=k; i++)
    {
        cout<<v[i]<<" "<<rem[i]<<endl;
    }
    cout<<findMinX(rem,v,k);

}
