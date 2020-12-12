/// BMDesktop
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
char s[300];
/// nord est sud vest
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
char dirs[]= {'N','E','S','V'};
int d;
int x,y;
int x2=-1,y2=10;
void update(int rot)
{
    int x=d;
    d+=rot;
    d+=10000000;
    d%=4;
    if(rot<0){
        while(rot)
        {
            swap(x2,y2);
            x2=-x2;
            rot++;
        }
    }
    else {
        while(rot)
        {
            swap(x2,y2);
            y2=-y2;
            rot--;
        }
    }

}
int main()
{
    d=1;/// est
    while(fin>>s)
    {
        cout<<x<<" "<<y<<" - ";
        cout<<x2<<" "<<y2<<endl;
        if(strlen(s)<2)
            break;
        char dir=s[0];
        // cout<<s[0]<<endl;
        if(s[0]=='L')
        {
            if(atoi(s+1)%90!=0){
                cout<<"EROARE";
            }
            update(-atoi(s+1)/90);
        }
        else if(s[0]=='R'){
                if(atoi(s+1)%90!=0){
                cout<<"EROARE";
            }
            update(atoi(s+1)/90);
        }
        else if(s[0]=='N')
        {
            x2-=atoi(s+1);
        }
        else if(s[0]=='E')
        {
            y2+=atoi(s+1);
        }
        else if(s[0]=='S')
        {
            x2+=atoi(s+1);
        }
        else if(s[0]=='W')
        {
            y2-=atoi(s+1);
        }
        else if(s[0]=='F')
        {
            if(d%2==1)
            {
                y+=y2*(atoi(s+1));
                // cout<<y<<endl;
                x+=x2*(atoi(s+1));
            }
            else{
                x+=x2*(atoi(s+1));
                y+=y2*(atoi(s+1));
            }
        }

    }
    cout<<x<<" "<<y<<endl;
    cout<<abs(x)+abs(y);

}
