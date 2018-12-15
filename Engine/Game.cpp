/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	map({ 50,50 }, gfx),
	snake({ 1,1 }, Snake::right),
	rnd(rd()),
	xDist(0, map.GetWidth() - 1),
	yDist(0, map.GetHeight() - 1),
	timer(20),
	stones({xDist(rnd),yDist(rnd)})
{
	bait.Respawn(rnd, xDist, yDist);
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			snake.SetDirection(Snake::right);
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			snake.SetDirection(Snake::left);
		}
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			snake.SetDirection(Snake::up);
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			snake.SetDirection(Snake::down);
		}
		if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
		{
			exit(0);
		}

		const float dt = frametimer.Mark();

		if (timer >= maxTimer)
		{
			snake.Update();

			if (snake.TailCollusion() || snake.BorderTest(map) || stones.CollusionTest(snake.GetLocation(0)))
			{
				gameOver = true;
			}

			if (snake.IsEat(bait))
			{
				snake.Grow();
				bait.Respawn(rnd, xDist, yDist);
				eatenBait++;
				stones.Increase({ xDist(rnd),yDist(rnd) });

				if (maxTimer != minTimer)
				{
					if (!(eatenBait % 5))
					{
						maxTimer = std::max(maxTimer - 0.05f, minTimer);
					}
				}
			}

			timer = dt - maxTimer;
		}

		timer+=dt;
	}
}

void Game::ComposeFrame()
{
	map.DrawBorder();

	snake.Draw(map);
	bait.Draw(map);
	stones.Draw(map);

	if (gameOver)
	{
		SpriteCodex::DrawGameOver(350, 280, gfx);
	}
}
