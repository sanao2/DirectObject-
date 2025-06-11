#include "pch.h"
#include "Object.h"

void Object::BeginDrawandClear()
{
	ObjTarget->BeginDraw();
	ObjTarget->Clear();
}

void Object::Initialize()
{
	ObjTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::SkyBlue),
		&FillTarget); 

	Objrect = { transforms.dx, transforms.dy,  transforms.dx + transforms.scaleX,  transforms.dy + transforms.scaleY };
}

void Object::DrawObject()
{
	ObjTarget->DrawRectangle(Objrect, FillTarget.Get(), 2.0f);
}

void Object::ObjectRender()
{
	BeginDrawandClear();
	DrawObject(); 
}

void Object::UnInitialize()
{
	ObjTarget = nullptr;
	FillTarget = nullptr;
}

void Object::SetRenderTarget(ComPtr<ID2D1RenderTarget> target)
{
	ObjTarget = target; 
}

void Object::SetObjPosition(float x, float y)
{
	transforms.dx = x;
	transforms.dy = y;
}

void Object::SetObjRotation(float rx)
{
	transforms.rotateX = rx;
	
}

void Object::SetObjScale(float sx, float sy)
{
	transforms.scaleX = sx;
	transforms.scaleY = sy;
}
