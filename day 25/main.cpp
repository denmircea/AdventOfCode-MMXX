/// BMDesktop
#include <iostream>
#include <fstream>
#define mod 20201227
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
ofstream fout(nameProb+".out");
long long i,k,d,x=1;
long long lgput(long long a,long long b){
    /// de calculat a la puterea b
    if(b==0)
        return 1;

    if(b%2==0){
        return lgput(a*a%mod,b/2);
    }else{
        return a*lgput(a,b-1)%mod;
    }
}
int main()
{
    fin>>k;
    fin>>d;
    x=1;
    while(x!=k)
    {
        i++;
        x=(x*7)%mod;
    }
    cout<<lgput(d%mod,i);
}
