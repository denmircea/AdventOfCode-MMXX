/// BMDesktop
#include <iostream>
#include <fstream>
#include <deque>
#include <map>
#include <unordered_map>
using namespace std;

string nameProb="test";
ifstream fin1(nameProb+"1.in");
ifstream fin2(nameProb+"2.in");
//ofstream fout(nameProb+".out");
int x;
deque<int> q1,q2;
bool lupta(deque<int> &q1,deque<int> &q2)
{
    map<pair<deque<int>,deque<int> >, int > m;
    while(!q1.empty()&&!q2.empty())
    {
        int ok=0;
        bool r;
        if(++m[make_pair(q1,q2)]>1)
        {
            return 0;
        }
        int x;
        int y;
        x=q1.front();
        q1.pop_front();
        y=q2.front();
        q2.pop_front();
        if(ok==0&&q1.size()>=x&&q2.size()>=y)
        {
            ok=1;
            deque<int> q1c(q1.begin(),q1.begin()+x);
            deque<int> q2c(q2.begin(),q2.begin()+y);
            r=lupta(q1c,q2c);
        }
        if(ok==0)
        {
            if(x>y)
            {
                q1.push_back(x);
                q1.push_back(y);
            }
            else
            {
                q2.push_back(y);
                q2.push_back(x);
            }
        }
        else if(ok==1)
        {
            if(r==0)
            {
                q1.push_back(x);
                q1.push_back(y);
            }
            else
            {
                q2.push_back(y);
                q2.push_back(x);
            }
        }
    }
    if(!q1.empty())
        return 0;
    return 1;
}
int main()
{
    while(fin1>>x)
    {
        q1.push_back(x);
    }
    while(fin2>>x)
    {
        q2.push_back(x);
    }
    lupta(q1,q2);
    if(q1.size()==0)
        q1=q2;
    long long sum=0;
    int p=q1.size();
    for(auto it:q1)
    {
        //cout<<it<<" ";
        sum+=it*p;
        p--;
    }
    cout<<sum;
}
