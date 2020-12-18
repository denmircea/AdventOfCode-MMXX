/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
ofstream fout(nameProb+".out");
long long grad1(),grad2(),grad3();
/// grad1 + -
/// grad2 * /
/// grad3 numere 10 11
char s[10000];
long long i;
long long grad1()
{
    long long r=grad3();
    while(s[i]=='+')
    {
        i++;
        if(s[i-1]=='+')
            r+=grad3();
    }
    return r;
}
long long grad2()
{
    long long r=grad1();
    while(s[i]=='*')
    {
        i++;
        if(s[i-1]=='*')
            r*=grad1();
    }
    return r;
}
long long grad3()
{
    long long r=0;
    if(s[i]=='(')
    {
        i++;
        r=grad2();
        i++;
        return r;
    }
    while(s[i]>='0'&&s[i]<='9')
    {
        r=r*10+s[i]-'0';
        i++;
    }
    return r;
}
int main()
{
    long long sum=0;
    while(fin.getline(s,2000))
    {
        long long st=0;
        for(long long i=0;i<strlen(s);i++){
            if(s[i]!=' '){
                s[st++]=s[i];
            }
        }
        s[st]=0;
        if(strlen(s)<2)
        {
            continue;
        }
        i=0;
        sum+=grad2();
    }
    cout<<sum;
}
