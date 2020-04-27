#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Libro
{
  private:
  string a;
  string b;
  string c;
  public:

  void e7a();
  void e7b();
  void e11();
  void e12();
  void e19();
  void e21();
  void e22();
  void ejecutar();
};
void Libro::e7a()
{
  cout<<"18.7.a:\n";
  cout<<"Introduzca una palabra para cifrar"<<endl;
  getline(cin,a);
  b=a;
  for(int i=0;i<a.length();i++)
  {
    if(isalpha(a[i]))
    {
      if(isupper(a[i]))
      {
        a[i]=tolower(a[i]);
      }
      b[i]=a[i]+13;
      if (!(isalpha(b[i])))
      {
        b[i]=b[i]-26;
      }
    }
  }
    cout<<"Palabra: "<<a<<endl;
    cout<<"Cifrado en ROT13: "<<b<<endl;
  c=b;
  e7b();
}
void Libro::e7b()
{
  cout<<"18.7.b:\n";
  for(int i=0;i<c.length();i++)
  {
    if(isalpha(c[i]))
    {
      if(isupper(c[i]))
      {
        a[i]=tolower(c[i]);
      }
      b[i]=c[i]+13;
      if (!(isalpha(b[i])))
      {
        b[i]=b[i]-26;
      }
    }
  }
    cout<<"Palabra: "<<c<<endl;
    cout<<"Descifrado en ROT13: "<<b<<endl;
    cout<<"18.7.c: No sería muy dificil, el cifrado ROT13 es un cifrado César simple asi que solo bastaría con encontrar un patron en la palabra cifrada.\n"<<endl;
}
void Libro::e11()
{
  cout<<"18.11:\n";
  cout<<"Introduzca un nombre:\n";
  getline(cin,a);
  cout<<"Introduzca un apellido:\n";
  getline(cin,b);
  c=a+" "+b;
  cout<<c<<endl; 
}
void Libro::e12()
{
  cout<<"18.12:\n";
  a="algebra";
  string b = a;
  string c;
  for(int i=0;i<b.length();i++)
  {
    b[i]='x';
  }
  for(int j=0;j<6;j++)
  {
    cout<<"\nIntroduzca una letra:\n";
    cin>>c;
    cout<<endl;
    for(int i=0;i<b.length();i++)
    {
      if(c[0]==a[i])
      {
        b[i]=c[0];
      }
    }
    cout<<b<<endl;
  }
  if(b==a)
  {
    cout<<"\nGanaste!\n";
  }
  else
  {
    cout<<"\nPerdiste :c\n";   
  }
}
void Libro::e19()
{
  cout<<"18.19:\n";
  a="computador";
  b="******";
  a.insert((a.length()/2),b);
  cout<<a<<endl;
}
void Libro::e21()
{
  cout<<"18.21:\n";
  a ="Lorem ipsum dolor sit amet, consectetur.Vestibulum, ¿dolor magna?, gravida ane.";
  for(int i=0;i<a.length();i++)
  {
    if (!(isalpha(a[i])))
    {
      a[i]=' ';
    }
  }
  char * pch;
  char temp[a.length()];
  for(int j=0;j<a.length();j++)
  {
    temp[j]=a[j];
  }

  pch = strtok(temp," ");
  while(pch!=NULL)
  {
    cout<<pch<<endl;
    pch= strtok(NULL," ");
  }
}
void Libro::e22()
{
  a="Abstracta";
  cout<<"18.22:\n";
  cout<<"Palabra: "<<a<<endl;
  string::const_iterator iterator= a.end();
  cout<<"Al revés: ";
  while(iterator!=a.begin()-1)
  {
    cout<<*iterator;
    iterator--;
  }
  cout<<endl;
}
void Libro::ejecutar()
{
  e7a();
  e11();
  e12();
  e19();
  e21();
  e22();
}

