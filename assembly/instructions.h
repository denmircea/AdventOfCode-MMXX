#include <iostream>
using namespace std;
int ACC(string x)
{
    int val=stoi(x);
    acc+=val;
}
int JMP(string x)
{
    int val=stoi(x);
    i+=val-1;
}
int NOP(string x)
{
    return;
}
