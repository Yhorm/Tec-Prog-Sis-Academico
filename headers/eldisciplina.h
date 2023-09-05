#pragma once

#include <iostream>
#include "disciplina.h"

using namespace std;


class elDisciplina
{
private:
	Disciplina* disciplina;
	elDisciplina* disProx;
	elDisciplina* disAnt;
public:

	elDisciplina();
	~elDisciplina();

	void setDisciplina (Disciplina* d);
	void setProx (elDisciplina* prox);
	void setAnt (elDisciplina* ant);
	
	Disciplina* getDisciplina ();
	elDisciplina* getProx ();
	elDisciplina* getAnt ();

	string getDisName ();
};