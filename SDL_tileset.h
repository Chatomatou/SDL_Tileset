#pragma once

/* Dépendance */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


typedef struct s_Tileset
{
	Uint32 w; /* Largeur de la tileset */
	Uint32 h; /* Hauteur de la tileset */
	Uint32 tile_w; /* Largeur d'une tile */
	Uint32 tile_h; /* Hauteur d'une tile */
	SDL_Texture* texture; /* La tileset */
}Tileset;

 

 
Tileset* TILESET_Load(SDL_Renderer* renderer, const char* path, const Uint32 tileW, const Uint32 tileH);
void TILESET_Destroy(Tileset* tileset, SDL_Texture** texturesID);
SDL_Texture* TILESET_GetTileByID(SDL_Renderer* renderer, Tileset* tileset, Uint32 id);
SDL_Texture* TILESET_GetTileByRowColumn(SDL_Renderer* renderer, const Tileset* tileset, const Uint32 i, const Uint32 j);
SDL_Texture** TILESET_GetTextureID(SDL_Renderer* renderer, const Tileset* tileset);