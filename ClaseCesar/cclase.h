#include <iostream>
#include <string>
using namespace std;
class Cesar
{
  private:
  int clave, ind;
  string alfabetoM, alfabetom;
  public:
  Cesar();
  string cifra(string msg);
  string descifrar(string cmsg);
  string getmsg(string &msg);


};

Cesar::Cesar()
{
  alfabetoM="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  alfabetom="abcdefghijklmnopqrstuvwxyz";
  clave=3;
}


string Cesar::cifra(string msg)
{
  for(int i=0;i<msg.length();i++)
  {
    if(isalpha(msg[i]))
    {
      if(isupper(msg[i]))
      {
        ind=alfabetoM.find(msg[i]);
        if((ind+clave)>=26)
        {
          msg[i]=alfabetoM[ind+clave-26];
        }
        else
        {
          msg[i]=alfabetoM[ind+clave];
        }
      }
      if(islower(msg[i]))
      {
        ind=alfabetom.find(msg[i]);
        if((ind+clave)>=26)
        {
          msg[i]=alfabetom[ind+clave-26];
        }
        else
        {
          
          msg[i]=alfabetom[ind+clave];
        }
      }
    }
  }
  return msg;
}

string Cesar::descifrar(string cmsg)
{
  for(int i=0;i<cmsg.length();i++)
  {
    if(isalpha(cmsg[i]))
    {
      if(isupper(cmsg[i]))
      {
        ind=alfabetoM.find(cmsg[i]);
        if((ind-clave)<0)
        {
          cmsg[i]=alfabetoM[ind-clave+26];
        }
        else
        {
          cmsg[i]=alfabetoM[ind-clave];
        }
      }
      if(islower(cmsg[i]))
      {
        ind=alfabetom.find(cmsg[i]);
        if((ind-clave)<0)
        {
          cmsg[i]=alfabetom[ind-clave+26];
        }
        else
        {
          cmsg[i]=alfabetom[ind-clave];
        }
      }
    }
  }
  return cmsg;
}
string Cesar::getmsg(string &msg)
{
  getline(cin,msg);
  return msg;
}

