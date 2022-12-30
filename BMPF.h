#include <SDL2/SDL.h>

void BMPF_initalise(SDL_Texture* font);
void BMPF_kill();
void BMPF_setColorFromSDL(SDL_Color* color);
void BMPF_setColor(Uint32 color, Uint32 unused); /* Color must be in 0x00RRGGBB format! */
void BMPF_print(SDL_Renderer* dst, const char* str, Uint32 x, Uint32 y, bool alignCenter = false);
