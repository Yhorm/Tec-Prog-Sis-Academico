#include "headers/listadisciplina.h"

listaDisciplina::listaDisciplina(int nDis, std::string n) 
{
	countDisciplinas = 0;
	numDisciplinas = nDis;
	nome = n;

	disAtual = NULL;
	disPrim = NULL;
}

listaDisciplina::~listaDisciplina() 
{
	countDisciplinas = 0;
	numDisciplinas = -1;
	nome = " ";

	elDisciplina* aux1 = disPrim;
	elDisciplina* aux2 = aux1;


	while (aux1 != NULL)
	{
		aux2 = aux1->getProx();
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
	elDisciplina* aux; 
	aux = new elDisciplina();

	aux->setDisciplina(dis);
	aux->setProx(NULL);
	aux->setAnt(NULL);

	if (countDisciplinas < numDisciplinas && dis != NULL || numDisciplinas == -1 && dis != NULL)
	{
		if (disPrim == NULL)
		{
			setPrim(aux);
			setAtual(aux);
		}
		else
		{
			disAtual->setProx(aux);
			aux->setAnt(disAtual);
			setAtual(aux);
		}
		countDisciplinas++;
	}
	else
	{
		cout << "Disciplina n sera adicionada devido a falta de espaço no departamento: " << nome << endl;
	}

}

void listaDisciplina::setAtual(elDisciplina* atual)
{
	disAtual = atual;
}
void listaDisciplina::setPrim(elDisciplina* prim)
{
	disPrim = prim;
}

void listaDisciplina::listDisciplina() 
{
	elDisciplina* aux = disPrim;

	while (aux != NULL)
	{
		cout << "Disciplina: " << aux->getDisName() << " do departamento " << nome << "." << endl;
		aux = aux->getProx();
	}
}
void listaDisciplina::listDisciplina2() 
{
	elDisciplina* aux = disAtual;

	while (aux != NULL)
	{
		cout << "Disciplina: " << aux->getDisName() << " do departamento " << nome << "." << endl;
		aux = aux->getAnt();
	}
}

Disciplina* listaDisciplina::localiza(string n)
{
	elDisciplina* aux;
	aux = disAtual;

	while (aux != NULL)
	{
		if (0 == n.compare(aux->getDisName()))
		{
			return aux->getDisciplina();
		}
		aux = aux->getProx();
	}

	return NULL;
}

void listaDisciplina::salvarDis()
{
	ofstream GravadorDisciplinas("disciplinas.dat", ios::out);

	if (!GravadorDisciplinas)
	{
		cerr << "Arquivo não pode ser criado." << endl;
		fflush(stdin);
		cin >> ws;
		(void)getchar();
		return;
	}

	elDisciplina* elAux = disPrim;

	while (elAux != NULL)
	{
		Disciplina* dAux = elAux->getDisciplina();
		string name = dAux->getName();
		replace(name.begin(), name.end(), ' ', '_');

		GravadorDisciplinas << name << ' ' << dAux->getId() << ' ' << dAux->getStatic() << endl;

		elAux = elAux->getProx();
	}
	GravadorDisciplinas.close();
}
void listaDisciplina::recuperarDis()
{
	Disciplina* aux = NULL;
	string name;
	int id;
	bool s;
	ifstream RecuperadorDisciplinas("disciplinas.dat", ios::in);


	if (!RecuperadorDisciplinas)
	{
		cerr << "Arquivo não encontrado." << endl;
		fflush(stdin);
		cin >> ws;
		(void)getchar();
		return;
	}

	while (RecuperadorDisciplinas >> name >> id >> s)
	{
		if (0 != name.compare(" "))
		{
			aux = new Disciplina();
			std::replace(name.begin(), name.end(), '_', ' ');
			aux->setName(name);
			aux->setId(id);
			aux->setStatic(s);

			setDisciplina(aux);

		}
	}
	RecuperadorDisciplinas.close();
}