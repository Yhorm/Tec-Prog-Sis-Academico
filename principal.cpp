#include "principal.h"

Principal::Principal()
{
	//Estrutura para utilizar o time.h: 
	struct tm* local;
	time_t segundos;
	time(&segundos);
	local = localtime(&segundos);

	diaAt = local->tm_mday;
	mesAt = local->tm_mon + 1;
	anoAt = local->tm_year + 1900;

	Inicializa();

}



Principal::~Principal()
{
}

void Principal::Executar()
{
	calcIdade();
	showDepAfil();
	felipe.showRA();
	jorge.showRA();
	listDiscDeps();
	listAlunosDisc();

}


void Principal::Inicializa()
{
	InicializaAlunos();	
	InicializaProfessores();
	InicializaUniversidades();
	InicializaDepartamentos();
	InicializaDisciplina();

}


void Principal::InicializaUniversidades()
{
	//Inicializa as universidades:
	UTFPR.Inicializa("UTFPR");
	cambridge.Inicializa("Cambridge");
	princeton.Inicializa("Princeton");

	//Seta os departamentos as Universidades:
	UTFPR.setDep(&DAINF, 0);
	UTFPR.setDep(&DAELN, 1);
	UTFPR.setDep(&DAMAT, 2);
	cambridge.setDep(&mathCambridge, 0);
	princeton.setDep(&physicsPrinceton, 0);

}
void Principal::InicializaProfessores()
{
	simao.Inicializa(3, 10, 1976, "Jean Simão");
	newton.Inicializa(4, 1, 1643, "Isaac Newton");
	einstein.Inicializa(14, 3, 1879, "Albert Einstein");

	simao.setUniAfil(&UTFPR);
	newton.setUniAfil(&cambridge);
	einstein.setUniAfil(&princeton);

	simao.setDepAfil(&DAELN);
	newton.setDepAfil(&mathCambridge);
	einstein.setDepAfil(&physicsPrinceton);
}
void Principal::InicializaDepartamentos()
{
	//Inicializa os departamentos:
	DAINF.Inicializa("DAINF");
	DAELN.Inicializa("DAELN");
	DAMAT.Inicializa("DAMAT");
	mathCambridge.Inicializa("Matematica na Universidade de Cambridge");
	physicsPrinceton.Inicializa("Fisica na Universidade de Princeton");

	//Filia os departamentos as universidades:
	DAINF.setUni(&UTFPR);
	DAELN.setUni(&UTFPR);
	DAMAT.setUni(&UTFPR);
	physicsPrinceton.setUni(&princeton);
	mathCambridge.setUni(&cambridge);
}
void Principal::InicializaAlunos()
{
	felipe.Inicializa(9, 8, 2002, "Felipe Mossato");
	jorge.Inicializa(10, 4, 2000, "Jorge Jorge");

	felipe.setUniAfil(&UTFPR);
	jorge.setUniAfil(&UTFPR);

	felipe.setDepAfil(&DAINF);
	jorge.setDepAfil(&DAMAT);

	felipe.setRA(2557959);
	jorge.setRA(2541343);
}
void Principal::InicializaDisciplina()
{
	Comp1_2006.setName("Computacao 1 2006");
	Introd_Alg_2007.setName("Intro de Algde Programacao 2007");
	Comp2_2007.setName("Computao II");
	Metodos2_2007.setName("Métodos II");


	DAELN.setDisciplina(&Comp1_2006);
	DAELN.setDisciplina(&Introd_Alg_2007);
	DAELN.setDisciplina(&Comp2_2007);
	DAELN.setDisciplina(&Metodos2_2007);

	Metodos2_2007.setAluno(&felipe);
	Metodos2_2007.setAluno(&jorge);
}

void Principal::calcIdade()
{
	felipe.calcAge(diaAt, mesAt, anoAt);
	jorge.calcAge(diaAt, mesAt, anoAt);
	simao.calcAge(diaAt, mesAt, anoAt);
	newton.calcAge(diaAt, mesAt, anoAt);
	einstein.calcAge(diaAt, mesAt, anoAt);
}
void Principal::showDepAfil()
{
	printf("\n");
	felipe.showDepAfil();
	printf("\n");
	jorge.showDepAfil();
	printf("\n");
	simao.showDepAfil();
	printf("\n");
	newton.showDepAfil();
	printf("\n");
	einstein.showDepAfil();
	printf("\n");
}
void Principal::showUniAfil()
{
	printf("\n");
	felipe.showUniAfil();
	printf("\n");
	jorge.showDepAfil();
	printf("\n");
	simao.showUniAfil();
	printf("\n");
	newton.showDepAfil();
	printf("\n");
	einstein.showDepAfil();
	printf("\n");
}
void Principal::listDiscDeps()
{
	printf("\n");
	DAELN.listDisciplina();
	printf("\n");
}

void Principal::listAlunosDisc()
{
	printf("\n");
	Metodos2_2007.listAlunos();
	printf("\n");
}