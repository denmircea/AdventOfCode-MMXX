/// BMDesktop
#include <iostream>
#include <fstream>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
ofstream fout(nameProb+".out");
int nr,cnt;
char s[350][100];
int res(int col,int lin){
    int cnt=0;
    int nr=0;
    for(int i=1;i<=323;i+=lin){
        cnt%=31;
        if(s[i][cnt]=='#')
            nr++;
        cnt+=col;
    }
    return nr;
}
int main()
{
    /// fin
    cnt=0;
    for(int i=1;i<=323;i++)
    {
        fin>>s[i];
    }
    cout<< 1LL*res(1,1)*res(3,1)*res(5,1)*res(7,1)*res(1,2);
}
