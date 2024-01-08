#include "WinApp.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	WinApp app(instance);
	app.Run();


}