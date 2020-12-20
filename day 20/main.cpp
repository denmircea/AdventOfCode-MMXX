/// BMDesktop
#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <set>
#include <deque>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
ofstream fout(nameProb+".out");
char s[300];
int fr[300];
int N;
set<int> L[300];
map<int,int> m;
int k,id,nr;
int tiles;
char v[400][13][13];
char x[300][300]; /// matricea imagine
int img[20][20];/// aici id urile
int b[300][6];
int aux[5];
map<int,int> borders,bord;
string monster[3];
bool verif(int id1,int id2)
{
    //    cout<<id1<<" "<<id2<<endl;
    if(id1==0||id2==0)
        return 1;
    int ok=0;
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
        {
            if(b[id1][i]==b[id2][j])
                ok++;
        }
    if(ok>=1)
        return 1;
    return 0;

}
//void backtr(int x,int y)
//{
//    if(x==12)
//    {
//        for(int i=1; i<=12; i++,cout<<endl)
//            for(int j=1; j<=12; j++)
//                cout<<img[i][j]<<" ";
//        cout<<"gata";
//        exit(0);
//        return;
//    }
//
//    for(int pas=1; pas<=tiles; pas++)
//    {
//        if(fr[pas]==0)
//        {
//            fr[pas]=1;
//            img[x][y]=pas;
//            int nx,ny;
//            if(y==12)
//            {
//                nx=x+1;
//                ny=1;
//            }
//            else
//            {
//                nx=x;
//                ny=y+1;
//            }
//            // if(x>1&&y>2)
//            //   cout<<x<<" "<<y<<endl;
//            if(L[ pas ].find(img[x-1][y])!=L[pas].end()&&
//                    L[ pas ].find(img[x][y-1])!=L[pas].end())
//            {
//                backtr(nx,ny);
//            }
//            fr[pas]=0;
//        }
//    }
//}
void borduri(int id,int r[])
{
    int p=1;
    r[1]=r[2]=r[3]=r[4]=0;
    aux[1]=aux[2]=aux[3]=aux[4]=0;
    int p2=512;
    for(int i=0; i<10; i++)
    {
        if(v[id][i][0]=='#')
            r[1]+=p;
        if(v[id][0][i]=='#')
            r[2]+=p;
        if(v[id][i][9]=='#')
            r[3]+=p;
        if(v[id][9][i]=='#')
            r[4]+=p;
        p*=2;
        if(v[id][i][0]=='#')
            aux[1]+=p2;
        if(v[id][0][i]=='#')
            aux[2]+=p2;
        if(v[id][i][9]=='#')
            aux[3]+=p2;
        if(v[id][9][i]=='#')
            aux[4]+=p2;
        p2/=2;
    }
    for(int i=1; i<=4; i++)
    {
        r[i]=min(r[i],aux[i]);
        borders[r[i]]++;
    }

}
void vertical(int id)
{
    for(int i=0; i<10; i++)
        for(int j=0; j<5; j++)
        {
            swap(v[id][i][j],v[id][i][10-j-1]);
        }
}
void orizontal(int id)
{
    for(int i=0; i<5; i++)
        swap(v[id][i],v[id][10-i-1]);
}
void afisare(int id)
{
    for(int i=0; i<10; i++,cout<<endl)
        for(int j=0; j<10; j++)
        {
            cout<<v[id][i][j];
        }
    cout<<endl;
    cout<<endl;


}
void transpusa(int id)
{
    for(int i=0; i<10; i++)
        for(int j=0; j<i; j++)
            swap(v[id][i][j],v[id][j][i]);
}
void bfs(int x,int y,int nod)
{
    deque< pair<int,int> > q;
    q.push_back({x,y});
    fr[nod]=1;
    img[x][y]=nod;
    fr[0]=1;
    while(q.size())
    {
        auto f=q.front();
        q.pop_front();
        x=f.first;
        y=f.second;
        if(x+1<=12)
        {
            /// in jos
            if(img[x+1][y]==0)
                for(auto it:L[img[x][y]])
                {
                    if(fr[it]==0&&L[img[x+1][y-1]].find(it)!=L[img[x+1][y-1]].end())
                    {
                        img[x+1][y]=it;
                        fr[it]=1;
                        q.push_back({x+1,y});
                        break;
                    }
                }
        }
        if(y+1<=12)
        {

            if(img[x][y+1]==0)
                for(auto it:L[img[x][y]])
                {
                    if(fr[it]==0&&L[img[x-1][y+1]].find(it)!=L[img[x-1][y+1]].end())
                    {
                        img[x][y+1]=it;
                        fr[it]=1;
                        q.push_back({x,y+1});
                        break;
                    }
                }
        }
    }
}
bool fit(int x1,int y1,int x2,int y2)
{
    if(x2<x1)
    {
        swap(x1,x2);
    }
    if(y2<y1)
    {
        swap(y2,y1);
    }
    if(y1!=y2)
    {
        /// stanga dreapta
        int ok= 1;
        int id1=img[x1][y1];
        int id2=img[x2][y2];
        for(int i=0; i<10; i++)
        {
            if(v[id1][i][9]!=v[id2][i][0])
            {
                ok=0;
                break;
            }
        }
        return ok;
    }
    if(x1!=x2)
    {
        /// sus jos
        int ok=1;
        int id1=img[x1][y1];
        int id2=img[x2][y2];
        for(int i=0; i<10; i++)
        {
            if(v[id1][9][i]!=v[id2][0][i])
            {
                ok=0;
                break;
            }
        }
        return ok;
    }
}
void rotire(int id,int rot)
{
    if(rot==4)
    {
        orizontal(id);
        transpusa(id);

    }
    if(rot>=4)
        rot-=4;
    if(rot==0)
        return;
    if(rot==1)
    {
        vertical(id);
    }
    if(rot==2)
    {
        orizontal(id);
    }
    if(rot==3)
    {
        vertical(id);
    }

}
void mutare(int x1,int y,int n,int m)
{
    x1--;
    y--;
    for(int i=x1*8; i<x1*8+n; i++)
        for(int j=y*8; j<y*8+m; j++)
        {
            x[i][j]=v[img[x1+1][y+1]][i%n+1][j%m+1];
        }
}
bool matchMonster(int x1,int y1){
    for(int i=0;i<3;i++)
    for(int j=0;j<monster[0].size();j++){
        if(monster[i][j]=='#' && x[x1+i][y1+j]!='#'){
            return 0;
        }
    }
    return 1;
}
/// ---
void transpusap2()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N/2; j++)
            swap(x[i][j],x[j][i]);
}
void verticalp2()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N/2; j++)
        {
            swap(x[i][j],x[i][N-j-1]);
        }
}
void orizontalp2()
{
    for(int i=0; i<N/2; i++)
        swap(x[i],x[N-i-1]);
}

void rotirepart2(int rot)
{
    if(rot==4)
    {
        orizontalp2();
        transpusap2();

    }
    if(rot>=4)
        rot-=4;
    if(rot==0)
        return;
    if(rot==1)
    {
        verticalp2();
    }
    if(rot==2)
    {
        orizontalp2();
    }
    if(rot==3)
    {
        verticalp2();
    }
}
int main()
{
    while(fin>>s)
    {
        if(strcmp(s,"Tile")==0)
        {
            fin>>s; ///id
            id=atoi(s);
            //cout<<id<<endl;
            if(m[id]==0)
                m[id]=++tiles;
            id=m[id];
            k=0;
            nr++;
        }
        else
        {
            strcpy(v[id][0],s);
            for(int k=1; k<10; k++)
                fin>>v[id][k];
        }
    }

    for(int i=1; i<=tiles; i++)
    {
        borduri(i,b[i]);
    }
    for(int i=1; i<=tiles; i++)
    {
        int cnt=0;
        for(int j=1; j<=4; j++)
        {
            if(borders[b[i][j]]==1)
                cnt++;
        }
        if(cnt!=0&&cnt<=2)
        {
            L[i].insert(0);
            L[0].insert(i);
        }
        if(cnt==2)
        {
            //  cout<<i<<endl;
        }
    }

    // cout<<L[0].size()<<endl;
    for(int i=1; i<=tiles; i++)
        for(int j=i+1; j<=tiles; j++)
            if(verif(i,j))
            {
                // cout<<i<<" "<<j<<endl;
                L[i].insert(j);
                L[j].insert(i);
            }
    bfs(1,1,11);
//    for(int i=1; i<=12; i++,cout<<endl)
//    {
//        for(int j=1; j<=12; j++)
//        {
//            cout<<img[i][j]<<" ";
//        }
//    }
    vertical(11);

    for(int i=1; i<=12; i++)
        for(int j=1; j<=12; j++)
        {
            if(i==1&&j==1)
                continue;
            int rot;
            for(rot=0; rot<8; rot++)
            {
                rotire(img[i][j],rot);
                if(i==1)
                {
                    if(fit(i,j-1,i,j))
                        break;
                }
                else
                {
                    if(fit(i-1,j,i,j))
                        break;
                }
            }

        }
    for(int i=1; i<=12; i++)
    {
        for(int j=1; j<=12; j++)
        {
            mutare(i,j,8,8);
        }
    }
//    for(int i=0; i<9*12-11; i++,cout<<endl)
//        for(int j=0; j<9*12-11; j++)
//            cout<<x[i][j];
    N=8*12;
    monster[0]="                  # ";
    monster[1]="#    ##    ##    ###";
    monster[2]=" #  #  #  #  #  #   ";
    for(int rot=0; rot<8; rot++)
    {
        rotirepart2(rot);
        if(rot==0)
        for(int i=0;i<N;i++,fout<<endl)
            for(int j=0;j<N;j++)
                fout<<x[i][j];
        int nr=0;
        for(int i=0; i+3<N; i++)
            for(int j=0; j+monster[1].size()<N; j++)
            {
                nr+=matchMonster(i,j);
            }
        if(nr!=0){
        cout<<nr<<endl;
        int cntdiez=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                if(x[i][j]=='#')
                    cntdiez++;
            }
        cout<<cntdiez-nr*15<<endl;
        return 0;
        }

    }


}
