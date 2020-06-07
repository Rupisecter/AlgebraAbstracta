#include <iostream>
#include <string>
#include "Afin.h"
using namespace std;
int main()
{
  Afin afin(23);
  string msj;
  cout<<"Introduzca su mensaje: \n";
  getline(cin,msj);
  string cmsg=afin.cypher(msj);
  string dmsg=afin.decypher(cmsg);
  cout<<afin.c2<<endl;
  cout<<cmsg<<endl;
  cout<<dmsg<<endl;
}