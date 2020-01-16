#pragma once
#include "Piloto.h"
#include "Carro.h"
#include "Log.h"
#include <random>


class Slow : public Piloto
{
public:
	Slow(string name);
	~Slow();
	Piloto* duplica() const override;
	void passatempo() override;
	void setLag() override;
	bool getCrazyProb() override;
	bool getFastProb() override;
	bool getSlowProb() override;
	int randomEmergencyGenerator(int start, int finish);
	string getProbLog() const override;
};

