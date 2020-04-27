#include <iostream>
#include <string>
using namespace std;

class Vigenere
{
  private:
  string clave;
  public:
  string abc;
  Vigenere();
  string cifrarabc(string msj);
  string descifrarabc(string msj);
  string cifraraqui(string msj);
  string descifraraqui(string msj);
  //string cifrarascii(string msj);
}; 

Vigenere::Vigenere()
{
  abc="abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
  //clave="Jose Nicolas Palo Zuniga 191-10-44905";
  clave="Cristian Ramos Medina 191-10-44936";
  //clave="Sol Morelia Velasquez Rodriguez 191-10-45003";

}

string Vigenere::cifrarabc(string msj)
{
  int aux,aux2,aux3,tam;
  tam=abc.length();
  for(int i=0,j=0;i<msj.length();++i,++j)
  {
    aux=abc.find(msj[i]);  
    aux2=abc.find(clave[j%clave.length()]);
    aux3=(aux+aux2)%tam;
    msj[i]=abc[aux3];
  }
  return msj;
}

string Vigenere::descifrarabc(string msj)
{
  int aux,aux2,aux3,tam;
  tam=abc.length();
  for(int i=0,j=0;i<msj.length();++i,++j)
  {
    aux=abc.find(msj[i]);  
    aux2=abc.find(clave[j%clave.length()]);
    aux3=(aux-aux2+tam)%tam;
    msj[i]=abc[aux3];
  }
  return msj;
}

string Vigenere::cifraraqui(string msj)
{
  int aux,aux2,aux3;
  string msj2("aqui");
  for(int i=0,j=0;i<msj.length();++i,++j)
  {
    if(i%10==0)
    {
      if(i!=0)
      {
        msj.insert(i,msj2);
      }
    }
    aux=abc.find(msj[i]);  
    if(!isalpha(msj[i]))
    {
      msj[i]=abc[aux];
      j--;
    }
    else
    { 
      if(islower(msj[i]))
      {
        aux2=abc.find(clave[j%clave.length()]);
        aux3=(aux+aux2)%26;
        msj[i]=abc[aux3];
      }
      else
      {
        aux2=abc.find(clave[j%clave.length()]);
        aux3=(aux+aux2)%53;
        msj[i]=abc[aux3];
      }
    }
  }
  while(msj.length()%4!=0)
  {
    msj.append("w");
  }
  return msj;
}

string Vigenere::descifraraqui(string msj)
{
  int aux,aux2,aux3;
  string msj2("aqui");
  for(int i=0,j=0;i<msj.length();++i,++j)
  {
    if(i%10==0)
    {
      if(i!=0)
      {
        msj.erase(i,3);
      }
    }
    aux=abc.find(msj[i]);  
    if(!isalpha(msj[i]))
    {
      msj[i]=abc[aux];
      j--;
    }
    else
    { 
      if(islower(msj[i]))
      {
        aux2=abc.find(clave[j%clave.length()]);
        aux3=(aux-aux2+26)%26;
        msj[i]=abc[aux3];
      }
      else
      {
        aux2=abc.find(clave[j%clave.length()]);
        aux3=(aux-aux2+53)%53;
        msj[i]=abc[aux3];
      }
    }
  }
  while(msj.length()%4!=0)
  {
    msj.erase(msj.length(),1);
  }
  return msj;
}