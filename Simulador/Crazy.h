#pragma once
#include "Piloto.h"

using namespace std;

class Crazy : public Piloto
{ 	

public:
	Crazy(string name);
	Piloto* duplica() const override;
	void passatempo() override;
	void setLag() override;
	bool getCrazyProb() override;	
	bool getFastProb() override;
	bool getSlowProb() override;
	int randomLagGenerator(int start, int finish);
	string getProbLog() const override;
};

