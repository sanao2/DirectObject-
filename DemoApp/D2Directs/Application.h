#pragma once
#include "RenderManager.h"

extern bool isQuit;

class Application
{
public:
	virtual void Initialize();
	virtual void Run();
	void Render();
	virtual void Uninitialize();
	virtual ~Application() = default;

private:
	RenderManager g_renderManager; 
};
