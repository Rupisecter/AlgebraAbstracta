#include <iostream>
#include <math.h>
using namespace std;

void criba(int n)
{
  bool primos[n];
  for(int i=0;i<n;i++)
  {
    primos[i]=false;
  }

  for(int j=2;j*j<=n;j++)
  {
    if(!(primos[j]))
    {
      for(int k=j*j;k<=n;k+=j)
      {
        primos[k]=true;
      }
    }
  }

  for(int l=2;l<=n;l++)
  {
    if(!(primos[l]))
    {
      cout<<l<<" ";
    }
  }
}
int main() 
{ 
  int n; 
  cout<<"Ingrese un numero: ";cin>>n;
  criba(n);
}