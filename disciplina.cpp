#include "disciplina.h"
#include "Aluno.h"

Disciplina::Disciplina(std::string nome, std::string area, int id, int nAlunos)
{
	Inicializa(nome, area, id, nAlunos);
}

Disciplina::Disciplina()
{
	Inicializa("", "", -1, 45);
}

Disciplina::~Disciplina()
{
}

void Disciplina::Inicializa(std::string nome, std::string area, int id, int nAlunos)
{
	setName(nome);
	setArea(area);
	setId(id);
	numAlunos = nAlunos;
	countAlunos = 0;
	alunos.resize(numAlunos);

	for (int i = 0; i < alunos.size(); i++)
	{
		alunos[i] = NULL;
	}
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
	if (countAlunos == alunos.size())
	{
		cout << "TURMA LOTADA." << endl << "STACK OVERFLOW" << endl;
	}
	alunos[countAlunos] = aluno;
	countAlunos++;
}
void Disciplina::listAlunos()
{
	for (int i = 0; i < countAlunos && countAlunos < alunos.size(); i++)
	{
		cout << "Aluno: " << alunos[i]->getName() << endl;
	}
}

void Disciplina::resizeAlunos(int nAlunos)
{
	numAlunos = nAlunos;
	alunos.resize(numAlunos);
}