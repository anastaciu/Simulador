#pragma once
#include "Piloto.h"

class Fast : public Piloto
{
public:
	Fast(string name);
	~Fast();
	void passatempo() override;
	void setLag() override;
	int getLag() const override;
	void iterateLag() override;
	bool getDamageProb() override;
};

