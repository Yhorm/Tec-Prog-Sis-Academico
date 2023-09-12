#include "headers/entidade.h"


Entidade::Entidade(int i, bool s)
{
	id = i;
	isStatic = s;
}
Entidade::~Entidade()
{
	id = -1;
	isStatic = true;
}
void Entidade::setId(int i)
{
	id = i;
}
int Entidade::getId()
{
	return id;
}
void Entidade::setStatic(bool s)
{
	isStatic = s;
}
bool Entidade::getStatic()
{
	return isStatic;
}