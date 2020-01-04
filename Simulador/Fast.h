#pragma once
#include "Piloto.h"
#include <random>

class Fast : public Piloto
{
private:
	int accelerateCounter, panic_counter;

public:
	Fast(string name);
	~Fast();
	Piloto* duplica() const override;
	void passatempo() override;
	void setLag() override;
	bool getCrazyProb() override;
	bool getFastProb() override;
	bool getSlowProb() override;
	int randomPanicGenerator(int start, int finish);
	string getProbLog() const override;
};

