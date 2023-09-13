#include "headers/principal.h"
#include "Windows.h"
#include <locale>


Principal::Principal()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	system("Color 0B");
	cout.width(35);

	//Estrutura para utilizar o time.h: 
	SYSTEMTIME st;
	GetSystemTime(&st);

	diaAt = st.wDay;
	mesAt = st.wMonth;
	anoAt = st.wYear;

	Inicializa();
}
Principal::~Principal()
{
}

void Principal::Executar()
{
	/*
	showUniAfil();
	showDepAfil();
	listDiscDeps();
	listAlunosDisc();
	*/
	calcIdade();
	Menu();
}

void Principal::Inicializa()
{

	InicializaAlunos();	
	InicializaUniversidades();
	InicializaDepartamentos();
	InicializaDisciplina();
	InicializaProfessores();

}
void Principal::InicializaUniversidades()
{
	UTFPR.setName("UTFPR");
	UTFPR.setId(idUni++);
	UTFPR.setStatic(true);
	listUni.setUni(&UTFPR);

	cambridge.setName("Cambridge");
	cambridge.setId(idUni++);
	cambridge.setStatic(true);
	listUni.setUni(&cambridge);

	princeton.setName("Princeton");
	princeton.setId(idUni++);
	princeton.setStatic(true);
	listUni.setUni(&princeton);

}
void Principal::InicializaProfessores()
{
	simao.setName("Jean Simao");
	simao.setBirthdate(3, 10, 1976);
	simao.setId(idProf++);
	simao.setStatic(true);

	newton.setName("Sir Isaac Newton");
	newton.setBirthdate(4, 1, 1643);
	newton.setId(idProf++);
	newton.setStatic(true);

	einstein.setName("Albert Einstein");
	einstein.setBirthdate(14, 3, 1879);
	einstein.setId(idProf++);
	einstein.setStatic(true);

	simao.setUniAfil(&UTFPR);
	simao.setDepAfil(&DAELN);

	newton.setUniAfil(&cambridge);
	newton.setDepAfil(&mathCambridge);

	einstein.setUniAfil(&princeton);
	einstein.setDepAfil(&physicsPrinceton);

}
void Principal::InicializaDepartamentos()
{
	DAINF.setDepName("DAINF");
	DAELN.setDepName("DAELN");
	DAMAT.setDepName("DAMAT");
	physicsPrinceton.setDepName("FISICA - PRINCETON");
	mathCambridge.setDepName("MATEMATICA - CAMBRIDGE");
	DAINF.setId(idDep++);
	DAINF.setStatic(true);
	DAELN.setId(idDep++);
	DAELN.setStatic(true);
	DAMAT.setId(idDep++);
	DAMAT.setStatic(true);
	physicsPrinceton.setId(idDep++);
	physicsPrinceton.setStatic(true);
	mathCambridge.setId(idDep++);
	mathCambridge.setStatic(true);

	listDeps.setDep(&DAINF);
	listDeps.setDep(&DAELN);
	listDeps.setDep(&DAMAT);

	listDeps.setDep(&physicsPrinceton);
	
	listDeps.setDep(&mathCambridge);

	UTFPR.setDep(&DAINF);
	UTFPR.setDep(&DAELN);
	UTFPR.setDep(&DAMAT);

	princeton.setDep(&physicsPrinceton);

	cambridge.setDep(&mathCambridge);
}
void Principal::InicializaAlunos()
{
	felipe.setName("Felipe");
	felipe.setBirthdate(9, 8, 2002);
	felipe.setId(idAluno++);
	felipe.setStatic(true);

	BBB.setName("BBB");
	BBB.setId(idAluno++);
	BBB.setStatic(true);
	CCC.setName("CCC");
	CCC.setId(idAluno++);
	CCC.setStatic(true);
	DDD.setName("DDD");
	DDD.setId(idAluno++);
	DDD.setStatic(true);

	listAlunos.setAluno(&felipe);
	listAlunos.setAluno(&BBB);
	listAlunos.setAluno(&CCC);
	listAlunos.setAluno(&DDD);

}
void Principal::InicializaDisciplina()
{
	Comp1_2006.setName("Computação 1 - 2006");
	Comp1_2006.setId(idDisci);
	Comp1_2006.setStatic(true);
	IntrodAlg_2007.setName("Introdução a Algoritmos - 2007");
	IntrodAlg_2007.setId(idDisci);
	IntrodAlg_2007.setStatic(true);
	Comp2_2007.setName("Computação 2 - 2007");
	Comp2_2007.setId(idDisci);
	Comp2_2007.setStatic(true);
	Metodos2_2007.setName("Metodos 2 - 2007");
	Metodos2_2007.setId(idDisci);
	Metodos2_2007.setStatic(true);

	listDis.setDisciplina(&Comp1_2006);
	listDis.setDisciplina(&IntrodAlg_2007);
	listDis.setDisciplina(&Comp2_2007);
	listDis.setDisciplina(&Metodos2_2007);

	Comp1_2006.setDep(&DAELN);
	IntrodAlg_2007.setDep(&DAINF);
	Comp2_2007.setDep(&DAELN);
	Metodos2_2007.setDep(&DAELN);

	IntrodAlg_2007.setAluno(&felipe);
	IntrodAlg_2007.setAluno(&BBB);
	IntrodAlg_2007.setAluno(&CCC);

	Comp2_2007.setAluno(&BBB);
	Comp2_2007.setAluno(&DDD);

}

void Principal::calcIdade()
{
	felipe.calcAge(diaAt, mesAt, anoAt);
	simao.calcAge(diaAt, mesAt, anoAt);
	einstein.calcAge(diaAt, mesAt, anoAt);
	newton.calcAge(diaAt, mesAt, anoAt);

}

void Principal::showDepAfil()
{
	simao.showDepAfil();
	einstein.showDepAfil();
	newton.showDepAfil();
}
void Principal::showUniAfil()
{
	simao.showUniAfil();
	einstein.showUniAfil();
	newton.showUniAfil();
}
void Principal::listDiscDeps()
{
	DAELN.listDisciplina();
	printf("\n");
	DAINF.listDisciplina();
	printf("\n");
}
void Principal::listAlunosDisc()
{
	IntrodAlg_2007.listAlunos();
	printf("\n");
	Comp2_2007.listAlunos();
	printf("\n");
}

void Principal::Menu()
{
	int opt = 0;

	while (opt != 5)
	{
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << endl;
		cout << "-------- SELECIONE UMA DAS OPÇÕES ABAIXO --------" << endl;
		cout << endl;
		cout << "-------- 1 - CADASTRAR --------" << endl;
		cout << endl;
		cout << "-------- 2 - EXECUTAR --------" << endl;
		cout << endl;
		cout << "-------- 3 - SALVAR ----------" << endl;
		cout << endl;
		cout << "-------- 4 - RECUPERAR ----------" << endl;
		cout << endl;
		cout << "-------- 5 - SAIR  -----------" << endl;
		cout << endl;
		cout << "-------------------------------------------------" << endl;
		cout << endl;
		cin >> ws;
		cin >> opt;


		switch (opt)
		{
		case 1: 
		{
			menuCad();
		}
			  break;
		case 2: 
		{
			menuExec();
		}
			  break;
		case 3: 
		{
			menuSalvar();
		}
		break;
		case 4:
		{
			menuRecuperar();
		}
		break;
		case 5: 
		{
			system("cls");
			cout << "------------------------------" << endl;
			cout << "SAINDO DO SISTEMA" << endl;
			cout << "------------------------------" << endl;
		}
			  break;
		default: {
			cerr << "OPÇÃO INVÁLIDA. - PRESSIONE QQR TECLA " << endl;
			cin >> ws;
			system("Pause");
		}
		}
	}
}
void Principal::menuCad()
{
	int opt = 0;

	while (opt != 5)
	{
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << endl;
		cout << "-------- SELECIONE UMA DAS OPÇÕES ABAIXO --------" << endl;
		cout << endl;
		cout << "-------- 1 - CADASTRAR UMA UNIVERSIDADE --------" << endl;
		cout << endl;
		cout << "-------- 2 - CADASTRAR UM DEPARTAMENTO --------" << endl;
		cout << endl;
		cout << "-------- 3 - CADASTRAR UMA DISCIPLINA  --------" << endl;
		cout << endl;
		cout << "-------- 4 - CADASTRAR UM ALUNO ---------------" << endl;
		cout << endl;
		cout << "-------- 5 - SAIR --------" << endl;
		cout << "------------------------------------------------" << endl;
		cout << endl;

		cin >> ws;
		cin >> opt;

		switch (opt)
		{
			case 1:
			{
				cadUni();
			}
			break;
			case 2:
			{
				cadDep();
			}
			break;
			case 3:
			{
				cadDisci();
			}
			break;
			case 4:
			{
				cadAluno();
			}
			break;
			case 5:
			{
				cout << "SAINDO DO SISTEMA" << endl;
			}
			break;
			default: 
			{
				cerr << "OPÇÃO INVÁLIDA - PRESSIONE QQR TECLA" << endl;
				fflush(stdin);
				cin >> ws;
				(void)getchar();
			}
		}
	}
}
void Principal::menuExec()
{
	int opt = 0;
	while(opt != 5)
	{
		fflush(stdin);
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << endl;
		cout << "-------- SELECIONE UMA DAS OPÇÕES ABAIXO --------" << endl;
		cout << endl;
		cout << "-------- 1 - LISTAR ALUNOS ------------------" << endl;
		cout << endl;
		cout << "-------- 2 - LISTAR AS UNIVERSIDADES --------" << endl;
		cout << endl;
		cout << "-------- 3 - LISTAR OS DEPARTAMENTOS --------" << endl;
		cout << endl;
		cout << "-------- 4 - LISTAR AS DISCIPLINAS  ---------" << endl;
		cout << endl;
		cout << "-------- 5 - SAIR ---------------------------" << endl;
		cout << endl;
		cout << "-------------------------------------------------" << endl;
		cin >> ws;
		cin >> opt;

		switch (opt)
		{
		case 1:
		{
			listAlunos.listAlunos();
			fflush(stdin);
			system("pause");
		}
		break;
		case 2:
		{
			listUni.listUnis1();
			fflush(stdin);
			system("pause");
		}
		break;
		case 3:
		{
			listDeps.listDep1();
			fflush(stdin);
			system("pause");
		}
		break;
		case 4:
		{
			listDis.listDisciplina();
			fflush(stdin);
			system("pause");
		}
		case 5:
		{
			cout << "SAINDO DO SISTEMA." << endl;
		}
		break;
		default:
		{
			cerr << "OPÇÃO INVÁLIDA. - PRESSIONE QQR TECLA PARA SAIR" << endl;
			fflush(stdin);
			cin >> ws;
			(void)getchar();
		}
		}
	}
}
void Principal::menuSalvar()
{
	int opt = 0;
	while (opt != 6)
	{
		fflush(stdin);
		system("cls");
		cout << "-------------------------------------------------";
		cout << "-------- SELECIONE UMA DAS OPÇÕES ABAIXO --------" << endl;
		cout << endl;
		cout << "-------- 1 - SALVAR TUDO --------------------" << endl;
		cout << endl;
		cout << "-------- 2 - SALVAR OS ALUNOS ---------------" << endl;
		cout << endl;
		cout << "-------- 3 - SALVAR AS DISCIPLINAS  ---------" << endl;
		cout << endl;
		cout << "-------- 4 - SALVAR OS DEPARTAMENTOS --------" << endl;
		cout << endl;
		cout << "-------- 5 - SALVAR AS UNIVERSIDADES --------" << endl;
		cout << endl;
		cout << "-------- 6 - SAIR ---------------------------" << endl;
		cout << endl;
		cout << "-------------------------------------------------" << endl;
		cin >> ws;
		cin >> opt;

		switch (opt)
		{
		case(1):
			{
			salvarTudo();
			}
			break;
		case (2):
			{
			salvarAlunos();
			}
			break;
		case(3):
			{
			salvarDisci();
			}
			break;
		case(4):
			{
			salvarDeps();
			}	
			break;
		case(5):
			{
			salvarUnis();
			}
			break;
		case(6):
			{
			cout << "------------- SAINDO DO SISTEMA -------------" << endl;
			}
			break;
		default:
			{
			cerr << "OPÇÃO INVALIDA - APERTE QUALQUER TECLA PARA SAIR." << endl;
			fflush(stdin);
			cin >> ws;
			(void)getchar();
			}
		}
	}
}
void Principal::menuRecuperar()
{
	int opt = 0;
	while (opt != 6)
	{
		fflush(stdin);
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "-------- SELECIONE UMA DAS OPÇÕES ABAIXO --------" << endl;
		cout << endl;
		cout << "-------- 1 - RECUPERAR TUDO --------------------" << endl;
		cout << endl;
		cout << "-------- 2 - RECUPERAR OS ALUNOS ---------------" << endl;
		cout << endl;
		cout << "-------- 3 - RECUPERAR AS DISCIPLINAS  ---------" << endl;
		cout << endl;
		cout << "-------- 4 - RECUPERAR OS DEPARTAMENTOS --------" << endl;
		cout << endl;
		cout << "-------- 5 - RECUPERAR AS UNIVERSIDADES --------" << endl;
		cout << endl;
		cout << "-------- 6 - SAIR ---------------------------" << endl;
		cout << endl;
		cout << "-------------------------------------------------" << endl;
		cin >> ws;
		cin >> opt;

		switch (opt)
		{
		case(1):
			{
			recuperarTudo();
			}
			break;
		case (2):
			{
			recuperarAlunos();
			}
			break;
		case(3):
			{
			recuperarDis();
			}
			break;
		case(4):
			{
			recuperarDeps();
			}	
			break;
		case(5):
			{
			recuperarUnis();
			}
			break;
		case(6):
			{
			cout << "------------- SAINDO DO SISTEMA -------------" << endl;
			}
			break;
		default:
			{
			cerr << "OPÇÃO INVALIDA - APERTE QUALQUER TECLA PARA SAIR." << endl;
			fflush(stdin);
			cin >> ws;
			(void)getchar();
			}
		}
	}

}

void Principal::cadAluno()
{
	string nomeAluno;
	string nomeDisci;
	string nomeUni;
	string nomeDep;

	int dia = 0, mes = 0, ano = 0, RA = 0;

	Aluno* aluno;
	Universidade* uni;
	Departamento* dep;
	Disciplina* dis;

	cout << "Digite o nome do aluno." << endl;
	while (getline(cin, nomeAluno))
	{
		if (nomeDisci != "")
		{
			break;
		}
	}

	aluno = new Aluno();
	aluno->setName(nomeAluno);

	cout << "Digite a data de nascimento do aluno no formado DDMMYYYY: " << endl;
	cin >> ws;
	cin >> dia >> mes >> ano;
	aluno->setBirthdate(dia, mes, ano);

	cout << "Digite o RA do aluno: " << endl;
	cin >> RA;
	aluno->setRA(RA);
	aluno->setId(idAluno++);
	aluno->setStatic(false);


	listAlunos.setAluno(aluno);
	aluno->calcAge(diaAt, mesAt, anoAt);

	cout << "Gostaria de cadastrar o aluno em uma Disciplina?" << endl << "1 - SIM" << endl << "2 - NÃO";
	int opt = 0;
	while (opt != 2)
	{
		cin >> ws;
		cin >> opt;
		switch (opt)
		{
		case(1):
			{
				cout << "Digite o nome da universidade: " << endl;
				fflush(stdin);
				while (getline(cin, nomeUni))
				{
					if (nomeUni != "")
					{
						break;
					}
				}
				uni = listUni.localizar(nomeUni);
				if (uni != NULL)
				{
					cout << "Digite o nome do departamento: " << endl;
					while (getline(cin, nomeDep))
					{
						if (nomeDep != "")
						{
							break;
						}
					}
					dep = listDeps.localizar(nomeDep);
					if (dep != NULL)
					{
						cout << "Digite o nome da disciplina: " << endl;
						while (getline(cin, nomeDisci))
						{
							if (nomeDisci != "")
							{
								break;
							}
						}

						dis = listDis.localiza(nomeDisci);
						if (dis != NULL)
						{
							dis->setAluno(aluno);
							aluno->setDisAfil(dis);
						}
						else
						{
							cerr << "Disciplina não existente." << endl;
						}
					}
					else
					{
						cerr << "Departamento não existente." << endl;
					}
				}
				else
				{
					cerr << "Universidade não existente." << endl;
				}
			}
			break;
		case (2):
			{
				aluno->setDisAfil(NULL);
				system("cls");
				cout << "------------------------------" << endl;
				cout << "SAINDO DO SISTEMA" << endl;
				cout << "------------------------------" << endl;
			}
			break;
		}
	}


}
void Principal::cadDisci()
{
	string nomeDisci;
	string nomeUni;
	string nomeDep;

	Universidade* uni;
	Departamento* dep;
	Disciplina* dis;


	cout << "Digite o nome da universidade do departamento: " << endl;
	fflush(stdin);
	while (getline(cin, nomeUni))
	{
		if (nomeUni != "")
		{
			break;
		}
	}

	uni = listUni.localizar(nomeUni);
	if (uni != NULL)
	{
		cout << "Digite o nome do departamento: " << endl;

		while (getline(cin, nomeDep))
		{
			if (nomeDep != "")
			{
				break;
			}
		}

		dep = listDeps.localizar(nomeDep);
		if (dep != NULL)
		{
			cout << "Digite o nome da disciplina: " << endl;
			while (getline(cin, nomeDisci))
			{
				if (nomeDisci != "")
				{
					break;
				}
			}

			dis = new Disciplina();
			dis->setName(nomeDisci);
			dis->setDep(dep);
			dis->setId(idDisci++);
			dis->setStatic(false);
			listDis.setDisciplina(dis);
		}
		else
		{
			cerr << "Departamento não existente." << endl;
		}
	}
	else
	{
		cerr << "Universidade não existente." << endl;
	}
}
void Principal::cadDep()
{
	string nomeUni;
	string nomeDep;

	Universidade* uni;
	Departamento* dep;

	cout << "Digite o nome da universidade do departamento: " << endl;
	fflush(stdin);
	while (getline(cin, nomeUni))
	{
		if (nomeUni != "")
		{
			break;
		}
	}
	
	uni = listUni.localizar(nomeUni);
	if (uni != NULL)
	{
		cout << "Digite o nome do departamento: " << endl;
		while (getline(cin, nomeDep))
		{
			if (nomeDep != "")
			{
				break;
			}
		}
		
		dep = new Departamento();
		dep->setDepName(nomeDep);
		dep->setUni(uni);
		dep->setId(idDep++);
		dep->setStatic(false);
		listDeps.setDep(dep);
		uni->setDep(dep);
	}
	else
	{
		cerr << "Universidade não existente." << endl;
	}
}
void Principal::cadUni()
{
	string nome;
	Universidade* univ = NULL;
	
	cout << "Digite o nome da universidade: " << endl;
	fflush(stdin);
	while (getline(cin, nome))
	{
		if (nome != "")
		{
			break;
		}
	}

	univ = new Universidade();
	univ->setName(nome);
	univ->setId(idUni++);
	univ->setStatic(false);
	listUni.setUni(univ);

}


void Principal::salvarTudo()
{
	salvarAlunos();
	salvarDisci();
	salvarDeps();
	salvarUnis();

}
void Principal::salvarAlunos()
{
	listAlunos.salvarAlunos();
}
void Principal::salvarDisci()
{
	listDis.salvarDis();
}
void Principal::salvarDeps()
{
	listDeps.salvarDeps();
}
void Principal::salvarUnis()
{
	listUni.salvarUnis();
}


void Principal::recuperarTudo()
{
	recuperarAlunos();
	recuperarDis();
	recuperarDeps();
	recuperarUnis();
}
void Principal::recuperarAlunos()
{
	listAlunos.recuperarAlunos();
}
void Principal::recuperarDis()
{
	listDis.recuperarDis();
}
void Principal::recuperarDeps()
{
	listDeps.recuperarDeps();
}
void Principal::recuperarUnis()
{
	listUni.recuperarUnis();
}