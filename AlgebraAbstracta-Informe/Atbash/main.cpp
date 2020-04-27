#include <iostream>
#include <string>
using namespace std;

class Atbash
{
  public:
  string abc="abcdefghijklmnopqrstuvwxyz";
  string abc2="zyxwvutsrqponmlkjihgfedcba";
  string cifrar(string msj);
  string descifrar(string msj);


};

string Atbash::cifrar(string msj)
{
  int aux,aux2;
  for(int i=0;i<msj.length();i++)
  {
    aux=abc.find(msj[i]);
    msj[i]=abc2[aux];
  }
  return msj;
}

string Atbash::descifrar(string msj)
{
  int aux,aux2;
  for(int i=0;i<msj.length();i++)
  {
    aux=abc.find(msj[i]);
    msj[i]=abc2[aux];
  }
  return msj;
}

int main() {
  Atbash atbash;
  string msj,cmsj,dmsj;
  getline(cin,msj);
  cmsj=atbash.cifrar(msj);
  dmsj=atbash.descifrar(cmsj);
  cout<<cmsj<<endl;
  cout<<dmsj<<endl;
}