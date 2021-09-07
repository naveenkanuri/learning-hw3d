#include "Window.h"
#include "WindowsMessageMap.h"
#include <sstream>

/*
// our custom WindowProcedure to handle windows' messages
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	static WindowsMessageMap wmm;
	OutputDebugString( wmm( msg, wParam, lParam ).c_str() );
	switch( msg )
	{
	case WM_CLOSE:
		PostQuitMessage( 69 );
		break;
	case WM_KEYDOWN:
		if( wParam == 'F' )
		{
			SetWindowText( hWnd, L"Hi Honey" );
		}
		else if( wParam = VK_ESCAPE ) // close on clicking Escape key
		{
			PostQuitMessage( 99 );
		}
		break;
	case WM_KEYUP:
		if( wParam == 'F' )
		{
			SetWindowText( hWnd, L"How are you" );
		}
		break;
	case WM_CHAR:
		{
			static std::wstring title;
			title.push_back( ( char ) wParam );
			SetWindowText( hWnd, title.c_str() );
		}
		break;
	case WM_LBUTTONDOWN:
		{
			const POINTS pt = MAKEPOINTS( lParam );
			std::wostringstream woss;
			woss << "(" << pt.x << "," << pt.y << ")";
			SetWindowText( hWnd, woss.str().c_str( ) );
		}
		break;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam );
}
*/
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd )
{
	Window wnd( 800, 300, L"Honey Window!" );

	// message pump
	MSG msg;
	BOOL gResult;
	while( gResult = ( GetMessage( &msg, nullptr, 0, 0 ) ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	if( gResult == -1 )
	{
		return -1;
	}
	
	return msg.wParam;
}