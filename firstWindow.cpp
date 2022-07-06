#include<Windows.h>

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCSTR Name, WNDPROC Procedure); // WNDPROC it's callback from window(permanent)


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, 
		                                       LoadIcon(NULL, IDI_QUESTION), "MainWndClass", SoftwareMainProcedure);
	MSG SoftwareMainMessage = { 0 };

	if (!RegisterClass(&SoftwareMainClass))
		return -1;
	
	CreateWindow("MainWndClass", "First c++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL);

	while (GetMessage(&SoftwareMainMessage,NULL, NULL, NULL))// LPMSG(it's where the information is retrieved from window)
		                                                     // HWND hWnd(handle of certain window(if NULL then information retrieved from the current queue)
                                                             // UINT UINT information of window(not interesting for us)
	{
	TranslateMessage(&SoftwareMainMessage);//(it's used to get information from user to window)
	DispatchMessage(&SoftwareMainMessage); //                                                                          
    }
	return 0;
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCSTR Name, WNDPROC Procedure)
{
	WNDCLASS NWC = { 0 };

	NWC.hbrBackground = BGColor;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.hIcon = Icon;
	NWC.lpszClassName = Name;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE: break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hWnd, msg, wp, lp);
    }
}