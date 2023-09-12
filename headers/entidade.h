#pragma once


class Entidade
{
protected:
	int id;
	bool isStatic;
public:
	Entidade(int i = -1, bool s = true);
	~Entidade();
	void setId(int i);
	int getId();
	void setStatic(bool s = true);
	bool getStatic();
};

