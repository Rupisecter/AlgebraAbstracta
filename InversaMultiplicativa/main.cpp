#include <iostream>
#include "Inversa.h"

int main() 
{
  int a,b;
  cout<<"Ingrese el numero:";cin>>a;
  cout<<"Ingrese la base:";cin>>b;
  if(a>b)
    cout<<"Datos Incorrectos";
  else
  {
    Inversa inversa(a,b);
    inversa.inversa();
  }  


}