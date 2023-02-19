/*
 * Copyright (C) 2015-2018,2022 Parallel Realities. All rights reserved.
 */

#include <SDL2/SDL_mixer.h>

#include "common.h"

#include "sound.h"

static void loadSounds(void);

static Mix_Chunk *sounds[SND_MAX];
static Mix_Music *music;

void initSounds(void)
{
	memset(sounds, 0, sizeof(Mix_Chunk *) * SND_MAX);

	music = NULL;

	loadSounds();
}

void loadMusic(char *filename)
{
	if (music != NULL)
	{
		Mix_HaltMusic();
		Mix_FreeMusic(music);
		music = NULL;
	}

	music = Mix_LoadMUS(filename);
}

void playMusic(int loop)
{
	Mix_PlayMusic(music, (loop) ? -1 : 0);
}

void playSound(int id, int channel)
{
	Mix_PlayChannel(channel, sounds[id], 0);
}

static void loadSounds(void)
{
	sounds[SND_JUMP] = Mix_LoadWAV("sound/331381__qubodup__public-domain-jump-sound.ogg");
	sounds[SND_PIZZA] = Mix_LoadWAV("sound/90134__pierrecartoons1979__found-item.ogg");
	sounds[SND_PIZZA_DONE] = Mix_LoadWAV("sound/449069__ricniclas__fanfare.ogg");
}
