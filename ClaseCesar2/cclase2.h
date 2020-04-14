#include <iostream>
#include <string>
using namespace std;
class Cesar
{
  private:
  int clave, ind;
  string alfabeto;
  public:
  Cesar();
  string cifra(string msg);
  string descifrar(string cmsg);



};

Cesar::Cesar()
{
  alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  clave=3;
}


string Cesar::cifra(string msg)
{
  int tam=alfabeto.length();
  int ax;
  for(int i=0;i<msg.length();i++)
  {
    ind=alfabeto.find(msg[i]);
    ax=ind+clave;
    if(msg[i]==' ')
    {
      msg[i]=alfabeto[ind];
    }
    else
    {
      msg[i]=alfabeto[(ax)%tam];
    }
  }
  return msg;
}

string Cesar::descifrar(string cmsg)
{
  int tam=alfabeto.length();
  int ax;
  for(int i=0;i<cmsg.length();i++)
  {
    ind=alfabeto.find(cmsg[i]);
    ax=ind-clave;
    if(cmsg[i]==' ')
    {
      cmsg[i]=alfabeto[ind];
    }
    else
    {
      cmsg[i]=alfabeto[(ax)%tam];
    }
  }
  return cmsg;
}

