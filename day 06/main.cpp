/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
char s[105];
int fr[200];
int sum,nr;
int pers=0;
int main()
{
    /// fin
    while(fin.getline(s,100))
    {
        if(s[0]<'a')
        {
            for(char i='a'; i<='z'; i++)
            {
                if(fr[i]==pers)
                {
                    sum++;
                }
            }
            nr=0;
            memset(fr,0,sizeof(fr));
            pers=0;
        }
        else
        {
            pers++;
            for(int i=0; i<strlen(s); i++)
            {
                fr[s[i]]++;
            }
        }
    }
    sum+=nr;
    nr=0;
    cout<<sum;
}
