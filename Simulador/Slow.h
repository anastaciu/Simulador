#pragma once
#include "Piloto.h"


class Slow : public Piloto
{
public:
	Slow(string name);
	~Slow();
	void passatempo() override;
	void setLag() override;
	int getLag() const override;
	void iterateLag() override;
	bool getDamageProb() override;
};

