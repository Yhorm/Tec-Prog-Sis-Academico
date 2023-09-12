#include "headers/aluno.h"

Aluno::Aluno(int dia, int mes, int ano, std::string nome, int r, int i, bool s) :
	Pessoa(dia, mes, ano, nome)
{
	aDepAfiliado = NULL;
	id = i;
	setRA(r);

}

Aluno::~Aluno()
{
}


void Aluno::setRA(int ra)
{
	RA = ra;
}


int Aluno::getRA()
{
	return RA;
}

void Aluno::setDepAfil(Departamento* dep)
{
	aDepAfiliado = dep;
}

Departamento* Aluno::getDepAfil()
{
	return aDepAfiliado;
}

void Aluno::setDisAfil(Disciplina* dis)
{
	aDiscAfiliado = dis;
}
Disciplina* Aluno::getDisAfil()
{
	return aDiscAfiliado;
}