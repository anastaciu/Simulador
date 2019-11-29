#pragma once

class Pista
{
private:
	int pistas, comprimento;

public:
	Pista(int pistas, int comprimento);
	~Pista();
	int getPistas() const;
	int getComprimento() const;
};

