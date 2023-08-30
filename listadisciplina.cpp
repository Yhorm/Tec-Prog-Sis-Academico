#include "headers/listadisciplina.h"

listaDisciplina::listaDisciplina(int nDis, std::string n) 
{
	countDisciplinas = 0;
	numDisciplinas = nDis;
	nome = n;

	disAtual = NULL;
	disPrim = NULL;
}
listaDisciplina::listaDisciplina() 
{
	countDisciplinas = -1;
	numDisciplinas = -1;
	setNome("");

	disAtual = NULL;
	disPrim = NULL;
}
listaDisciplina::~listaDisciplina() 
{
	countDisciplinas = -1;
	numDisciplinas = -1;
	nome = "";

	elDisciplina* aux1 = disPrim;
	elDisciplina* aux2 = NULL;


	while (aux1 != NULL)
	{
		aux2 = aux1->disProx;
		delete aux1;
		aux1 = aux2;
	}

	disPrim = NULL;
	disAtual = NULL;

}

void listaDisciplina::setNome(std::string n) 
{
	nome = n;
}
void listaDisciplina::setDisciplina(Disciplina* dis)
{
	if (countDisciplinas < numDisciplinas && dis != NULL || numDisciplinas == -1 && dis != NULL)
	{
		elDisciplina* aux = new elDisciplina();

		aux->setDisciplina(dis);

		if (disPrim == NULL)
		{
			disPrim = aux;
			disAtual = aux;
		}
		else
		{
			disAtual->disProx = aux;
			aux->disAnt = disAtual;
			disAtual = aux;
		}
		countDisciplinas++;
	}
	else
	{
		cout << "Disciplina n sera adicionada devido a falta de espaço em: " << endl;
	}

}


void listaDisciplina::listDisciplina() 
{
	elDisciplina* aux = disPrim;

	while (aux != NULL)
	{
		cout << "Disciplina: " << aux->getDisName() << " do departamento " << nome << "." << endl;
		aux = aux->disProx;
	}
}
void listaDisciplina::listDisciplina2() 
{
	elDisciplina* aux = disAtual;

	while (aux != NULL)
	{
		cout << "Disciplina: " << aux->getDisName() << " do departamento " << nome << "." << endl;
		aux = aux->disAnt;
	}
}