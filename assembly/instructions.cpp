#include <string>
using namespace std;
extern int acc;
extern int i;
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
void NOP(string x)
{
    return;
}
