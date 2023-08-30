#include "../Tec-Prog-Sis-Academico-master/headers/eldisciplina.h"
#include "../Tec-Prog-Sis-Academico-master/headers/disciplina.h"


elDisciplina::elDisciplina() 
{

}
elDisciplina::~elDisciplina() 
{
}
void elDisciplina::setDisciplina(Disciplina* d)
{
	disciplina = d;
}

Disciplina* elDisciplina::getDisciplina()
{
	return disciplina;
}

string elDisciplina::getDisName()
{
	return disciplina->getName();
}