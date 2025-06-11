#pragma once
#include <array> // Include for std::array
using namespace std;

// �÷��̾�, ���� ���� ��ǥ, ������, �����̼� ���� ���� ���� 
// �Ǵ�, ��Ʈ���� �����ų ������Ʈ�� ���� 

// �ʿ��� ���� : RECT, Rotatioon, Scale(float), dx,dy 

// ��� ���� ������ �迭�� �����ؼ�, �� �迭�� ��� ������ �ҷ��ͼ� 
// transform  �Ǵ� ��ȯ ��Ŀ� ����� �� ������ ���� ������? 
// size ���� ���� ������ �ʿ��ϴ�. 

struct Objtransform
{
	// �̵��� ����� int Ÿ��
	float dx;
	float dy;

	// �������� ����� float Ÿ�� 
	float scaleX;
	float scaleY;

	// ȸ���� ����� float Ÿ�� 
	float rotateX;
};
class Object
{
public : 
	D2D1_RECT_F Objrect;

private:
	// ������Ʈ�� �׸� ���� 
	Objtransform transforms;
	ComPtr<ID2D1RenderTarget> ObjTarget; 
	ComPtr<ID2D1SolidColorBrush> FillTarget; 

	// ������Ʈ�� ��ǥ 	// ������Ʈ�� ũ�� 	// ������Ʈ�� ȸ�� ũ�� 

public:
	Object(D2D1_POINT_2F Pos, D2D1_POINT_2F Scale, D2D1_POINT_2F Rotate) {
		Objrect = { 0,0,0,0 };
		transforms = { Pos.x, Pos.y, Rotate.x, Rotate.y, Scale.x };
	}

	~Object() {	
		UnInitialize();
	}

	// ������Ʈ�� �׸��� �Լ� 
	void BeginDrawandClear(); 
	void Initialize(); 
	void DrawObject();
	void ObjectRender();
	void UnInitialize(); 

	void SetRenderTarget(ComPtr<ID2D1RenderTarget> target); 
	void SetObjPosition(float x, float y);
	void SetObjRotation(float rx); 
	void SetObjScale(float sx, float sy); 

};
