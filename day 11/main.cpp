/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
char v[1000][1000];
int fr[1000][1000];
int dx[]= {-1,-1,0,1,1,1,0,-1};
int dy[]= {0,1,1,1,0,-1,-1,-1};
int n,m;
int numar()
{
    int nr=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(v[i][j]=='#')
                nr++;
        }
    return nr;
}
char directia(int x,int y,int nx,int ny)
{
    x+=nx;
    y+=ny;
    while(x>=1&&x<=n&&y>=1&&y<=m)
    {
        if(v[x][y]!='.')
            return v[x][y];
        x+=nx;
        y+=ny;
    }
    return '.';
}
int nrVecini(int i,int j)
{
    int nr=0;
    for(int d=0; d<8; d++)
    {
        char intalnit=directia(i,j,dx[d],dy[d]);
        if(intalnit=='#')
            nr++;
    }
    return nr;
}
bool solve()
{
    bool ok=0;
    memset(fr,0,sizeof(fr));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(v[i][j]=='#'||v[i][j]=='L')
                fr[i][j]=nrVecini(i,j);
        }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(v[i][j]=='#'&&fr[i][j]>=5)
            {
                v[i][j]='L';
                ok=1;
            }
            else if(v[i][j]=='L'&&fr[i][j]==0)
            {
                v[i][j]='#';
                ok=1;
            }
        }
    return ok;
}
int main()
{
    while(fin>>(v[++n]+1));
    n--;
    m=strlen(v[1]+1);
    //cout<<n<<m;
    // cout<<v[1];
    while( solve() )
    {

    }
    for(int i=1; i<=n; i++,cout<<endl)
        for(int j=1; j<=m; j++)
            cout<<v[i][j];
    cout<<numar();
}
