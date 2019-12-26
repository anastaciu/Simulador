#include "Crazy.h"
#include "Carro.h"

Crazy::Crazy(string name) : Piloto(name), lost_position_flag(false), lost_position_accelerate(0)
{
	this->tipo = "crazy";
}

void Crazy::passatempo()
{
	if (getLast()) {
		getCarro().brake();
	}
	if (!getFirst() && !getLast()) {
		getCarro().accelerate();
	}
	if (getFirst()) {
		getCarro().stopBraking();
		getCarro().stopAccelerating();
	}
	if (position < prev_position && !getLast()) {
		lost_position_flag = true;
		lost_position_accelerate = 2;
	}

	if (lost_position_accelerate--) {
		getCarro().accelerate();
		if (lost_position_accelerate == 0)
			lost_position_flag = false;
	}

}

void Crazy::setLag()
{
	lag = randomIntGenerator(1, 5);
}

int Crazy::getLag() const
{
	return lag;
}

void Crazy::iterateLag()
{
	if (lag > 0) {
		lag--;
	}
}

bool Crazy::getDamageProb()
{
	return randomIntGenerator(1, 100) < 6;
}



