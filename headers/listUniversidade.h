#pragma once

#include <iostream>
#include "universidade.h"
#include "elUniverisdade.h"
#include <fstream>
#include <string>
#include <algorithm>

class listUniversidade
{
private:
	int numUni;
	int countUni;

	string nome;

	elUniversidade* uAtual;
	elUniversidade* uPrim;
public:

	listUniversidade(int n = 100, string no = "");
	~listUniversidade();

	void setUni(Universidade* uni);
	
	void setName(string no = "");

	void listUnis1();
	void listUnis2();

	Universidade* localizar(string n = "");

	void salvarUnis();
	void recuperarUnis();
};

