#pragma once
#include <exception>
#include "ImageManager.h"
#include "Object.h"

class RenderManager : public ImageManager 
{
public:
	void Render();
	void Initialize();
	void Uninitialize();
	void Release();

	//Object* obj; 
private : 
	bool g_resized = false;
	HINSTANCE  g_hInstance = nullptr; // ������ �ν��Ͻ� �ڵ� 

};

