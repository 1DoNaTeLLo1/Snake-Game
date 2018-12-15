#pragma once

#include "Graphics.h"
#include "Colors.h"

struct Location
{
	int x;
	int y;

	bool operator==(const Location& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	void operator+=(const Location& rhs)
	{
		x += rhs.x;
		y += rhs.y;
	}
};

class Map
{
	Location loc;
	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int dimension = 20;
	static constexpr int borderThickness = 3;
	static constexpr int dimBorderThickness = 1;
	static constexpr Color borderColor = Colors::Blue;
	Graphics& gfx;

public:
	Map(Location l, Graphics& gfxx);
	void Insert(Location l, Color c) const;
	const int GetWidth() const;
	const int GetHeight() const;
	void DrawBorder() const;
};
