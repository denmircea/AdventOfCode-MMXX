/// BMDesktop
#include <iostream>
#include <fstream>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
string s;
int maxx;
int fr[2000];
int main()
{
   while(fin>>s){
        int st=0;
        int dr=127;
        for(int i=0;i<7;i++){
            if(s[i]=='F'){
                dr=(st+dr)/2;
            }
            else {
                 st=(st+dr)/2;
            }
        }
        int linie=dr;
        st=0;
        dr=7;
        for(int i=7;i<10;i++){
            if(s[i]=='L'){
                dr=(st+dr)/2;
            }
            else {
                 st=(st+dr)/2;
            }
        }
        int coloana=dr;
        int val=linie*8+coloana;
        fr[val]++;
        maxx=max(val,maxx);
   }
   cout<<maxx<<" partea 1\n";
   for(int i=0;i<=maxx;i++){
    if(fr[i-1]==1&&fr[i+1]==1&&fr[i]==0)
        cout<<i<<" partea 2\n";
   }

}
