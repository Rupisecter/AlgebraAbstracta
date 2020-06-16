#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
long long int mod(long long int x, long long int y)
{
  long long int r;
  r=x-((x/y)*y);
  if(r<0)
    r=x-(((x/y)-1)*y);
  return r;    
}
long long int expmod(long long int base, long long int exp, long long int n)
{
  vector<long long int>mod_v;
  mod_v.push_back(mod(base, n));

	long long int n1,n2;
	long long int res = mod_v[0];
	long long int i=0,j=1,aux=1;

	while(exp)
	{
		bool binario = mod(exp, 2);
		if(j>1)
		{
			long long int mod_l = mod_v[i];
      long long int temp=pow(mod_l, 2);
			long long int aux = mod(temp, n);
			mod_v.push_back(aux);
			i+=1;
			if(binario)
			{

				n1 = mod(res, n);
				n2 = mod(mod_v[i], n);
				res = mod(n1 * n2, n);
			}
		}
		aux*= 2;
    exp/= 2;
		j+=1;
	}
	return res;
}
int main() {
  cout<<expmod(572,29,713);
}