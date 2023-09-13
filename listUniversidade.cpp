#include "headers/listUniversidade.h"

listUniversidade::listUniversidade(int n , string no)
{
	countUni = 0;
	numUni = n;
	nome = no;
	
	uPrim = NULL;
	uAtual = NULL;
}
listUniversidade::~listUniversidade()
{
	countUni = 0;
	numUni = -1;
	nome = " ";

	elUniversidade* aux1;
	elUniversidade* aux2;

	aux1 = uPrim;
	aux2 = aux1;

	while (aux1 != NULL)
	{
		aux2 = aux1->getProx();
		delete aux1;
		aux1 = aux2;
	}

	uPrim = NULL;
	uAtual = NULL;
}

void listUniversidade::setUni(Universidade* uni)
{
	elUniversidade* aux; 
	aux = new elUniversidade();
	
	aux->setAnt(NULL);
	aux->setProx(NULL);
	
	if (countUni < numUni && uni != NULL || numUni == -1 && uni != NULL)
	{
		aux->setUni(uni);
		if (uPrim == NULL)
		{
			uPrim = aux;
			uAtual = aux;
		}
		else
		{
			uAtual->setProx(aux);
			aux->setAnt(uAtual);
			uAtual = aux;
		}
		countUni++;
	}
	else
	{
		cout << "QUANTIDADE LIMITE DE UNIVERSIDADES ATINGIDA." << endl;
	}
}

void listUniversidade::setName(string no)
{
	nome = no;
}

void listUniversidade::listUnis1()
{
	elUniversidade* aux = uPrim;
	while (aux != NULL)
	{
		cout << "Universidade: " << aux->getName() << endl;
		aux = aux->getProx();
	}
}
void listUniversidade::listUnis2()
{
	elUniversidade* aux = uAtual;
	while (aux != NULL)
	{
		cout << "Universidade: " << aux->getName() << endl;
		aux = aux->getAnt();
	}
}

Universidade* listUniversidade::localizar(string n)
{
	elUniversidade* aux;
	aux = uPrim;

	while (aux != NULL)
	{
		if (0 == n.compare(aux->getName()))
		{
			return aux->getUni();
		}
		aux = aux->getProx();
	}
	return NULL;
}

void listUniversidade::salvarUnis()
{
	ofstream GravadorUniversidade("universidades.dat", ios::out);

	if (!GravadorUniversidade)
	{
		cerr << "Não foi possível criar o arquivo." << endl;
		cout << endl;
		cerr << "PRESSIONE QUALQUER TECLA PARA VOLTAR" << endl;
		fflush(stdin);
		cin >> ws;
		(void)getchar();
		return;
	}

	elUniversidade* elAux = uPrim;

	while (elAux != NULL)
	{
		Universidade* uAux = elAux->getUni();
		string name = uAux->getUniName();
		std::replace(name.begin(), name.end(), ' ', '_');

		GravadorUniversidade << name << ' ' << uAux->getId() << ' ' << uAux->getStatic() << endl;

		elAux = elAux->getProx();
	}

	GravadorUniversidade.close();
}
void listUniversidade::recuperarUnis()
{
	Universidade* aux = NULL;
	string name;
	bool s;
	int id;
	ifstream RecuperadorUniversidade("Universidades.dat", ios::in);

	if (!RecuperadorUniversidade)
	{
		cerr << "Arquivo não encontrado." << endl;
		cout << endl;
		cerr << "PRESSIONE QUALQUER TECLA PARA SAIR" << endl;
		fflush(stdin);
		cin >> ws;
		(void)getchar();
		return;
	}

	while (RecuperadorUniversidade >> name >> id >> s)
	{		
		if (0 != name.compare(" "))
		{
			aux = new Universidade();

			std::replace(name.begin(), name.end(), '_', ' ');
			aux->setName(name);
			aux->setId(id);
			aux->setStatic(s);

			setUni(aux);
		}
	}
	RecuperadorUniversidade.close();
}
