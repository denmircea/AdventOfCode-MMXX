/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
int prop,nr;
char s[104];
int main()
{
    prop=0;
    while(fin.getline(s,100))
    {
        if(strlen(s)<2)
        {
            if(prop>=7)
            {
                nr++;

            }
            prop=0;
            continue;
        }
        char *tok;
        for(tok=strtok(s," :"); tok!=NULL; tok=strtok(NULL," :"))
        {
            // cout<<tok<<"\n";
            string t;
            t+=tok[0];
            t+=tok[1];
            t+=tok[2];
            tok=strtok(NULL," :");
            if(t[0]!='c')
            {
                if(t=="byr")
                {
                    int an=stoi(tok);
                    if(an>=1920&&an<=2002)
                        prop++;
                    else
                        cout<<t;
                }
                else if(t=="iyr")
                {
                    int an=stoi(tok);
                    if(an>=2010&&an<=2020)
                        prop++;
                    else cout<<t;
                }
                else if(t=="eyr")
                {
                    int an=stoi(tok);
                    if(an>=2020&&an<=2030)
                        prop++;
                        else cout<<t;
                }
                else if(t=="hgt")
                {
                    int l=strlen(tok);
                    int d=stoi(tok);
                    string masura;
                    int j;
                    for( j=0; j<l; j++)
                    {
                        if(tok[j]<'0'||tok[j]>'9')
                            break;
                    }
                    for(; j<l; j++)
                        masura+=tok[j];
                    if(masura=="cm"&&d>=150&&d<=193)
                        prop++;
                    else if(masura=="in"&&d>=59&&d<=76)
                        prop++;
                        else cout<<t;
                }
                else if(t=="hcl")
                {
                    if(tok[0]=='#')
                    {
                        int l=strlen(tok);
                        int ok=0;
                        for(int j=1; j<l; j++)
                        {
                            if( (tok[j]>='0'&&tok[j]<='9') || (tok[j]>='a'&&tok[j]<='z'))
                                ok++;
                        }
                        if(ok==6&&l==7)
                        {
                            prop++;
                        }
                        else cout<<t;
                    }
                }
                else if(t=="ecl")
                {
                    if(
                        strcmp(tok,"amb")==0||
                        strcmp(tok,"blu")==0||
                        strcmp(tok,"brn")==0||
                        strcmp(tok,"gry")==0||
                        strcmp(tok,"grn")==0||
                        strcmp(tok,"hzl")==0||
                        strcmp(tok,"oth")==0
                    )
                        prop++;
                        else cout<<t;
                }
                else if(t=="pid")
                {
                    int ok=0;
                    for(int j=0; j<strlen(tok); j++)
                    {
                        if( (tok[j]>='0'&&tok[j]<='9'))
                            ok++;
                    }
                    if(ok==9&&strlen(tok)==9)
                    {
                        prop++;
                    }
                    else cout<<t;
                }
            }


        }
    }
    cout<<endl<<nr;
}
