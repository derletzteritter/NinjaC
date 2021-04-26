#include <windows.h>
#include <tchar.h>
#include <string.h>
#include <stdlib.h>

// The main window class name.
static TCHAR szWindowClass[] = _T("NinjaC");


static TCHAR szTitle[] = _T("Face dec eh...like this will ever be done");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("NinjaC"),
			NULL);
		return 1;
	}

	HWND hWnd = CreateWindow(
		szWindowClass, 
		szTitle, 
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		500, 500, 
		NULL, NULL, 
		hInstance, 
		NULL
	);

	if (!hWnd) {
		MessageBox(
			NULL,
			_T("Call to CreateWindow failed!"),
			_T("NinjaC"),
			NULL
		);

		return 1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	// Yes, this is a really dumb name!
	TCHAR hTitle[] = _T("Ninja Detection...what a stupid name");

	switch (message) {
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		TextOut(hdc, 5, 5, hTitle, _tcsclen(hTitle));

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

