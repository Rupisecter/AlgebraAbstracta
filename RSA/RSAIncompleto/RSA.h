#include <iostream>
#include <NTL/ZZ.h>
#include <string>
#include <math.h>
#include "matematica.h"
using namespace std; 

class RSA
{
	public:
		string alfabeto;
		NTL::ZZ p, q, n, e, d, phin;
		RSA();
		NTL::ZZ generarprivada();
		NTL::ZZ cypher(string msj);
		

};
RSA::RSA()
{
	alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	p = 15913;
	q = 89019;
	n = 1416559347;
	phin = 1416454416;
	e = 263209;

}
NTL::ZZ RSA::generarprivada()
{
	NTL::ZZ d = inversa(e, phin);
	return NTL::ZZ(0);
}

NTL::ZZ RSA::cypher(string msj)
{
	string temp,dmsj;
	int aux;
	NTL::ZZ aux2;
	for (int i = 0; i < msj.length(); i++)
	{
		aux = alfabeto.find(msj[i]);
		NTL::ZZ(aux);
		aux2 = NTL::PowerMod(aux, e, n);
	}
	return aux2;
}