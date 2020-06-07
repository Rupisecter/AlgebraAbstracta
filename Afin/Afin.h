#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Afin
{
  public:
  string alf;
  int c,zn,c2;

  Afin(int _c);
  int mod(int x,int y);
  int mcd(int x, int y);
  int euclidesext(int x,int y);
  int inversa(int x,int y);
  string cypher(string msj);
  string decypher(string cmsj);
};

Afin::Afin(int _c)
{
  alf="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
  c=_c;
  zn=alf.length();
  c2=mod(rand() % 100,zn);
}
int Afin::mod(int x,int y)
{
  int r;
  r=x-((x/y)*y);
  if(r<0)
    r=x-(((x/y)-1)*y);
  return r; 
}
int Afin::mcd(int x,int y)
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
int Afin::euclidesext(int x,int y)
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
int Afin::inversa(int x,int y)
{
  if(mcd(x,y)==1)
  {
    int inv=euclidesext(x,y);
    if(mod((inv*x),y)==1)
    {
      if (inv<0)
        inv=mod(inv,y);
      return inv;
    }
  }
  else
    return 0;
}
string Afin::cypher(string msj)
{
  int aux,aux2;
  string cmsj;
  for(int i=0;i<msj.length();i++)
  {
    aux=alf.find(msj[i]);
    aux2=mod(((c*aux)+c2),zn);
    cmsj+=alf[aux2];
  }
  return cmsj;
}

string Afin::decypher(string cmsj)
{
  int aux,aux2,aux3;
  string dmsj;
  aux=inversa(c,zn);
  if(!aux)
    return 0;
  for(int i=0;i<cmsj.length();i++)
  {
    aux2=alf.find(cmsj[i]);
    aux3=mod(aux*(aux2-c2),zn);
    dmsj+=alf[aux3];
  }
  return dmsj;
}