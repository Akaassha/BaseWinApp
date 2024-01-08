#include "WinApp.h"

static HWND WindowHandle;
static WNDCLASS WindowClass;
static HINSTANCE WindowInstance;
const LPCWSTR WIN_CLASS_NAME = TEXT("WIN_CLASS");
const LPCWSTR APP_TITLE = TEXT("APP_TITLE");
const DWORD WINDOWED_STYLE = WS_POPUP | WS_CAPTION;

WinApp::WinApp(HINSTANCE instance)
{
	WindowInstance = instance;

	make_window_class(WindowClass);
	RegisterClass(&WindowClass);
	make_handle_to_window(WindowHandle);

	ShowWindow(WindowHandle, SW_SHOWNORMAL);
}

void WinApp::make_window_class(WNDCLASS& winClass)
{
	winClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;
	winClass.hInstance = WindowInstance;
	winClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winClass.lpszMenuName = NULL;
	winClass.lpszClassName = WIN_CLASS_NAME;
	winClass.lpfnWndProc = &WinProc;
}

void WinApp::make_handle_to_window(HWND& HanleToWindow)
{
	HanleToWindow = CreateWindow(
		WIN_CLASS_NAME,             /*Class name*/
		APP_TITLE,       /*Window Title*/
		WINDOWED_STYLE,                /*Window Style*/
		0,                 /*X Starting pos*/
		0,                 /*Y Starting Pos*/
		600,				/*Width*/
		400,				/*Height*/
		0,                      /*Parent Window*/
		0,                      /*Menu*/
		WindowInstance,    /*HInstance*/
		0                       /*Lparam This will be available in WM_CREATE*/
	);
}

void WinApp::Run()
{
	while(true)
	{
		ProcessMessages();
	}
}

void WinApp::ProcessMessages(void)
{
	MSG msg;
	while (PeekMessage(&msg, WindowHandle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK WinApp::WinProc(HWND win, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    default:
        return DefWindowProc(win, msg, wp, lp);
    }

    return 0;
}

