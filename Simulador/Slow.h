#pragma once
#include "Piloto.h"


class Slow : public Piloto
{
public:
	Slow(string name);
	~Slow();
	Piloto* duplica() const override;
	void passatempo() override;
	void setLag() override;
	bool getDamageProb() override;
};

