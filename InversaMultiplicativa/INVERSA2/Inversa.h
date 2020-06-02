#include <iostream>
#include <string>
using namespace std;

class Inversa
{
  public:
  int a, n;
  Inversa(int _a, int _b);
  int mcd(int x, int y);
  int mod(int x,int y);
  void inversa();
  int euclidesext(int x, int y);
};
Inversa::Inversa(int _a, int _b)
{
  a=_a;//Numero
  n=_b;//Zn
}
int Inversa::mod(int x, int y)
{
  int r;
  r=x-((x/y)*y);
  if(r<0)
    r=x-(((x/y)-1)*y);
  return r;    
}
int Inversa::mcd(int x, int y)
{
  int r;
  r=mod(x,y);
  while (r > 0)
  { 
    x=y;
    y=r;
    r = mod(x,y);
  }
  return y;
}
int Inversa::euclidesext(int x,int y)
{
  int q,s,t,r;
  int r1=x,r2=y,s1=1,s2=0,t1=0,t2=1;
  while(r2>0)
  {
    q=r1/r2;
    r=r1-q*r2;
    r1=r2;
    r2=r;

    s=s1-q*s2;
    s1=s2;
    s2=s;

    t=t1-q*t2;
    t1=t2;
    t2=t;
  }
  s=s1;
  t=t1;
  return s;
}
void Inversa::inversa()
{
  if(mcd(a,n)==1)
  {
    int inv=euclidesext(a,n);
    if(mod((inv*a),n)==1)
    {
      if (inv<0)
        inv=mod(inv,n);
      cout<<"El numero "<<a<<" en Z"<<n<<" tiene inversa "<<inv; 
    }
    else
      cout<<"El numero "<<a<<" en Z"<<n<<" no tiene inversa"; 
  }
  else
  {
    cout<<"El numero "<<a<<" en Z"<<n<<" no tiene inversa";
  }
}