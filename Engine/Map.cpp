#include "Map.h"

Map::Map(Location l, Graphics& gfxx) : gfx(gfxx)
{
	loc = l;
}

void Map::Insert(Location l, Color c) const
{
	gfx.DrawRectDim((l.x * dimension + loc.x) + dimBorderThickness, (l.y * dimension + loc.y) + dimBorderThickness, dimension - (2 * dimBorderThickness), dimension - (2 * dimBorderThickness), c);
}

const int Map::GetWidth() const
{
	return width;
}

const int Map::GetHeight() const
{
	return height;
}

void Map::DrawBorder() const
{
	gfx.DrawRectDim(loc.x - borderThickness, loc.y - borderThickness, (width*dimension) + 2 * borderThickness, borderThickness, borderColor); //Up Side
	gfx.DrawRectDim(loc.x - borderThickness, loc.y + (height*dimension), (width*dimension) + 2 * borderThickness, borderThickness, borderColor); //Down Side
	gfx.DrawRectDim(loc.x - borderThickness, loc.y, borderThickness, (height*dimension), borderColor); //Left Side
	gfx.DrawRectDim(loc.x + (width*dimension), loc.y, borderThickness, (height*dimension), borderColor); //Right Side
}
