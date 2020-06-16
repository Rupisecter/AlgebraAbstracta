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
		unsigned long long int p, q, n, e, d, phin;
		RSA();
		unsigned long long int generarprivada();
		unsigned long long int cypher(string msj);
		

};
RSA::RSA()
{
	alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	p = 199877;
	q = 175081;
	n = 349946650378;
	phin = 34994290080;
	e = 11;
	//d=15906495491
	

}
unsigned long long int RSA::generarprivada()
{
	unsigned long long int d = inversa(e, phin);
	return d;
}

unsigned long long int RSA::cypher(string msj)
{
	string temp,dmsj;
	unsigned long long int aux2,aux3;
	for (int i = 0; i < msj.length(); i++)
	{
		aux2 = expmod(msj[i],e,n);
	}
	return aux2;
}