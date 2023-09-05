#include "headers/pessoa.h"
//CONSTRUTORAS E DESTRUTORA
Pessoa::Pessoa(int dia, int mes, int ano, std::string nome)
{
	Inicializa(dia, mes, ano, nome);
}


Pessoa::~Pessoa() {}

void Pessoa::Inicializa(int dia, int mes, int ano, std::string nome)
{
	bDay = dia;
	bMonth = mes;
	bYear = ano;
	pName = nome;
	age = -1;
}

void Pessoa::setName(string nome)
{
	pName = nome;
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
//MOSTRA A IDADE, MAS N�O RETORNA
void Pessoa::printAge()
{
	std::cout << "a idade de " << pName << " ";
	printf("eh: %d\n", age);
	std::cout << "\n";
}

//MOSTRA A DATA DE NASCIMENTO, MAS N�O A RETORNA
void Pessoa::printBirthdate()
{
	std::cout << "A data de nascimento de " << pName << " ";
	printf("eh: %d/%d/%d\n", bDay, bMonth, bYear);
	std::cout << "\n";
}
//MOSTRA O NOME, MAS N�O O RETORNA
void Pessoa::printName()
{
	std::cout << "O nome da pessoa eh: " << pName << "\n";
	std::cout << "\n";
}

//RETORNA A IDADE
int Pessoa::getAge()
{
	return age;
}
//RETORNA A DATA DE NASCIMENTO NO FORMADO DDMMYYYY
int Pessoa::getBirthdate()
{
	return (bDay, bMonth, bYear);
}
//RETORNA O NOME
string Pessoa::getName()
{
	return pName;
}