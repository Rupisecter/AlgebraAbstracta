#include <iostream>
#include <string>
using namespace std;

class Practica
{
  private:
  string a;
  string b;
  string c;
  public:
  void practica1();
  void practica3();
  void practica4();
  void practica5();
  void practica6();
  void practica7();
  void practica8();
  void practica9();
  void practica10();
  void practica11();
  void ejecutar();
  
};
void Practica::practica1()
{
  cout<<"Practica Ejercicio 1:\n";
  cout<<"Ingrese una palabra para convertir:\n";
  cin>>a;
  cout<<endl;
  char b[a.length()];
  for(int i=0;i<a.length();i++)
  {
    b[i]=a[i];
  }
  cout<<"\nArray de chars: \n"<<b<<endl;
  cout<<"Practica Ejercicio 2:\nCapacity es el máximo número de caracteres que un string puede mantener sin crecer y size es cuantos caracteres existen en el string.\n";
}
void Practica::practica3()
{
  cout<<"Practica Ejercicio 3:\n";
  cout<<"Ingrese una palabra:\n";
  cin>>a;
  cout<<endl;
  for(int i=0;i<a.length();i++)
  {
    if(isupper(a[i]))
    {
      a[i]=tolower(a[i]);
    }
    else if(islower(a[i]))
    {
      a[i]=toupper(a[i]);
    }    
  }
  cout<<a<<endl;
}

void Practica::practica4()
{
  int n,m;
  cout<<"Practica Ejercicio 4\n";
  cout<<"Ingrese un número:\n";
  cin>>n;
  cout<<"Ingrese un número:\n";
  cin>>m;  
  a=to_string(n);
  b=to_string(m);
  c=a+b;
  cout<<c<<endl;
  n=n*2;
  m=m*2;
  a=to_string(n);
  b=to_string(m);
  c=a+b;
  cout<<c<<endl;
}
void Practica::practica5()
{
  cout<<"Practica Ejercicio 5:\n";
  string ikstr(1000,'a');
  cout<<ikstr<<endl;
}

void Practica::practica6()
{
  cout<<"Practica Ejercicio 6:\n";
  a="Yo desaprobe el curso de Algebra Abstracta";
  cout<<"Inicio: "<<a<<endl;
  b="desaprobe";
  c="aprobe";
  int i=a.find(b);
  a.replace(i,b.length(),c);
  cout<<"Reemplazando: "<<a<<endl;
}
void Practica::practica7()
{
  cout<<"Practica Ejercicio 7:\n";
  int cont=0;
  int found;
  a="Como poco coco como, poco coco compro.";
  cout<<a<<endl;
  cout<<"Introduzca una palabra para buscar en la oración:\n";
  cin>>b;
  found=a.find(b);
  while(found!=string::npos)
  {
    cont++;
    found=a.find(b,found+1);
  }
  cout<<"\nPalabras encontradas: "<<cont<<endl;

}
void Practica::practica8()
{
  cout<<"Practica Ejercicio 8:\n";
  a="Algebra Abstracta";
  for(string::iterator iterador=a.begin();iterador<a.end();iterador++)
  {
    cout<<*iterador<<endl;
  }
}
void Practica::practica9()
{
  cout<<"Practica Ejercicio 9:\n";
  a="gato";
  cout<<"a: "<<a<<endl;
  b="ti";
  cout<<"b: "<<b<<endl;
  a.insert((a.length()/2),b);
  cout<<a<<endl;
}
void Practica::practica10()
{
  cout<<"Practica Ejercicio 10:\n";
  a="Cuando te diga que te creo, no me creas, porque ya no creo lo que creo.";
  cout<<a<<endl;
  cout<<"Introduzca la palabra a reemplazar:\n";
  cin>>b;
  cout<<"\nIntroduzca la nueva palabra:\n";
  cin>>c;
  int i=a.find(b);
  while(i!=string::npos)
  {
    a.replace(i,b.length(),c);
    i=a.find(b,i+1);
  }
  cout<<endl<<a<<endl;

}
void Practica::practica11()
{
  cout<<"Practica Ejercicio 11:\n";
  cout<<"Introduzca 2 palabras para comparar:\n";
  cin>>a;
  cout<<endl;
  cin>>b;
  cout<<"\nPalabras:\n"<<a<<endl<<b<<endl;
  string mayor;
  if(a<b)
  {
    mayor=b;
  }
  else if(b<a)
  {
    mayor=a;
  }
  else
  {
    mayor=a;
  }
  for(int i=0;i<mayor.length();i++)
  {
    if(a[i]<b[i])
    {
      cout<<"Palabra lexicograficamente mayor: "<<b<<endl;
      break;
    }
    else if(b[i]<a[i])
    {
      cout<<"Palabra lexicograficamente mayor: "<<a<<endl;
      break;
    }
  }
}
void Practica::ejecutar()
{
  practica1();
  practica3();
  practica4();
  practica5();
  practica6();
  practica7();
  practica8();
  practica9();
  practica10();
  practica11();
}