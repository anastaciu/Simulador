#pragma once
#include "Piloto.h"


class Slow : public Piloto
{
public:
	Slow(string name);
	~Slow();
	string getAsString() const override;
};

