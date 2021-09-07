#include "Mouse.h"
#include <Windows.h>

std::pair<int, int> Mouse::GetPos() const
{
	return { x,y };
}

int Mouse::GetPosX() const
{
	return x;
}

int Mouse::GetPosY() const
{
	return y;
}

bool Mouse::LeftIsPressed() const
{
	return leftIsPressed;
}

bool Mouse::RightIsPressed() const
{
	return rightIsPressed;
}

bool Mouse::IsInWindow() const
{
	return isInWindow;
}

Mouse::Event Mouse::Read()
{
	if( !buffer.empty() )
	{
		Mouse::Event e = buffer.front();
		buffer.pop();
		return e;
	}
	return Mouse::Event();
}

void Mouse::Flush()
{
	buffer = std::queue<Event>();
}

void Mouse::OnMouseLeave()
{
	isInWindow = false;
	buffer.push( Mouse::Event( Mouse::Event::Type::Leave, *this ) );
	TrimBuffer();
}

void Mouse::OnMouseEnter()
{
	isInWindow = true;
	buffer.push( Mouse::Event( Mouse::Event::Type::Enter, *this ) );
	TrimBuffer();
}

void Mouse::OnMouseMove( int newx, int newy )
{
	x = newx;
	y = newy;

	buffer.push( Mouse::Event( Mouse::Event::Type::Move, *this ) );
	TrimBuffer();
}

void Mouse::OnLeftPressed( int x, int y )
{
	leftIsPressed = true;

	buffer.push( Mouse::Event( Mouse::Event::Type::LPress, *this ) );
	TrimBuffer();
}

void Mouse::OnLeftReleased( int x, int y )
{
	leftIsPressed = false;

	buffer.push( Mouse::Event( Mouse::Event::Type::LRelease, *this ) );
	TrimBuffer();
}

void Mouse::OnRightPressed( int x, int y )
{
	rightIsPressed = true;

	buffer.push( Mouse::Event( Mouse::Event::Type::RPress, *this ) );
	TrimBuffer();
}

void Mouse::OnRightReleased( int x, int y )
{
	rightIsPressed = false;

	buffer.push( Mouse::Event( Mouse::Event::Type::RRelease, *this ) );
	TrimBuffer();
}

void Mouse::OnWheelUp( int x, int y )
{
	buffer.push( Mouse::Event( Mouse::Event::Type::WheelUp, *this ) );
	TrimBuffer();
}

void Mouse::OnWheelDown( int x, int y )
{
	buffer.push( Mouse::Event( Mouse::Event::Type::WheelDown, *this ) );
	TrimBuffer();
}

void Mouse::TrimBuffer()
{
	while( buffer.size() > bufferSize )
	{
		buffer.pop();
	}
}

void Mouse::OnWheelDelta( int x, int y, int delta ) noexcept
{
	wheelDeltaCarry += delta;
	//generate events for every 120
	while( wheelDeltaCarry >= WHEEL_DELTA )
	{
		wheelDeltaCarry -= WHEEL_DELTA;
		OnWheelUp( x, y );
	}
	while( wheelDeltaCarry <= -WHEEL_DELTA )
	{
		wheelDeltaCarry += WHEEL_DELTA;
		OnWheelDown( x, y );
	}
}

int Mouse::GetDelta() const noexcept
{
	return wheelDeltaCarry;
}
