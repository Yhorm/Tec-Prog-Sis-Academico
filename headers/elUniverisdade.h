#pragma once

#include <iostream>
#include "universidade.h"


class elUniversidade
{

private:
	Universidade* uni;
	elUniversidade* uProx;
	elUniversidade* uAnt;
public:

	elUniversidade();
	~elUniversidade();
	
	void setUni(Universidade* u);
	void setProx(elUniversidade* prox);
	void setAnt(elUniversidade* ant);

	Universidade* getUni();
	elUniversidade* getProx();
	elUniversidade* getAnt();

	string getName();
};

