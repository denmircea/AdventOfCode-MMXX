/// BMDesktop
#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
map< pair< pair<int,int>,pair<int,int>>,int > d;
char s[40];
int numar(int x,int y, int z,int w)
{
    int nr=0;
    for(int i=x-1; i<=x+1; i++)
    {
        for(int j=y-1; j<=y+1; j++)
            for(int k=z-1; k<=z+1; k++)
                for(int t=w-1; t<=w+1; t++)
                {
                    if(i==x&&j==y&&k==z&&t==w)
                        continue;
                    if(nr>5)
                        return nr;
                    if(d.find({{i,j},{k,t}})!=d.end())
                    nr++;
                }
    }
    return nr;
}
int main()
{
    int k=0;
    while(fin>>s)
    {
        for(int i=0; i<strlen(s); i++)
        {
            if(s[i]=='#')
                d[ {{k,0},{i,0}}]=1;
        }
        ++k;
    }
    int st=0;
    int dr=8;
    for(int ciclu=1; ciclu<=6; ciclu++)
    {
        cout<<ciclu<<endl;
        st--;
        dr++;
        map< pair< pair<int,int>,pair<int,int> >,int>  aux;
        for(int i=st; i<=dr; i++)
        {
            for(int j=st; j<=dr; j++)
                for(int k=st; k<=dr; k++)
                {
                    for(int w=st; w<=dr; w++)
                    {
                        if(d.find({{i,j},{k,w}})!=d.end())
                        {
                            /// aici am forma
                            int nrvecini=numar(i,j,k,w);
                            if(nrvecini==2||nrvecini==3)
                            {
                                aux[ {{i,j},{k,w}}]=1;
                            }
                        }
                        else
                        {
                            /// aici am liber
                            int nrvecini=numar(i,j,k,w);
                            if(nrvecini==3)
                            {
                                aux[ {{i,j},{k,w}}]=1;
                            }
                        }
                    }
                }
        }
        d=aux;
        cout<<d.size()<<" :size\n";
    }


    cout<<d.size();

}
