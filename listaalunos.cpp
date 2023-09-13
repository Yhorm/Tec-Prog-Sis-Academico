#include "headers/listaalunos.h"


listaAlunos::listaAlunos(int n, std::string no)
{
	countAlunos = 0;
	numAlunos = n;
	nome = no;
	alunoPrim = NULL;
	alunoAtual = NULL;
}

listaAlunos::~listaAlunos()
{
	countAlunos = -1;
	numAlunos = -1;
	nome = "";
	
	elAluno* aux1 = NULL;
	elAluno* aux2 = NULL;

	aux1 = alunoPrim;
	aux2 = aux1;

	while (aux1 != NULL)
	{
		aux2 = aux1->getProx();
		delete aux1;
		aux1 = aux2;
	}


	alunoPrim = NULL;
	alunoAtual = NULL;
}


void listaAlunos::setAluno(Aluno* aluno)
{

	elAluno* aux; 
	aux = new elAluno();
	aux->setAluno(aluno);

	aux->setAnt(NULL);
	aux->setProx(NULL);

	if (countAlunos < numAlunos && aluno != NULL || numAlunos == -1 && aluno != NULL)
	{

		if (alunoPrim == NULL)
		{
			alunoAtual = aux;
			alunoPrim = aux;
		}
		else
		{
			alunoAtual->setProx(aux);
			aux->setAnt(alunoAtual);
			alunoAtual = aux;
		}
		countAlunos++;
	}
	else
	{
		cout << "TURMA LOTADA, ALUNO NÃO SERA INCLUIDO." << endl;
	}

}
void listaAlunos::listAlunos()
{

	elAluno* aux = alunoPrim;

	while (aux != NULL)
	{
		cout << "O(a) aluno(a) " << aux->getName() << " estuda a disciplina: " << nome << endl;
		aux = aux->getProx();
	}
}

void listaAlunos::listAlunos2()
{
	elAluno* aux = alunoAtual;

	while (aux != NULL)
	{
		cout << "O(a) aluno(a) " << aux->getName() << " estuda a disciplina: " << nome << endl;
		aux = aux->getAnt();
	}
}

void listaAlunos::resizeAlunos(int n)
{
	numAlunos = n;

}

void listaAlunos::salvarAlunos()
{
	ofstream GravadorAlunos ("alunos.dat", ios::out);

	if (!GravadorAlunos)
	{
		cerr << "Não foi possível criar o arquivo." << endl;
		fflush(stdin);
		cin >> ws;
		(void)getchar();
		return;
	}
	
	elAluno* elAlaux = alunoPrim;

	while (elAlaux != NULL)
	{
		Aluno* auxAl = elAlaux->getAluno();

		GravadorAlunos << auxAl->getName() << ' ' << auxAl->getBirthday() << ' ' << auxAl->getBirthmonth() << ' ' << auxAl->getBirthyear() << ' ' << auxAl->getRA() 
			<< ' ' << auxAl->getId() << ' ' << auxAl->getStatic() << endl;
		elAlaux = elAlaux->getProx();
	}
	GravadorAlunos.close();
}
void listaAlunos::recuperarAlunos()
{
	Aluno* aux = NULL;
	int id;
	int day, month, year;
	int ra;
	string name;
	bool s;

	ifstream RecuperadorAlunos("alunos.dat", ios::in);
	if (!RecuperadorAlunos)
	{
		cerr << "Arquivo não encontrado." << endl;
		fflush(stdin);
		cin >> ws;
		(void)getchar();
		return;
	}
	
	
	while (RecuperadorAlunos >> name >> day >> month >> year >> ra >> id >> s)
	{		
		if (0 != name.compare(" "))
		{
			aux = new Aluno();
			aux->setId(id);
			aux->setName(name);
			aux->setRA(ra);
			aux->setBirthdate(day, month, year);
			aux->setStatic(s);
			
			setAluno(aux);
		}
	}
	RecuperadorAlunos.close();
}