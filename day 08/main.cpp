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
int ac,i,k,iter=1;
int acc(int x)
{
    ac+=x;
}
int jmp(int x)
{
    i+=x-1;
}
int main()
{
    int ant;
    k=1;
    while(fin>>v[k]>>v2[k])
        k++;
    k--;
    while(1)
    {
        ac=0;
        for(int j=1;j<=k;j++){
            s[j]=v[j];
            s2[j]=v2[j];
        }
        fr.clear();
        while(s[iter]=="acc"&&iter<=k)
            iter++;
        if(iter>k)
            break;
        if(s[iter]=="jmp")
            s[iter]="nop";
        else
            s[iter]="jmp";
        for(i=1; i<=k; i++)
        {

            if(fr[i]==2)
            {
                /// part1 -  de modificat iter
              //  cout<<ac<<endl;

                break;
            }
            fr[i]++;
            ant=i;
            if(s[i]=="acc")
                acc(stoi(s2[i]));
            else if(s[i]=="jmp")
                jmp(stoi(s2[i]));

        }
        if(i>k)
        {
            cout<<ac;
            return 0;
        }
        iter++;
    }


}
