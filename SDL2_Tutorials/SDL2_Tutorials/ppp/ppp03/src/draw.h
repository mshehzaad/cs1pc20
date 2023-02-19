/*
 * Copyright (C) 2015-2018,2022 Parallel Realities. All rights reserved.
 */

void prepareScene(void);
void presentScene(void);
void blit(SDL_Texture *texture, int x, int y, int center);
void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
