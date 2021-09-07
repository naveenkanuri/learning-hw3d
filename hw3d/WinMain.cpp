#include "Window.h"
#include "WindowsMessageMap.h"
#include <sstream>

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd )
{
	try
	{
		Window wnd( 800, 300, "Honey Window!" );

		// message pump
		MSG msg;
		BOOL gResult;
		while( gResult = ( GetMessage( &msg, nullptr, 0, 0 ) ) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );

			//do app logic test
			while( !wnd.mouse.IsEmpty() )
			{
				const auto e = wnd.mouse.Read();
				switch( e.GetType() )
				{
				case Mouse::Event::Type::WheelUp:
				{
					std::ostringstream oss;
					oss << "Mouse Wheel Up: " << wnd.mouse.GetDelta();
					wnd.SetTitle( oss.str() );
				}
					break;
				case Mouse::Event::Type::WheelDown:
					{
						std::ostringstream oss;
						oss << "Mouse Wheel Down: " << wnd.mouse.GetDelta();
						wnd.SetTitle( oss.str() );
					}
					break;
				}
			}
		}

		if( gResult == -1 )
		{
			return -1;
		}

		return msg.wParam;
	}
	catch( const HoneyException& e )
	{
		MessageBox( nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION );
	}
	catch( const std::exception& e )
	{
		MessageBox( nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION );
	}
	catch( ... )
	{
		MessageBox( nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION );
	}
	return -1;
}