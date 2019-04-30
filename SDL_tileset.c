#include "SDL_tileset.h"
 
Tileset* TILESET_Load(SDL_Renderer* renderer, const char* path, const Uint32 tileW, const Uint32 tileH)
{
	Tileset* tileset = malloc(sizeof(*tileset));
	SDL_Surface* tmp = NULL;

	if (tileset == NULL)
		return NULL;

	tmp = IMG_Load(path);

	if (tmp == NULL)
	{
		TILESET_Destroy(tileset, NULL);
		return NULL;
	}

	tileset->texture = SDL_CreateTextureFromSurface(renderer, tmp);

	if (tileset->texture == NULL)
	{
		SDL_FreeSurface(tmp);
		TILESET_Destroy(tileset, NULL);
		return NULL;
	}
	SDL_FreeSurface(tmp);
	
	tileset->tile_w = tileW;
	tileset->tile_h = tileH;
	SDL_QueryTexture(tileset->texture, NULL, NULL, &tileset->w, &tileset->h);
 
	return tileset;
}

void TILESET_Destroy(Tileset* tileset, SDL_Texture** texturesID)
{
	for (int i = 0; i < 0; i++)
	{
		if(texturesID[i] != NULL)
			SDL_DestroyTexture(texturesID[i]);
	}

	if (texturesID != NULL)
		free(texturesID);

	if (tileset->texture != NULL)
		SDL_DestroyTexture(tileset->texture);
	if (tileset != NULL)
		free(tileset);
}

SDL_Texture* TILESET_GetTileByID(SDL_Renderer* renderer, Tileset* tileset, Uint32 id)
{
	SDL_Texture* texture = NULL;
	SDL_Rect src = { 0, 0, tileset->tile_w, tileset->tile_h };
	Uint32 count_id = 1;

	for (Uint32 i = 0; i < (tileset->h / tileset->tile_h); i++)
	{
		for (Uint32 j = 0; j < (tileset->w / tileset->tile_w); j++)
		{
 
			if (count_id == id)
			{
				texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, tileset->tile_w, tileset->tile_h);
				if (texture == NULL)
					return  NULL;

				SDL_SetRenderTarget(renderer, texture);
				SDL_RenderCopy(renderer, tileset->texture, &src, NULL);
				SDL_SetRenderTarget(renderer, NULL);
				return texture;
			}
			src.x += tileset->tile_w;
			count_id++;

		}
		src.x = 0;
		src.y += tileset->tile_h;
	}
	return NULL;
}

SDL_Texture* TILESET_GetTileByRowColumn(SDL_Renderer* renderer, const Tileset* tileset, const Uint32 i, const Uint32 j)
{
	SDL_Texture* texture = NULL;
	SDL_Rect src = { j * tileset->tile_w, i * tileset->tile_h, tileset->tile_w, tileset->tile_h };

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, tileset->tile_w, tileset->tile_h);
	if (texture == NULL)
		return  NULL;

	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderCopy(renderer, tileset->texture, &src, NULL);
	SDL_SetRenderTarget(renderer, NULL);

	return texture;
}

SDL_Texture** TILESET_GetTextureID(SDL_Renderer* renderer, const Tileset* tileset)
{
	SDL_Texture** texturesID = malloc(sizeof(*texturesID) * tileset->w * tileset->h);

	for (int i = 0; i < tileset->tile_w * tileset->tile_h; i++)
	{
		texturesID[i] = TILESET_GetTileByID(renderer, tileset, i);
	}

	return texturesID;
}