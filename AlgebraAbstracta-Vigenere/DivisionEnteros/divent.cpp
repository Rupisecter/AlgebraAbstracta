#include <iostream>
using namespace std;
void divent(int a,int n)
{
  int q,r;
  q=a/n;
  r=a%(q*n);
  if(r<0)
  {
    q-=1;
    r=a-(q*n);
  }
  cout<<"q: "<<q<<endl;
  cout<<"r: "<<r<<endl;
};

int main()
{
  divent(-255,11);
}
