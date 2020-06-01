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
  string aux;
  int aux2;
  int lalf=alfabeto.length();
  for(int i=0;i<cmsj.length();i++)
  {
    if(cmsj[i]=='7')
    {
      aux=cmsj[i+1];
      aux2=stoi(aux);
      dmsj+=alfabeto[(aux2+20%lalf)-1];
      i++;
    }
    else if(cmsj[i]=='2')
    {
      aux=cmsj[i+1];
      aux2=stoi(aux);
      dmsj+=alfabeto[(aux2+10%lalf)-1];
      i++;
    }
    else
    {
      aux=cmsj[i];
      aux2=stoi(aux);
      dmsj+=alfabeto[(aux2%lalf)-1];
    }
  }
  return dmsj;
}