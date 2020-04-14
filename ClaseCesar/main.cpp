#include <iostream>
#include <string>
#include "cclase.h"
using namespace std;

int main() {
  Cesar emisor;
  Cesar receptor;
  string msj, cmsj, dmsj;
  cmsj=emisor.cifra(emisor.getmsg(msj));
  dmsj=receptor.descifrar(cmsj);
  cout<<cmsj<<endl;
  cout<<dmsj<<endl;

}