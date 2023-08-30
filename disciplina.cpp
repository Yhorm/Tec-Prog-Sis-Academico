#include "../Tec-Prog-Sis-Academico-master/headers/disciplina.h"
#include "../Tec-Prog-Sis-Academico-master/headers/Aluno.h"

Disciplina::Disciplina(std::string nome, std::string area, int id)
{
	Inicializa(nome, area, id);
}

Disciplina::Disciplina()
{
	Inicializa("", "", -1);
}

Disciplina::~Disciplina()
{

	dNome = "";
	areaConhecimento = "";
	id = -1;

	elAluno* aux1 = NULL;
	elAluno* aux2 = NULL;

	aux1 = alunoPrim;

	while (aux1 != NULL)
	{
		aux2 = aux1->alunoProx;
		delete aux1;
		aux1 = aux2;
	}

	depAssociado = NULL;
	alunoAtual = NULL;
	alunoPrim = NULL;
}

void Disciplina::Inicializa(std::string nome, std::string area, int id)
{
	setName(nome);
	setArea(area);
	setId(id);
	alunoAtual = NULL;
	alunoPrim = NULL;
}

void Disciplina::setName(std::string nome)
{
	dNome = nome;
}

string Disciplina::getName()
{
	return dNome;
}

void Disciplina::setArea(std::string area)
{
	areaConhecimento = area;
}

string Disciplina::getArea()
{
	return areaConhecimento;
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