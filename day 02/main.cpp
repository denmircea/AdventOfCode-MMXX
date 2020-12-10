/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
ofstream fout(nameProb+".out");
int n,v[1000000];
int fr[1000];
char s[10001];
int r;
char *tok;
char *call[10];
int main()
{
    while(fin.getline(s,1000))
    {
        int k=0;
        for(tok=strtok(s," :-\n"); tok!=NULL; tok=strtok(NULL," :-\n"))
        {
            call[++k]=tok;
        }

        /// in 1 avem param st
        int st=atoi(call[1]);
        int dr=atoi(call[2]);
        st--;
        dr--;
        char c=call[3][0];
        int l=strlen(call[4]);
        bool ok=0;
        if((call[4][st]==c||call[4][dr]==c)&&(call[4][st]!=call[4][dr]))
            ok=1;
        r+=ok;
    }
    cout<<r;
}
