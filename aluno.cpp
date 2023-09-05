#include "headers/aluno.h"

//CONSTRUTORAS E DESTRUTORA
Aluno::Aluno(int dia, int mes, int ano, std::string nome, int r, int i) :
	Pessoa(dia, mes, ano, nome)
{
	aDepAfiliado = NULL;
	id = i;
	setRA(r);

}

Aluno::~Aluno()
{
}

//SETA O RA DO ALUNO.
void Aluno::setRA(int ra)
{
	RA = ra;
}

//MOSTRA MAS N RETORNA.
void Aluno::showRA()
{
	cout << pName << " --- RA: "<< RA << endl;
}

//SETA O DEPARTAMENTO EM QUE O ALUNO ESTA ESTUDANDO:
void Aluno::setDepAfil(Departamento* dep)
{
	aDepAfiliado = dep;
}