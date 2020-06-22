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
		long long int p, q, n, e, d, phin;
		RSA(int bits);
		vector<long long int> generaraleatorio();
		long long int cypher(string msj);
		long long int decypher(long long int cmsj);
		

};
RSA::RSA(int bits)
{
	vector<long long int> primos = criba2(powl(2, bits) - 1, (powl(2, bits)) / 2);
	alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.- abcdefghijklmnopqrstuvwxyz<>*1234567890";
	p = primos[rand() % primos.size()];
	q = primos[rand() % primos.size()];
	n = p*q;
	phin = (p-1)*(q-1);
}
vector<long long int> RSA::generaraleatorio()
{
	vector<long long int> claveprivada;
	vector<long long int> posiblesE = criba(phin);
	e = posiblesE[rand() % posiblesE.size()];
	d = inversa(e, phin);
	claveprivada.push_back(n);
	claveprivada.push_back(d);
	return claveprivada;
}
 long long int RSA::cypher(string msj)
{
	long long int res;
	for (int i = 0; i < msj.length(); i++)
	{
		res = expmod(msj[i],e,n);
	}
	return res;
}
 long long int RSA::decypher(long long int cmsj)
 {
	 long long int res;
	 for (int i = 0; i < 1; i++)
	 {
		 res = expmod(cmsj, d, n);
	 }
	 return res;
 }