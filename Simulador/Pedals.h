#pragma once
class Pedals
{
private:
	bool accelerator;
	bool brake;

public:
	Pedals();
	~Pedals();
	bool getAcceleratorState() const;
	void setAccelerator(bool accelerator);
	bool getBrakeState() const;
	void setBrake(bool brake);

};

