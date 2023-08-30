#pragma once

#include <iostream>

class Disciplina;

using namespace std;


class elDisciplina
{
private:
	Disciplina* disciplina;
public:
	elDisciplina* disProx;
	elDisciplina* disAnt;

	elDisciplina();
	~elDisciplina();
	void setDisciplina (Disciplina* d);
	Disciplina* getDisciplina ();
	string getDisName ();
};