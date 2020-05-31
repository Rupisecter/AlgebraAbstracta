#include <iostream>
#include <string>
using namespace std;

class polybius
{
  public:
  string alfabeto;
  string tabla;
  int ltabla;
  polybius();
  string cypher(string msj);
  string decypher(string cmsj);
};
polybius::polybius()
{
  alfabeto="ABCDEFGHIKLMNOPQRSTUVWXYZ";
  tabla="ABCDE";
  ltabla=tabla.length();
}
string polybius::cypher(string msj)
{
  int aux,aux2,aux3;
  string cmsj;
  for(int i=0;i<msj.length();i++)
  {
    aux=alfabeto.find(msj[i]);
    aux2=aux%ltabla;
    aux3=aux/ltabla;
    cmsj+=tabla[aux3];
    cmsj+=tabla[aux2];
  }
  return cmsj;
}

string polybius::decypher(string cmsj)
{
  int aux,aux2,aux3,aux4;
  string dmsj;
  for(int i=0;i<cmsj.length();i=i+2)
  {
    aux=tabla.find(cmsj[i]);
    aux2=tabla.find(cmsj[i+1]);
    dmsj+=alfabeto[aux*ltabla+aux2];
  }
  return dmsj;
}