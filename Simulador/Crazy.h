#pragma once
#include "Piloto.h"

using namespace std;

class Crazy : public Piloto
{ 
	bool lost_position_flag;
	int lost_position_accelerate;

public:
	Crazy(string name);
	void passatempo() override;
	void setLag() override;
	int getLag() const override;
	void iterateLag() override;
	bool getDamageProb() override;	
	int randomLagGenerator(int start, int finish);
};

