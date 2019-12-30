#include "Carro.h"
#include <iostream>


char Carro::id_global = 'a';
const string Carro::MODELO_BASE = "modelo base";

Carro::Carro(int v_max, double energy, double capacity, string marca, string modelo) : marca(marca), modelo(modelo), max_speed(v_max), capacity(capacity), pedals(), is_moving(false),
emergency(false), is_damaged(false), speed(0), positionX(0), positionY(0), distancia(0), stop(false)
{
	id = id_global > 'z' ? '?' : id_global++;
	this->energy = energy;
	if (!energyLimitsInbound()) {
		this->energy = this->capacity;
	}
}

Carro::Carro(int v_max, double energy, double capacity, string marca) : marca(marca), max_speed(v_max), capacity(capacity), modelo(MODELO_BASE), pedals(), is_moving(false),
emergency(false), is_damaged(false), speed(0), positionX(0), positionY(0), distancia(0), stop(false)
{
	id = id_global > 'z' ? '?' : id_global++;
	this->energy = energy;
	if (!energyLimitsInbound()) {
		this->energy = this->capacity;
	}
}

Carro::~Carro()
{
}

Pedals Carro::getPedals() const
{
	return this->pedals;
}

bool Carro::getStop() const
{
	return stop;
}

void Carro::setStop(bool stop)
{
	this->stop = stop;
}

string Carro::getId()
{
	return id;
}

void Carro::setId(char id)
{
	this->id = id;
}

string Carro::getBrand() const
{
	return marca;
}

string Carro::getModel() const
{
	return modelo;
}

int Carro::getMaxSpeed() const
{
	return max_speed;
}

double Carro::getEnergy() const
{
	return energy;
}

double Carro::getMaxEnergy() const
{
	return capacity;
}

bool Carro::energyLimitsInbound() const
{
	return energy < capacity;
}

Piloto& Carro::getPiloto()
{ 
	return *condutor;
}

void Carro::setPiloto(Piloto* condutor)
{
	this->condutor = condutor;
}

void Carro::manivela(double n)
{
	if (energyLimitsInbound() && n > 0) {
		this->energy += n;
	}
	if (!energyLimitsInbound()) {
		this->energy = this->capacity;
	}
}

string Carro::getAsString() const
{
	ostringstream os;
	os << "Carro: " << id << ", " << marca << " " << modelo << ", Velocidade Maxima: " << max_speed << ", Capacidade Maxima: "
		<< capacity << ", Energia: " << energy << (condutor ? ", " + condutor->getPilotDetais() : "\n");
	return os.str();
}

double Carro::getXPosition() const
{
	return positionX;
}

int Carro::getYPosition() const
{
	return positionY;
}

void Carro::setPosition(double x, int y)
{
	this->positionX = x;
	this->positionY = y;
}

int Carro::getSpeed() const
{
	return speed;
}

void Carro::setSpeed()
{
	if (this->pedals.getAcceleratorState() && speed < max_speed) {
		speed += 1;
	}
	if (this->pedals.getBrakeState() && speed > 0) {
		speed -= 1;
	}
}

bool Carro::getEmergency() const
{
	return emergency;
}

void Carro::setEmergency(bool emergency)
{
	this->emergency = emergency;
}

void Carro::passatempo(double comprimento, double const comprimentoPista, int tempo)
{
	int i = 5;
	exception e;
	if (condutor != nullptr) {		
		resetPedals();
		semEnergia();
		getPiloto().passatempo();		
		setSpeed();
		gastaEnergia();
		setPosition(positionX + ((comprimentoPista / comprimento) * speed), positionY);
		distancia += speed;
		if (distancia >= comprimento) {
			throw e;
		}
	}
}

bool Carro::operator== (Carro* carro)
{
	return this->id == carro->id;
}

void Carro::carregaMax()
{
	this->energy = this->capacity;
}

void Carro::nullifyPiloto()
{
	condutor = nullptr;
}

void Carro::accelerate()
{
	this->pedals.setBrake(false);
	this->pedals.setAccelerator(true);
}

void Carro::brake()
{
	this->pedals.setAccelerator(false);
	this->pedals.setBrake(true);
}

void Carro::stopBraking()
{
	this->pedals.setBrake(false);
}

void Carro::stopAccelerating()
{
	this->pedals.setAccelerator(false);
}

void Carro::gastaEnergia()
{
	if (energy > 0 && speed > 0)
		energy -= 0.1 * speed;
	if (energy < 0)
		energy = 0;
}

void Carro::setSpeedManually(int speed)
{
	this->speed = speed;
}

void Carro::resetPedals()
{
	stopAccelerating();
	stopBraking();
}

string Carro::getRaceDetails()
{
	ostringstream lag;
	lag << condutor->getLag();
	ostringstream os;
	os << "  " << this->getPiloto().getPosition() << " - Carro " << getPiloto().getCarro().getId() << "/" << condutor->getName() <<", " << condutor->getPontos() <<" pontos, " << speed << " m/s, " << this->energy << "/" << this->capacity << " mAh, " << distancia << " m" << (getPiloto().getLag() > 0 ? ", Atraso:" : "") << (getPiloto().getLag() > 0 ? lag.str() : "");
	return os.str();
}

void Carro::semEnergia()
{
	if (energy == 0) {
		brake();
	}
}

int Carro::getDistance() const
{
	return distancia;
}

void Carro::resetCarro()
{
	speed = 0;
	distancia = 0;
	stopBraking();
	stopAccelerating();	

}


