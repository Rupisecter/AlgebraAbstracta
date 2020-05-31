#include<iostream>
#include <string>
#include "polybius.h"
using namespace std;
int main()
{
  polybius polybios;
  string cmsg,dmsg;
  cmsg=polybios.cypher("HOLA");
  dmsg=polybios.decypher(cmsg);
  cout<<cmsg<<endl;
  cout<<dmsg<<endl;
}