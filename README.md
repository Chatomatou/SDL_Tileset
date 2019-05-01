# SDL_Tileset

[![N|SDL2.0](https://image.noelshack.com/fichiers/2019/18/2/1556621548-sdl-logo-svg.png)](https://github.com/GuerrierNumerique/SDL_Tileset)

Bonjour, je suis @GuerrierNumérique#2513  et je vous présente aujourd'hui une bibliothèque SDL que j'ai nommer SDL_Tileset qui vous permettra de gérer vos tilemap en SDL 2.0. 

# Quesqu'une tilemap ? 

Une tilemap est un tableau a 2 dimension qui est censé representer votre monde 2D (le décore, l'emplacement d'un arbre). 

# Tileset ?

une Tileset est une image qui representes chaque élement de votre décore placer côte à côte ligne par ligne colone par colone.

Comme ceci : https://i.stack.imgur.com/5z1KX.png

# Comment faire vos tile map 

Il existe plusieurs solution ce que je connait c'est la méthode **BUCHERON** de l'extrème et la méthode **PRO** de l'extrème inteligent.

 - La méthode **BUCHERON** consiste a faire votre tilemap a la main, et avoir chaque tuile en une seule image (PNG, BMP, etc...) et donc votre répertoire ce trouve avec 36 images pour vos 36 décore dans votre monde 2D, et vous vous retrouver avec un code qui IMG_Load ou SDL_LoadBMP 36 fois et avec un SDL_CreateTexture 36 fois si vous êtes des nul soit vous utiliser un tableau qui contiendra 36 chaine de caractère qui contient repertorie vos image et vous faite un tableau de SDL_Texture* et puis ensuite vous devez savoir a quel valeur de tilemap sa represente quel SDL_Texture* donc vous êtes dans la merde... car c'est du code a répétition... Vous êtes partie en syrie dans le cas ou vous êtes...
 - La méthode **PRO** Premièrement vous utilisez tiled pour construire votre tableau 2D qui représente votre monde, puis vous utilisez une tileset qui contiendra tout vous texture qui seront utilisez dans votre monde et vous n'avez qu'une SDL_Texture* a charger mais par contre ! vous devez vous faire chier a vous décalerer de la largeur des tuiles et de la hauteur et aussi gerer par un ID qu'elle texture vous allez charger.
 - La méthode **PRO (féneant)** vous vous faites une bibliothèque ou vous utilisez SDL_Tileset :) !
 
Pourquoi la troisème méthode est la meilleur !? car parce qu'un développeur est féneant et c'est la régle d'or !
 
 # Je veux devenir un pro (féneant) des tilemap

Premièrement je t'invite a construire ton décore 2D via a tiled (https://www.mapeditor.org/)
Deuxièmement utilise ma bibliothèque SDL_Tileset et secondement regarde cette vidéo ! je montre comment l'utilisez avec un example : https://www.youtube.com/watch?v=fKTigZPoK78

Obtenir ma bibliothèque SDL_Tileset : 

```sh
git clone https://github.com/GuerrierNumerique/SDL_Tileset.git
```


Bibliothèque permetant de gérérer des tileset, se basant sur SDL.

| Dependence | URL |
| ------ | ------ |
| SDL 2.0 | https://www.libsdl.org/ |
| SDL_image 2.0  |  https://www.libsdl.org/projects/SDL_image/ |

### Tiled Editeur de tilemap 
https://www.mapeditor.org/


### Explication Vidéo
[![Explication vidéo](https://image.noelshack.com/fichiers/2019/18/2/1556622155-youtube-circle.png)](https://www.youtube.com/watch?v=fKTigZPoK78)
 
Vidéo de 14 minutes environ pour vous expliquez sont fonctionnement ! 
