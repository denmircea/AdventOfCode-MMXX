/// BMDesktop
#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
long long x,sol;
deque<long long> v;
bool cauta(int x){
    for(int i=0;i<v.size();i++)
    for(int j=i+1;j<v.size();j++){
        if(v[i]+v[j]==x){
            return 1;
        }
    }
    return 0;
}
int main()
{
    for(int i=1;i<=25;i++){
        fin>>x;
        v.push_back(x);
    }
    while(fin>>x){
        if(cauta(x)==0){
            sol=x;
            break;
        }
        /// verif
        v.push_back(x);
        v.pop_front();
    }
    long long st,dr,sum;
    st=0;
    dr=0;
    sum=v[0];
    while(sum!=sol){
        if(sum<sol){
            dr++;
            sum+=v[dr];
        }
        else if(sum>sol){
            st++;
            sum-=v[st-1];
        }
    }
    long long minn=INT_MAX;
    long long maxx=0;
    for(int i=st;i<=dr;i++){
        minn=min(minn,v[i]);
        maxx=max(maxx,v[i]);
    }
    cout<<minn<<" "<<maxx<<endl;
    cout<<minn+maxx;
}
