/// BMDesktop
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <list>
#include <set>
using namespace std;

string nameProb="test";
ifstream fin(nameProb+".in");
//ofstream fout(nameProb+".out");
struct nod
{
    nod * next,* ant;
    int val;
    nod(int val)
    {
        this->val=val;
        next=0;
        ant=0;
    }
};
vector<int> v= {3,1,5,6,7,9,8,2,4};
vector<int> test= {3,8,9,1,2,5,4,6,7};
vector< nod* > loc(1000001);
void adaug(nod * & p , int x){
    nod *p2=new nod(x);
    loc[x]=p2;
    p2->next=p;
    p=p2;
}
void afisare(nod *p,int n){
    nod*aux=p;
    for(int i=1;i<=n;i++){
        cout<<aux->val<<" ";
        aux=aux->next;
    }
    cout<<endl;

}
int main()
{
    nod * head=NULL;
    //v=test;
    for(int i=10; i<=1000000; i++)
        v.push_back(i);
    for(auto it=v.rbegin();it!=v.rend();it++)
    {
        adaug(head,*it);
    }
    for(int i=0;i<v.size()-1;i++){
        loc[v[i]]->next=loc[v[i+1]];
        loc[v[i+1]]->ant=loc[v[i]];
    }
    int n=v.size();
    loc[v[0]]->ant=loc[v[n-1]];
    loc[v[n-1]]->next=loc[v[0]];

    auto stanga=head->ant;
    for(int mv=1; mv<=10000000; mv++)
    {
       // cout<<"move "<<mv<<"\n";
       if(mv%500000==0)
        cout<<mv<<endl;
        stanga=stanga->next;
        //afisare(stanga,9);
        set<int> s;
        nod* p1=stanga->next;
        nod* p2=p1->next;
        nod* p3=p2->next;
       // cout<<p1->val<<" "<<p2->val<<" "<<p3->val<<endl;
        s.insert(p1->val);
        s.insert(p2->val);
        s.insert(p3->val);
        stanga->next=p3->next;
        (p3->next)->ant=stanga;
        //afisare(stanga,6);
        int  minn=stanga->val-1;
       // cout<<stanga->val <<endl;
        while(minn>=1&&s.find(minn)!=s.end())
            minn--;
        if(minn<=0)
        {
            minn=v.size();
            while(s.find(minn)!=s.end()||minn==stanga->val)
                minn--;
        }
        //cout<<minn<<" -- minn\n";
        auto itsol=loc[minn];
        /// sa inseram intre itsol si itsol->next
        auto st=itsol;
        auto dr=itsol->next;
//        cout<<st->val<<" "<<dr->val<<endl;
        st->next=p1;
        p1->ant=st;
        p3->next=dr;
        dr->ant=p3;
    }
    afisare(loc[1],3);



}
