#pragma once
#include "Piloto.h"

class Fast : public Piloto
{
public:
	Fast(string name);
	~Fast();
	string getAsString() const override;
	string getPilotDetais() const override;
};

