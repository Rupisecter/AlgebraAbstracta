// Vigenere.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "clase.h"
using namespace std;

int main()
{
    Vigenere cypher;
    string msg, cmsg, dmsg;
    //msg="Puedo escribir los versos mas tristes esta noche.Escribir, por ejemplo: La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche.Yo la quise, y a veces ella tambien me quiso.";
    getline(cin, msg);
    cmsg = cypher.cifraraqui(msg);
    dmsg = cypher.descifraraqui(cmsg);
    cout << cmsg << endl;
    cout << dmsg << endl;
}