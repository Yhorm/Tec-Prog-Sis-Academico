#include "headers/disciplina.h"

Disciplina::Disciplina(std::string nome, std::string area, int id)
{
	Inicializa(nome, area, id);
}

Disciplina::~Disciplina()
{
	dNome = "";
	areaConhecimento = "";
	id = -1;
	depAssociado = NULL;
	dProx = NULL;
	dAnt = NULL;
}

void Disciplina::Inicializa(std::string nome, std::string area, int id)
{
	setName(nome);
	setId(id);
	dProx = NULL;
	dAnt = NULL;
}

void Disciplina::setName(std::string nome)
{
	dNome = nome;
}

string Disciplina::getName()
{
	return dNome;
}
void Disciplina::setProx(Disciplina* prox)
{
	dProx = prox;
}
void Disciplina::setAnt(Disciplina* ant)
{
	dAnt = ant;
}

Disciplina* Disciplina::getProx()
{
	return dProx;
}

Disciplina* Disciplina::getAnt()
{
	return dAnt;
}

void Disciplina::setId(int id)
{
	id = id;
}

int Disciplina::getId()
{
	return id;
}

void Disciplina::setDep(Departamento* dep)
{
	depAssociado = dep;

	depAssociado->setDisciplina(this);
}
Departamento* Disciplina::getDep()
{
	return depAssociado;
}

void Disciplina::setAluno(Aluno* aluno)
{
	objlAlunos.setAluno(aluno);
}

void Disciplina::listAlunos()
{
	objlAlunos.listAlunos();
}

void Disciplina::listAlunos2()
{
	objlAlunos.listAlunos2();
}


void Disciplina::resizeAlunos(int nAlunos)
{
	objlAlunos.resizeAlunos(nAlunos);
	
}