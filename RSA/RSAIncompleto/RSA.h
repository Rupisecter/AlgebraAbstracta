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
		string cypher(string msj);
		

};
RSA::RSA()
{
	alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	p = criba(100);
	q = criba(100);
	n = p * q;
	phin = (p - 1) * (q - 1);
	e = criba(phin);

}
NTL::ZZ RSA::generarprivada()
{
	NTL::ZZ d = inversa(e, phin);
	return NTL::conv < NTL::ZZ >("0");
}

string RSA::cypher(string msj)
{
	string temp,dmsj;
	int aux;
	for (int i = 0; i < msj.length(); i++)
	{
		aux = alfabeto.find(msj[i]);
		temp = to_string(mod(pow(aux, e), n));
		dmsj.append(temp);
	}
	return dmsj;
}