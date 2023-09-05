#pragma once

#include <iostream>
#include "universidade.h"
#include "elUniverisdade.h"


class listUniversidade
{
private:
	int numUni;
	int countUni;

	string nome;

	elUniversidade* uAtual;
	elUniversidade* uPrim;
public:

	listUniversidade(int n = -1, string no = "");
	~listUniversidade();

	void setUni(Universidade* uni);
	
	void setName(string no = "");

	void getUnis1();
	void getUnis2();

};

