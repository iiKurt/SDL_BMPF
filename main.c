#include <SDL2/SDL.h>

#include "BMPF.h"

int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	Uint32 width = 424;
	Uint32 height = 480;
	Uint32 flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Video initialization failed: %s\n", SDL_GetError());
		exit(-1);
	}

	// Create window
	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags );
	if( window == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		exit(-1);
	}
	else
	{
		// Create renderer for window
		renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
		if( renderer == NULL )
		{
			printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
			exit(-1);
		}
		else
		{
			// Initialize renderer color
			SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		}
	}

	SDL_Surface* bmpSurface = SDL_LoadBMP("fonts/zap-light16.bmp");
	
	SDL_Texture* bmpTexture = SDL_CreateTextureFromSurface(renderer, bmpSurface);
	BMPF_initalise(bmpTexture); // Use bitmap font
	
	SDL_FreeSurface(bmpSurface);

	// Clear screen
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
	SDL_RenderClear(renderer);
	
	// Main loop flag
	bool quit = false;

	// Event handler
	SDL_Event e;

	// While application is running
	while( !quit )
	{
		// Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			// User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}
		
		// Clear screen
		SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( renderer );
		
		// Make color red and print some lines
		//BMPF_setColor(0xFF0000, 0);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		BMPF_print(renderer, "The quick brown fox jumps over the lazyy dog. The quick brown fox jumpss over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick I\nO !brownnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn0123456789nnnnnnnn fox juP\nQmps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog...\n.1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456\nThe quick brown fox jumps over the lazy dog. The quick brown fox jumps over the AA", 400, 90, true);
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderDrawLine(renderer, width / 2, 0, width / 2, height);
		SDL_RenderDrawLine(renderer, 400, 0, 400, height);

		// Update screen
		SDL_RenderPresent(renderer);
	}

	// Cleanup
	BMPF_kill();
	SDL_Quit();
	return 0;
}
