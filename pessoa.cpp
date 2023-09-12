#include "headers/pessoa.h"
//CONSTRUTORAS E DESTRUTORA
Pessoa::Pessoa(int dia, int mes, int ano, std::string nome, int i, bool s) :
	Entidade(i, s)
{
	bDay = dia;
	bMonth = mes;
	bYear = ano;
	pName = nome;
	age = -1;
}


Pessoa::~Pessoa() 
{

}

void Pessoa::setName(string nome)
{
	pName = nome;
}

void Pessoa::setBirthdate(int dia, int mes, int ano)
{
	bDay = dia;
	bMonth = mes;
	bYear = ano;

}

//CALCULA A IDADE
void Pessoa::calcAge(int dia, int mes, int ano)
{
	age = ano - bYear;

	if (bMonth < mes)
	{
		--age;
	}
	else if (bMonth == mes)
	{
		if (dia > bDay)
		{
			--age;
		}
	}
}

//RETORNA A IDADE
int Pessoa::getAge()
{
	return age;
}


//RETORNA O NOME
string Pessoa::getName()
{
	return pName;
}

int Pessoa::getBirthday()
{
	return bDay;
}
int Pessoa::getBirthmonth()
{
	return bMonth;
}
int Pessoa::getBirthyear()
{
	return bYear;
}