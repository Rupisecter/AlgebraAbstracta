#include <iostream>
#include <string>
#include "monomio.h"
using namespace std;

int main()
{
  Monomio monomio;
  string cmsg,dmsg;
  cmsg=monomio.cypher("PQTUV");
  dmsg=monomio.decypher(cmsg);
  cout<<cmsg<<endl;
  cout<<dmsg;
}