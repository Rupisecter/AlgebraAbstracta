#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vigenere
{
private:
    string clave;
public:
    string abc;
    Vigenere();
    string cifrarabc(string msj);
    string descifrarabc(string msj);
    string cifraraqui(string msj);
    string descifraraqui(string msj);
    //string cifrarascii(string msj);
};

Vigenere::Vigenere()
{
    abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.:";
    clave = "flaco";
}

string Vigenere::cifrarabc(string msj)
{
    int aux, aux2, aux3;
    for (int i = 0, j = 0; i < msj.length(); ++i, ++j)
    {
        aux = abc.find(msj[i]);
        if (!isalpha(msj[i]))
        {
            msj[i] = abc[aux];
            j--;
        }
        else
        {
            if (islower(msj[i]))
            {
                aux2 = abc.find(clave[j % clave.length()]);
                aux3 = (aux + aux2) % 26;
                msj[i] = abc[aux3];
            }
            else
            {
                aux2 = abc.find(clave[j % clave.length()]);
                aux3 = (aux + aux2) % 53;
                msj[i] = abc[aux3];
            }

        }
    }
    return msj;
}

string Vigenere::descifrarabc(string msj)
{
    int aux, aux2, aux3;
    for (int i = 0, j = 0; i < msj.length(); ++i, ++j)
    {
        aux = abc.find(msj[i]);
        if (!isalpha(msj[i]))
        {
            msj[i] = abc[aux];
            j--;
        }
        else
        {
            if (islower(msj[i]))
            {
                aux2 = abc.find(clave[j % clave.length()]);
                aux3 = (aux - aux2 + 26) % 26;
                msj[i] = abc[aux3];
            }
            else
            {
                aux2 = abc.find(clave[j % clave.length()]);
                aux3 = (aux - aux2 + 53) % 53;
                msj[i] = abc[aux3];
            }

        }
    }
    return msj;
}

/*string Vigenere::cifrarascii(string msj)
{
  int aux2,aux;
  for(int i=0;i<msj.length();++i)
  {
    aux=int(msj[i]);
    if(msj[i]==' ' or msj[i]==',' or msj[i]=='.')
    {
      msj[i]=msj[aux];
    }
    else
    {
      aux2=int(clave[i%clave.length()]);
      cout<<aux<<"     "<<msj[i]<<"     "<<aux2<<"     "<< clave[i%clave.length()]<<"      "<<(aux2+aux+122)%122<<endl;
      msj[i]=(aux2+aux+122)%122  ;
    }
  }
  return msj;
}
*/


string Vigenere::cifraraqui(string msj)
{
    int aux, aux2, aux3;
    string msj2("aqui");
    for (int i = 0, j = 0; i < msj.length(); ++i, ++j)
    {
        if (i % 9 == 0)
        {
            if (i != 0)
            {
                msj.insert(i, msj2);
            }
        }
        aux = abc.find(msj[i]);
        if (!isalpha(msj[i]))
        {
            msj[i] = abc[aux];
            j--;
        }
        else
        {
            if (islower(msj[i]))
            {
                aux2 = abc.find(clave[j % clave.length()]);
                aux3 = (aux + aux2) % 26;
                msj[i] = abc[aux3];
            }
            else
            {
                aux2 = abc.find(clave[j % clave.length()]);
                aux3 = (aux + aux2) % 53;
                msj[i] = abc[aux3];
            }

        }
    }
    while(msj.length()%4!=0)
    {
      msj.append("w");
    }
    return msj;
}

string Vigenere::descifraraqui(string msj)
{
    int aux, aux2, aux3;
    string msj2("aqui");
    while (msj[msj.length()-1] == 'w')
    {
        msj.erase(msj.length()-1, 1);
    }
    for (int i = 0, j = 0; i < msj.length(); ++i, ++j)
    {
        cout << msj[i] << endl;
        aux = abc.find(msj[i]);
        if (i %9 == 0)
        {
            if (i != 0)
            {
                msj.erase(i, 4);
            }
        }
        if (!isalpha(msj[i]))
        {
            msj[i] = abc[aux];
            j--;
        }
        else
        {
            if (islower(msj[i]))
            {
                aux2 = abc.find(clave[j % clave.length()]);
                aux3 = (aux - aux2 + 26) % 26;
                msj[i] = abc[aux3];
            }
            else
            {
                aux2 = abc.find(clave[j % clave.length()]);
                aux3 = (aux - aux2 + 53) % 53;
                msj[i] = abc[aux3];
            }
        }
    }
    return msj;
}