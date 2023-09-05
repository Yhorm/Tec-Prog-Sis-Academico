#include "headers/eldisciplina.h"

elDisciplina::elDisciplina() 
{
	disciplina = NULL;
	disProx = NULL;
	disAnt = NULL;
}
elDisciplina::~elDisciplina() 
{
	disciplina = NULL;
	disProx = NULL;
	disAnt = NULL;
}
void elDisciplina::setDisciplina(Disciplina* d)
{
	disciplina = d;
}

void elDisciplina::setProx(elDisciplina* prox)
{
	disProx = prox;
}

void elDisciplina::setAnt(elDisciplina* ant)
{
	disAnt = ant;
}

Disciplina* elDisciplina::getDisciplina()
{
	return disciplina;
}

elDisciplina* elDisciplina::getProx()
{
	return disProx;
}

elDisciplina* elDisciplina::getAnt()
{
	return disAnt;
}

string elDisciplina::getDisName()
{
	return disciplina->getName();
}