#pragma once
#include "Piloto.h"

using namespace std;

class Crazy : public Piloto
{
	int lag;

public:
	Crazy(string name);
	string getAsString() const override;
	string getPilotDetais() const override;
	void passatempo() override;
	void setLag();
	
	
};

