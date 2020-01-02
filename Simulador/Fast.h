#pragma once
#include "Piloto.h"

class Fast : public Piloto
{
private:
	int accelerateCounter;

public:
	Fast(string name);
	~Fast();
	Piloto* duplica() const override;
	void passatempo() override;
	void setLag() override;
	bool getDamageProb() override;
};

