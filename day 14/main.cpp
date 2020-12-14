/// BMDesktop
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
string t;
string mask;
map<long long,pair<long long,string> > m,m2;
long long sum,sumtot;
long long aplicare(long long numar,long long valoare,string mask)
{
    vector<int> v;
    long long r=0;
    //cout<<endl;
    //cout<<numar<<" numar"<<endl;
    for(int i=0; i<=35; i++)
    {
        if(mask[35-i]=='X')
        {
            v.push_back(i);
            if((1LL<<i)&numar)
                numar-=(1LL<<i);
        }
    }
    //cout<<numar<<" numar"<<endl;
    long long val=(1LL<<(v.size()));
    val--;
    for(int i=0; i<=val; i++)
    {
        long long nr=numar;

        long long p;
        for(int bit=0; bit<v.size(); bit++)
        {
            /// sunt la bitul bit
            p= (1LL<<v[bit]);
            /// trebuie sa pun valoarea din starea i
            if(p&nr)
            {
                nr-=p;
                if( (1LL<<bit)&i)
                {
                    nr+=p;
                }
            }
            else
            {
                if( (1LL<<bit)&i)
                {
                    nr+=p;
                }
            }
        }
        for(int i=0; i<=35; i++)
        {
            if(mask[35-i]=='1')
            {
                if(nr&(1LL<<i))
                {

                }
                else nr+=(1LL<<i);
            }
        }
        //cout<<nr<<" stare"<<endl;
        m[nr]= {valoare,mask};
    }
    return r;
}
int main()
{
    while(fin>>t)
    {
        if(t=="mask")
        {
            fin>>mask;

        }
        else
        {
            long long loc;
            fin>>loc;
            long long val;
            fin>>val;
            aplicare(loc,val,mask);
        }
    }
//    for(auto it:m){
//        aplicare(it.second.first,it.second.second);
//    }
    for(auto it:m)
    {
        sumtot+=it.second.first;
    }
    cout<<sumtot;
}
