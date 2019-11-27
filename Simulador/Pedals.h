#pragma once
class Pedals
{
private:
	bool accelerator;
	bool brake;

public:
	bool getAcceleratorState() const;
	void setAccelerator(bool accelerator);
	bool getBrakeState() const;
	void setBrake(bool brake);

};

