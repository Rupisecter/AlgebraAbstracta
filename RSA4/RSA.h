#include <iostream>
#include <string>
#include <math.h>
#include "matematica.h"
#include <Windows.h>
using namespace std; 

class RSA
{
	public:

		vector<int> numeros;
		string alfabeto;
		NTL::ZZ p, q, n, e, d, phin;
		RSA(int bits);
		vector<NTL::ZZ> generaraleatorio(int bits);
		vector<NTL::ZZ> cypher(string msj);
		vector<int> decypher(vector<NTL::ZZ> cmsj);
		

};
RSA::RSA(int bits)
{
	//vector<long long int> primos = criba2(powl(2, bits) - 1, (powl(2, bits)) / 2);
	numeros = HardwareGen(numeros, bits);

	alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.- abcdefghijklmnopqrstuvwxyz<>*1234567890";
	p = iniciarRC4(numeros, bits);

	numeros = HardwareGen(numeros, bits);

	q = iniciarRC4(numeros, bits);
	n = p*q;
	phin = (p-1)*(q-1);
	cout << p << " " <<endl<< q << " " <<endl<< n << " " <<endl<< phin << " ";
	numeros = HardwareGen(numeros, bits);
	generaraleatorio(bits);
}
vector<NTL::ZZ> RSA::generaraleatorio(int bits)
{
	vector<NTL::ZZ> claveprivada;
	vector<NTL::ZZ>posiblesE=criba(phin);
	e = posiblesE[NTL::conv<int>(modzz(iniciarRC4(numeros, bits),phin))];
	d = inversa(e, phin);
	cout <<"e: "<< e <<" d: "<< d << endl;
	claveprivada.push_back(n);
	claveprivada.push_back(d);
	return claveprivada;
}
vector<NTL::ZZ> RSA::cypher(string msj)
{
	NTL::ZZ res;
	NTL::ZZ indice;
	vector<NTL::ZZ> mensaje;
	for (int i = 0; i < msj.length(); i++)
	{
		indice = NTL::ZZ(alfabeto.find(msj[i]));
		res = expmod(indice,e,n);
		mensaje.push_back(res);
	}
	return mensaje;
}
vector<int> RSA::decypher(vector<NTL::ZZ> cmsj)
 {
	 NTL::ZZ res;
	 vector<int> mensaje;
	 for (int i = 0; i < cmsj.size(); i++)
	 {
		 res = expmod(cmsj[i], d, n);
		 mensaje.push_back(NTL::conv<int>(res));
	 }
	 return mensaje;
 }