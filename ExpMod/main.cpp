#include <iostream>
#include <math.h>
using namespace std;

long long int mod (long long int x,long long int y)
{
    long long int r;
    r = x - ((x / y) * y);
    if (r < 0)
        r = x - (((x / y) - 1) * y);
    return r;
}
long long int expmod(long long int base, long long int exp,long long int zn)
{
  long long int aux=1;
  long long int res=mod(base,zn);
  long long int i=1;
  while(exp)
  {
    if(mod(exp,2))
    {
      aux=mod(aux*res,zn);
    }
    res=mod((res*res),zn);
    zn/=2;  
  }
  return aux;

}
int main() {
  cout<<expmod(57,2,79);
}