

#include <iostream>
#include <string>
#include "cclase2.h"
using namespace std;

int main() {
  Cesar emisor;
  Cesar receptor;
  string msj, cmsj, dmsj;
  getline(cin,msj);
  cmsj=emisor.cifra(msj);
  dmsj=receptor.descifrar(cmsj);
  cout<<cmsj<<endl;
  cout<<dmsj<<endl;

}