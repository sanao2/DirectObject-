#include "pch.h"
#include "Application.h"
#include <exception>

bool isQuit = true;

void Application::Initialize()
{
	CoInitialize(nullptr);
	g_renderManager.Initialize();
 
}

void Application::Run()
{
   // �޽��� ����
   try {
       MSG msg = {};
       // �޽��� ����
       while (isQuit)
       {
           while (msg.message != WM_QUIT && PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
               if (msg.message == WM_QUIT) {
                   return;
               }
               TranslateMessage(&msg);
               DispatchMessage(&msg);
           }
           // ���� ȣ��

           Render();
       }
   }
   catch (const std::exception& e) {
       // std::exception �迭(��: std::runtime_error)�� throw�� ���� ���
       MessageBoxA(nullptr, e.what(), "���� �߻�", MB_OK | MB_ICONERROR);
   }
   catch (...) {
       // �� �� ��� ����(����, ���ڿ�, ����� ���� Ŭ���� ��) ���
       MessageBox(nullptr, L"�� �� ���� ���ܰ� �߻��߽��ϴ�.", L"���� �߻�", MB_OK | MB_ICONERROR);
   }
}

void Application::Render()
{	
	g_renderManager.Render(); // ������ �Ŵ����� ���� �޼��� ȣ��

}

void Application::Uninitialize()
{
	g_renderManager.Uninitialize();
   
    CoUninitialize();
}
