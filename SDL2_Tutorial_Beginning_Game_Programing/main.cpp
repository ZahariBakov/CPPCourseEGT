//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Key press surface constants
enum KeyPressSurface {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

// Load individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The surface contained by the window
SDL_Surface* gScreenSurface = nullptr;

// The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//The image we will load and show on the screen
SDL_Surface* gCurrentSurface = nullptr;

bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		//Create window
		gWindow = SDL_CreateWindow("Optimize loaded surfaces", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load default surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("./press.bmp");

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr) {
		printf("Failed to load default image!\n");
		success = false;
	}

	//Load up surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("./up.bmp");

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr) {
		printf("Failed to load up image!\n");
		success = false;
	}

	//Load down surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("./down.bmp");

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr) {
		printf("Failed to load down image!\n");
		success = false;
	}

	//Load left surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("./left.bmp");

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr) {
		printf("Failed to load left image!\n");
		success = false;
	}

	//Load right surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("./right.bmp");

	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr) {
		printf("Failed to load right image!\n");
		success = false;
	}

	return success;
}

void close() {
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i) {
		//Deallocate surface
		SDL_FreeSurface(gKeyPressSurfaces[i]);
		gKeyPressSurfaces[i] = nullptr;

		//Destroy window
		SDL_DestroyWindow(gWindow);
		gWindow = nullptr;

		//Quit SDL subsystems
		SDL_Quit();
	}

	
}

SDL_Surface* loadSurface(std::string path) {

	// The final optimized image
	SDL_Surface* optimizedSurface = nullptr;

	// Load image at specified path
	SDL_Surface* loadSurface = SDL_LoadBMP(path.c_str());

	if (loadSurface == nullptr) {
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		// Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadSurface, gScreenSurface->format, 0);

		if (optimizedSurface == nullptr) {
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadSurface);
	}

	return optimizedSurface;
}

int main(int argc, char* args[]) {

	//Start up SDL and create window
	if (!init()) {
		printf("Failed to initialize!\n");
	}
	else {

		//Load media
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		}
		else {
			// Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e; 

			// Set default current surface
			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
			 
			// While application is running
			while (!quit) { 

				// Handle events on queue
				while (SDL_PollEvent(&e) != 0) { 

					// User requests quit
					if (e.type == SDL_QUIT) {
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN) { // User presses a kay
						switch (e.key.keysym.sym) {
						case SDLK_UP:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
							break;
						case SDLK_DOWN:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
							break;
						case SDLK_LEFT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
							break;
						case SDLK_RIGHT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
							break;

						default:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
							break;
						}
					}
				}

				//Apply the current image
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = 0;
				stretchRect.h = 0;
				SDL_BlitSurface(gCurrentSurface, nullptr, gScreenSurface, &stretchRect);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
