#include <iostream>
#include <string>
#include "monomio.h"
using namespace std;

int main()
{
  Monomio monomio;
  string cmsg,dmsg;
  cmsg=monomio.cypher("DENAR");
  dmsg=monomio.decypher(cmsg);
  cout<<cmsg<<endl;
  cout<<dmsg;
}