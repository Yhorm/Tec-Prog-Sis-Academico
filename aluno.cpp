#include "../Tec-Prog-Sis-Academico-master/headers/aluno.h"

//CONSTRUTORAS E DESTRUTORA
Aluno::Aluno(int dia, int mes, int ano, std::string nome, int ra) :
	Pessoa(dia, mes, ano, nome)
{
	aUniMatriculado = NULL;
	aDepAfiliado = NULL;
	setRA(ra);
}

Aluno::Aluno()
{
	aUniMatriculado = NULL;
	aDepAfiliado = NULL;
	setRA(-1);
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

//SETA A UNIVERSIDADE EM QUE O ALUNO ESTA MATRICULADO
void Aluno::setUniAfil(Universidade* pu)
{
	aUniMatriculado = pu;
}

//MOSTRA A UNIVERSIDADE, MAS NÃO A RETORNA.
void Aluno::showUniAfil()
{
	cout << pName << " está matriculado na universidade " << aUniMatriculado->getUniName() << "." << endl;
}

//SETA O DEPARTAMENTO EM QUE O ALUNO ESTA ESTUDANDO:
void Aluno::setDepAfil(Departamento* dep)
{
	aDepAfiliado = dep;
}

//MOSTRA O DEP E A UNIVERSIDADE, MAS NÃO OS RETORNA.
void Aluno::showDepAfil()
{
	cout << pName << " está matriculado na universidade " << aUniMatriculado->getUniName() << " e estuda no departamento " << aDepAfiliado->getDepName() << endl;
}