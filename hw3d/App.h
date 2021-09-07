#pragma once
#include "Window.h"
#include "HoneyTimer.h"

class App
{
public:
	App();
	//master frame/message loop
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	HoneyTimer timer;
};