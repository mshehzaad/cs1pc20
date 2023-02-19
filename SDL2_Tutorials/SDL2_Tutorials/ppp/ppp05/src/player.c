/*
 * Copyright (C) 2015-2018,2022 Parallel Realities. All rights reserved.
 */

#include "common.h"

#include "player.h"
#include "textures.h"

extern App     app;
extern Entity *player;
extern Stage   stage;

static SDL_Texture *pete[2];

void initPlayer(void)
{
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.entityTail->next = player;
	stage.entityTail = player;

	pete[0] = loadTexture("gfx/pete01.png");
	pete[1] = loadTexture("gfx/pete02.png");

	player->texture = pete[0];

	SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
}

void doPlayer(void)
{
	player->dx = 0;

	if (app.keyboard[SDL_SCANCODE_A])
	{
		player->dx = -PLAYER_MOVE_SPEED;

		player->texture = pete[1];
	}

	if (app.keyboard[SDL_SCANCODE_D])
	{
		player->dx = PLAYER_MOVE_SPEED;

		player->texture = pete[0];
	}

	if (app.keyboard[SDL_SCANCODE_I] && player->isOnGround)
	{
		player->riding = NULL;

		player->dy = -20;
	}

	if (app.keyboard[SDL_SCANCODE_SPACE])
	{
		player->x = player->y = 0;

		app.keyboard[SDL_SCANCODE_SPACE] = 0;
	}
}
