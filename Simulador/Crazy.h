#pragma once
#include "Piloto.h"

using namespace std;

class Crazy : public Piloto
{ 
	int lost_position_accelerate;

public:
	Crazy(string name);
	void passatempo() override;
	void setLag() override;
	bool getDamageProb() override;	
	int randomLagGenerator(int start, int finish);
};

