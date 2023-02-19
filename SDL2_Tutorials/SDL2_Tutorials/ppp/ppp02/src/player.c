/*
 * Copyright (C) 2015-2018,2022 Parallel Realities. All rights reserved.
 */

#include "common.h"

#include "player.h"

extern App   app;
extern Stage stage;

void doPlayer(void)
{
	if (app.keyboard[SDL_SCANCODE_A])
	{
		stage.camera.x -= PLAYER_MOVE_SPEED;
	}

	if (app.keyboard[SDL_SCANCODE_D])
	{
		stage.camera.x += PLAYER_MOVE_SPEED;
	}

	if (app.keyboard[SDL_SCANCODE_W])
	{
		stage.camera.y -= PLAYER_MOVE_SPEED;
	}

	if (app.keyboard[SDL_SCANCODE_S])
	{
		stage.camera.y += PLAYER_MOVE_SPEED;
	}
}
