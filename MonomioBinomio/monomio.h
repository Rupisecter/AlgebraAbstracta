#include <iostream>
#include <string>
using namespace std;

class Monomio
{
  public:
  string alfabeto;
  
  Monomio();
  string cypher(string msj);
  string decypher(string cmsj);
};

Monomio::Monomio()
{
  alfabeto="D-ENAR-IOSBCFGHJKLMÑPQTUVWXYZ.";
}

string Monomio::cypher(string msj)
{
  string cmsj;
  int aux;
  for(int i=0;i<msj.length();i++)
  {
    aux=alfabeto.find(msj[i]);
    aux++;
    if(aux>20)
      cmsj+="7";
    if(aux>10 && aux<21)
      cmsj+="2"; 
    cmsj+=to_string(aux%10);  
  }
  return cmsj;
}

string Monomio::decypher(string cmsj)
{
  string dmsj;
  for(int i=0;i<cmsj.length();i++)
  {
    if(cmsj[i]=='7')
    {
      dmsj+=alfabeto[cmsj[i+1]+20];
    }
    else if(cmsj[i]=='2')
    {
      dmsj+=alfabeto[cmsj[i+1]+10];
    }
    else
      dmsj+=alfabeto[cmsj[i]];
  }
  return dmsj;
}