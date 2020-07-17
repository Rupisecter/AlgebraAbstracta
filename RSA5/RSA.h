#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "matematica.h"
#include <Windows.h>
using namespace std; 
using namespace NTL;
class RSA
{
	public:

		vector<int> numeros;
		string alfabeto;
		NTL::ZZ p, q, n, e, d, phin;
		RSA(int bits);
		vector<NTL::ZZ> generaraleatorio(int bits);
		string cypher(string msj);
		string decypher(string cmsj);
		string ZZtoString(NTL::ZZ a);		
		NTL::ZZ StringtoZZ(string b);


};
RSA::RSA(int bits)
{
	//vector<long long int> primos = criba2(powl(2, bits) - 1, (powl(2, bits)) / 2);
	numeros = HardwareGen(numeros, bits);

	alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.- abcdefghijklmnopqrstuvwxyz<>*1234567890";
	p = iniciarRC4(numeros, bits);

	numeros = HardwareGen(numeros, bits);

	q = iniciarRC4(numeros, bits);
	n = p * q;
	phin = (p - 1) * (q - 1);
	cout << p << " " << endl << q << " " << endl << n << " " << endl << phin << " ";
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
string RSA::ZZtoString(NTL::ZZ a)
{
	stringstream numerostring;
	numerostring << a;
	return numerostring.str();
}
ZZ RSA::StringtoZZ(string a)
{
	ZZ zz_(NTL::INIT_VAL, a.c_str());
	return zz_;
}

string RSA::cypher(string msj)
{
	NTL::ZZ res;
	NTL::ZZ indice;
	vector<NTL::ZZ> mensaje;
	string msjcifrado;
	for (int i = 0; i < msj.length(); i++)
	{
		indice = NTL::ZZ(alfabeto.find(msj[i]));
		res = expmod(indice,e,n);
		mensaje.push_back(res);
		msjcifrado.append(ZZtoString(mensaje[i]));

	}
	return msjcifrado;
}
string RSA::decypher(string cmsj)
 {
	 ZZ res=StringtoZZ(cmsj);
	 string dmsj;
	 cout <<endl<<"res: " <<res<<endl;
	 //for (int i = 0; i < cmsj.length(); i++)
	 //{
		 res = expmod(res, d, n);
		 dmsj.append(ZZtoString(res));
	 //}
	 return dmsj;
 }