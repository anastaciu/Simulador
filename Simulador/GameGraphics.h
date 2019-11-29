#pragma once
#include "UserConsole.h"
#include "MessageLog.h"

using namespace std;

class GameGraphics
{
private:
	UserConsole userConsole;
	MessageLog log;

public:
	GameGraphics();
	void start();

};

